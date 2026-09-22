#include "configure.h"
//#define DEBUG
//#define DEBUGEXEC

#define TEST

#define true 1
#define false 0

// Possible exit values:
#define EXIT_SUCCESS 0						// Verification task launched and completed without finding a problem
#define EXIT_ERROR 1						// Verification task NOT LAUNCHED because of a problem
#define EXIT_NO_VERIFICATION 2				// Verification task NOT LAUNCHED because not asked to (only parameter -s, for instance)
#define EXIT_FOUND_PROBLEM 3				// Verification task launched and problem found
#define EXIT_REACHED_EXPLORATION_LIMIT 4	// Verification task launched, no problem found, but ended prematurely due to exploration limit

// This controls the number of blanks in a "tab" when printing symbol tables and FSMs
#define LEVEL_STEP 10

// Seed for PRNG
#define RNG_SEED 1337
#define RNG_STREAM 42

// The maximum number of labels per statement is fixed statically:
#define NBLABELS 2

// Bytes needed to record the system variables: exclusive and handshake.
#define SYS_VARS_SIZE 5 + sizeof(void *)
#define OFFSET_EXCLUSIVE 0 // T_BYTE
#define OFFSET_HANDSHAKE 1 // T_INT
#define OFFSET_NEVERNODE 5

// For any channel, its offset is positive. Thus, we use the value -1 to specify the absence of rendezvous request.
#define NO_HANDSHAKE 0

// For any process, its pid is between 0 and 254. Thus, we use the value 255 to specify absence of a process
#define NO_PROCESS 255 // T_BYTE
#define MAX_PROCESS 254 // T_BYTE

// Modulo for hashtable functions
#define HASHTABLE_MODULO 2027

// Size of listHashtable
#define HASHTABLE_SIZE 4054

// Number of calls to the SAT solver before reinitialize it.
#define SAT_REINITIALISE 100000

// During model-checking: number of states to explore before a message appears.
#define PRINT_EXPLORED_STEP 1048576 // 65536 // 4056

typedef unsigned char byte;

// Output control
#define NO_TRACE 0		// No traces are printed at all.
#define SIMPLE_TRACE 1	// States are not printed when there are no changed variables.
#define FULL_TRACE 2	// All states are printed (each time the differences only).

// Path to the currently used Snip executable.
extern char * path;

// Global variables (declared in main)
extern byte keepTempFiles;
extern byte spinMode;
extern byte optimisedSpinMode;
extern byte exhaustive;
extern byte fullDeadlockCheck;
extern byte trace;
extern byte stutterStep;
extern byte sim;
extern byte optim;
extern int sampling;
extern byte prior;
extern long int limitExploration;
extern struct symTabNode_* neverClaim;
extern void * _handshake_transit;

// Parameter: check tautology of each feature expression
// #define CHECK_TAUTOLOGY

// With this macro, a minor optimisation is activated: before conjuncting a clause
// with a CNF, it checks whether the same clause already exists (approximately)
// by iterating through existing clauses and comparing them with the new one.  For
// the comparison, a maximum of CNF_OPTIM_LIMIT literals will be considered (clauses
// with more are considered different).
#define CNF_OPTIM
#define CNF_OPTIM_LIMIT 6

//#define PROFILER		// Switch profiling globally on/off
//#define PROFILE_SAT	// SAT checking
//#define PROFILE_HT	// Hash tables
//#define PROFILE_CNF	// CNF functions
//#define PROFILE_EXEC	// execution: executables, apply, eval
//#define PROFILE_CEGAR	// CEGAR functions

#ifdef PROFILER
	#include <time.h>
	#include <sys/time.h>

	struct profilerData_ {
		char* name;
		unsigned long int nbCalls;
		unsigned long int runtime;
		unsigned long int max;
		struct timeval begin;
		struct timeval end;
	};

	typedef struct profilerData_ tProfilerData;

	#define PROFILER_REGISTER(var, name, max)	tProfilerData var = {name, 0, 0, max, 0, 0};

	#define PROFILER_USE(var)		extern tProfilerData var;

	#define PROFILER_START(var)		gettimeofday(&(var.begin), NULL); \
									var.nbCalls++;

	#define PROFILER_END(var)		gettimeofday(&var.end, NULL); \
									var.runtime += (    ((double)var.end.tv_sec * 1000000.0 + (double)var.end.tv_usec) \
													-   ((double)var.begin.tv_sec * 1000000.0 + (double)var.begin.tv_usec) ); \
									if((var.runtime / var.nbCalls) > var.max) { 		\
										time_t t;										\
										struct tm * ti;									\
										char buffer[9];									\
										time(&t);										\
										ti = localtime(&t);								\
										strftime (buffer,9,"%H:%M:%S", ti);				\
										printf("%s p[%s]: average %lu microsec exceeding max set at %lu\n", buffer, var.name, var.runtime / var.nbCalls, var.max); \
									}

	#define PROFILER_CRITICAL(var)	((var.runtime / var.nbCalls) > var.max)

	#define PROFILER_REPORT(var)	printf("%-25s: %12lu calls, %5.2f seconds\n", var.name, var.nbCalls, ((double) var.runtime)/1000000);
#endif

#ifndef PROFILER
	#define PROFILER_REGISTER(var, name, max)
	#define PROFILER_USE(var)
	#define PROFILER_START(var)
	#define PROFILER_END(var)
	#define PROFILER_CRITICAL(var) 0
	#define PROFILER_REPORT(var)
#endif
