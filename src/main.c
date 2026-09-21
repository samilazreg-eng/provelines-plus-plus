#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "error.h"
#include "main.h"
#include "list.h"
#include "stack.h"
#include "hashtableGen.h"
#include "boolFct.h"
#include "ltl.h"
#include "tvl.h"
#include "symbols.h"
#include "costFormula.h"
#include "automata.h"
#include "fdg.h"
#include "state.h"
#include "execution.h"
#include "checking.h"
#include "y.tab.h"
#include "lexer.h"

extern FILE* yyin;
extern int yyparse();
extern void init_lex();

// Settings defined in main
char * path;
byte trace = FULL_TRACE;
byte keepTempFiles = 0;
byte spinMode = 0;
byte optimisedSpinMode = 0;
byte exhaustive = 0;
byte fullDeadlockCheck = 0;
byte sim = 0;
byte stutterStep = 0;
byte bfs = 0;
byte optim = 0;
int sampling = 0;
byte prior = 0;
long int limitExploration;

// Other global variables from main
ptSymTabNode globalSymTab = NULL;
ptSymTabNode globalSymTab2 = NULL;
ptMTypeNode mtypes = NULL;
ptMTypeNode mtypes2 = NULL;
ptSymTabNode neverClaim;
ptList props, props2;
void * _handshake_transit = NULL;
ptCostFormula costFormula = NULL;

// Profiler variables
struct timeval _profileTimeBegin, _profileTimeEnd;
char* _profilerStr = NULL;


/**
 * To be used for command-line parameter errors.  Does the
 * same as failure(), and prints the usage instructions.
 */
void error(char* msg, ...) {
	printf("Error: ");
	va_list args;
	va_start(args, msg);
	vfprintf(stdout, msg, args);
	va_end(args);
	printf(	"\n --\n"
			"Usage: ./provelines [options] model.pml\n"
			"\n"
			" Options for model checking:\n"
			"  (none)   Does nothing.\n"
			"  -check   Verifies the model.  When a problem (assert, deadlock or pro-\n"
			"           perty violation) is found, an error trace (counterexample) is\n"
			"           printed and execution stops. \n"
			"  -exhaustive \n"
			"           Determines also which products have *no* problems. The normal\n"
			"           check will stop at the first problem,  and does not determine\n"
			"           whether there are products that have no problems  (e.g. those\n"
			"           that satisfy a property).\n"
			"  -bfs \n"
			"           Performs a breadth-first search instead of a depth-first search.\n"
           "  -fdlc     Search for trivially invalid end states (more costly).\n"
           "  -optim    Search for optimal executions only.\n"
           "  -sampling    Search for optimal executions by sampling.\n"
           "  -prior    Prioritize transitions with lesser cost.\n");
	printf( "  -ltl <property> \n"
			"           Checks whether the specified property is satisfied (when used\n"
			"           with -check). Never claims can be specified manually, too.\n");
	printf(	"\n"
			" Options for output control:\n"
			"  (none)   Prints a full trace for every counterexample.\n"
			"  -st      Only prints states when there are no changed variables.\n"
			"  -nt      Does not print any traces, only information  about  violating\n"
			"           (or satisfying) products.\n"
			"\n"
			" Options for features and feature model:\n"
			"  (none)   Will attempt to load a TVL feature model that is named as the\n"
			"           .pml file but with extension .tvl\n"
			"  -fm <file.tvl> \n"
			"           Load the specified TVL file (only used in verification). This\n"
			"           parameter can be omitted if the TVL file is named as the .pml\n"
			"           file but with extension .tvl.\n"
			"  -fmdimacs <dimacsClauseFile.txt> <mappingFile.txt>\n"
			"           As before, but load the dimacs of the feature model directly.\n"
			"  -filter <expression> \n"
			"           Limit the verification to a subset of the products  specified\n"
			"           in the TVL file.  The TVL syntax has to be used for this.\n"
			"  -spin    Treat features like normal variables (as SPIN would do).\n"
			"  -ospin   Similar to -spin, but statements with a bad guard are removed\n"
			"           from the  model before model checking.  The input is thus in-\n"
			"           terpreted as fPromela (not exactly as SPIN would do). This is\n"
			"           normally more efficient than -spin.\n"
			"\n"
			" Options for debugging:\n"
			"  -exec    Execute the model (does not print states, only model output).\n"
			"  -l <integer> \n"
			"           Stop when the given number of states were explored. (This op-\n"
			"           tion can also be used for model checking.)\n"
			"  -s       Parse and print static info (symbol table, FSMs, MTypes, ..).\n"
			"  -t       Do not delete the generated temporary files.\n"
			"\n"
			" --\n");
	exit(EXIT_ERROR);
}

/**
 * Simply copies a file byte by byte; could be made more efficient.
 */
int copyFile(char* source, char* target) {
	FILE* fsource;
	FILE* ftarget;
	fsource = fopen(source, "r");
	ftarget = fopen(target, "w");

	if(fsource != NULL && ftarget != NULL)  {
		char buffer;
		buffer = fgetc(fsource);
		while(!feof(fsource)) {
			fputc(buffer, ftarget);
			buffer = fgetc(fsource);
		}
		fclose(fsource);
		fclose(ftarget);
		return 1;
	}

	if(fsource != NULL) fclose(fsource);
	if(ftarget != NULL) fclose(ftarget);
	return 0;
}

int main(int argc, char *argv[]) {
	if(sizeof(int) != 4)	failure("Bad architecture: int type must be four bytes long.\n");
	if(sizeof(short) != 2)	failure("Bad architecture: short type must be two bytes long.\n");
	char* ltlProp = NULL;
	char* tvlFile = NULL;
	char* tvlFilter = NULL;
	char* pmlFile = NULL;
	char * propFile = NULL;
	int i, ps = 0, check = 0, exec = 0, fm = 0, ltl = 0;

	path = (char *)malloc((strlen(argv[0]) - 9) * sizeof(char));
	for(i = 0; i < strlen(argv[0]) - 10; i++)
		path[i] = argv[0][i];
	path[strlen(argv[0]) - 10] = '\0';
	initBoolFct();

	if(argc < 2) error("No fPromela file provided.");

	if(!copyFile(argv[argc - 1], "__workingfile.tmp")) error("The fPromela file does not exist or is not readable!");

	// Read command-line arguments
	for(i = 1; i < argc-1; i++) {
		if(strcmp(argv[i],"-s") == 0) {
			ps = 1;

		} else if(strcmp(argv[i],"-check") == 0) {
			check = 1;

		} else if(strcmp(argv[i],"-exhaustive") == 0) {
			exhaustive = 1;

		} else if(strcmp(argv[i],"-bfs") == 0) {
			bfs = 1;

		} else if(strcmp(argv[i],"-t") == 0) {
			keepTempFiles = 1;

		} else if(strcmp(argv[i],"-spin") == 0) {
			if(optimisedSpinMode) error("The options -spin and -ospin cannot be used together.");
			spinMode = 1;

		} else if(strcmp(argv[i],"-ospin") == 0) {
			if(spinMode) error("The options -spin and -ospin cannot be used together.");
			optimisedSpinMode = 1;

        } else if(strcmp(argv[i],"-fdlc") == 0) {
            fullDeadlockCheck = 1;
            
        } else if(strcmp(argv[i],"-optim") == 0) {
            optim = 1;
            
        } else if(strcmp(argv[i],"-sampling") == 0) {
            i++;
            if (i >= argc - 1) error("The -sampling option has to be followed by an integer denoting the number of executions to sample.");
            else sampling = atoi(argv[i]);
            if (sampling < 1) error("In -sampling mode, the number of executions to sample must be greater than zero.");
            
        } else if(strcmp(argv[i],"-prior") == 0) {
            prior = 1;
            
        } else if(strcmp(argv[i],"-exec") == 0) {
			exec = 1;

		} else if(strcmp(argv[i],"-l") == 0) {
			i++;
			if(i >= argc - 1) error("The -l option has to be followed by an integer denoting the number of steps to execute.");
			else limitExploration = atol(argv[i]);

		} else if(strcmp(argv[i],"-filter") == 0) {
			i++;
			if(i >= argc - 1) error("The -filter option has to be followed by a TVL expression.");
			else tvlFilter = argv[i];

		} else if(strcmp(argv[i],"-fm") == 0) {
			if(fm) error("The options -fm and -fmdimacs cannot be used at the same time.");
			fm = 1;
			i++;
			if(i >= argc - 1) error("The -fm option has to be followed by the feature model file name.");
			else tvlFile = argv[i];

		} else if(strcmp(argv[i],"-fmdimacs") == 0) {
			if(fm) error("The options -fm and -fmdimacs cannot be used at the same time.");
			fm = 1;
			if(i+2 >= argc - 1) error("The -fmdimacs option has to be followed by the dimacs clause file and the dimacs mapping file.");
			else loadFeatureModelDimacs(argv[i+1], argv[i+2]);
			i += 2;

		} else if(strcmp(argv[i],"-nt") == 0) {
			trace = NO_TRACE;

		} else if(strcmp(argv[i],"-st") == 0) {
			if(trace != NO_TRACE) trace = SIMPLE_TRACE;
#ifndef CLOCK
		} else if(strcmp(argv[i],"-ltl") == 0) {
			ltl = 1;
			i++;
			if(i >= argc - 1) error("The -ltl option has to be followed by an LTL property.");
			else {
				ltlProp = argv[i];
				char* errorMsg = malloc(1024 * sizeof(char));
				if(!errorMsg) failure("Out of memory (creating string buffer).\n");
				if(!appendClaim("__workingfile.tmp", ltlProp, errorMsg)) error("The LTL formula '%s' could not be parsed, error message: \n --\n%s\n", ltlProp, errorMsg);
				free(errorMsg);
			}

		} else if(strcmp(argv[i], "-sim") == 0) {
			if(check) error("The options -check and -sim cannot be used at the same time.");
			sim = 1;
			i++;
			pmlFile = argv[i];
		} else if(strcmp(argv[i], "-props") == 0) {
			i++;
			propFile = argv[i];
		} else if(strcmp(argv[i], "-stutter") == 0) {
			stutterStep = 1;
#endif
		} else {
			error("Unrecognised option '%s'", argv[i]);
		}
	}

	// Some basic validity checks

	if(fm && tvlFile == NULL && tvlFilter != NULL) error("The -filter option cannot be used with the -fmdimacs option, only with -fm.");
	if(fm && tvlFile != NULL) {
		if(!loadFeatureModel(tvlFile, tvlFilter)) error("Could not load the specified feature model file.");
	} else if(!fm && !spinMode && !optimisedSpinMode) {
		// Try to guess name of feature model file name
		char * pmlFile = argv[argc - 1];
		int pmlFileLen = strlen(pmlFile);
		tvlFile = (char *) malloc((pmlFileLen +1) * sizeof(char));
		strcpy(tvlFile, pmlFile);
		tvlFile[pmlFileLen - 3] = 't';
		tvlFile[pmlFileLen - 2] = 'v';
		tvlFile[pmlFileLen - 1] = 'l';
		tvlFile[pmlFileLen] = '\0';
		if(!loadFeatureModel(tvlFile, tvlFilter) && tvlFilter != NULL) error("The -filter option can only be used when a feature model is charged.");
	} else {
		if(!fm && (spinMode || optimisedSpinMode) && tvlFilter != NULL) error("The -filter option can only be used when a feature model is charged.");
	}

	if(!propFile && (sim || stutterStep)) {
		error("Simulation checking and non stutter steps require a property file.");
	}

	// Initialise random number generator
	SelectStream(RNG_STREAM);
	PutSeed(RNG_SEED);

	// Invoke cpp
	if(system("cpp __workingfile.tmp __workingfile.tmp.cpp") != 0) failure("Could not run the c preprocessor (cpp).\n");

	yyin = fopen("__workingfile.tmp.cpp", "r");
	if(yyin == NULL) failure("Could not open temporary working file (%s).\n", argv[argc - 1]);
	init_lex();

	if(yyparse(&globalSymTab, &mtypes, &costFormula) != 0) printf("Syntax error; aborting..\n");
	else {
#ifdef DEBUG
		printf("Parsed.\n");
#endif
        if (costFormula) {
            printf("time = %d\n",costFormula->within);
        }
		// Resolve variable names
        processVariables(globalSymTab, globalSymTab, mtypes, SYS_VARS_SIZE, 1);
        if (costFormula && costFormula->property) {
            resolveVariableNamesInExpression(costFormula->property, globalSymTab, mtypes, NULL, NULL);
            printf("Property expression resolved\n");
            //printExpression(costFormula->property);
            
        }
#ifdef DEBUG
		printf("Processed variables.\n");
#endif
		// Treat user request
		if(ps) {
			printSymTab(globalSymTab, 0, "Global");
			printMTypes(mtypes);
		}
		if(check) {
			/*if(propFile) {
				fclose(yyin);
				yyin = fopen(propFile, "r");
				if(yyin == NULL) failure("Could not open temporary working file.", argv[argc - 1]);
				if(yyparse(&globalSymTab, &mtypes, &props) != 0) failure("Syntax error in property file; aborting..\n");
			}*/
			if(check && (ltl || neverClaim)) {
				if(ltl) printf("Checking LTL property %s..\n", ltlProp);
				else printf("Checking never claim contained in input file..\n");
				if(tvlFilter) printf("Attention! Checks are only done for products satisfying:\n  %s!\n", tvlFilter);
				startNestedDFS(globalSymTab, mtypes);
			} else {
				printf("No never claim, checking only asserts and deadlocks..\n");
				if(tvlFilter) printf("Attention! Checks are only done for products satisfying:\n  %s!\n", tvlFilter);
				if(bfs)
					startExplorationBFS(globalSymTab, mtypes);
                else {
                    if(sampling > 0) {
                        startSamplingExploration(sampling, globalSymTab, mtypes, costFormula);
                    } else {
                        startExploration(globalSymTab, mtypes, costFormula);
                    }
                }
			}
		} else if(exec) {
			launchExecution();
		}

		if(!ps && !check && !exec && !sim) {
			error("No action specified in command-line.");
		}

	}

	if(yyin != NULL) fclose(yyin);
	if(!keepTempFiles) {
		remove("__workingfile.tmp");
		remove("__workingfile.tmp.cpp");
	}


	exit(EXIT_NO_VERIFICATION);
}
