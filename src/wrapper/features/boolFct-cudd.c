#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "main.h"
#include "mtr.h"
#include "epd.h"
#include "cuddInt.h"
#include "cudd.h"
#include "boolFct.h"
#include "tvl.h"


DdManager* _manager = NULL;

void initBoolFct() {
	_manager = Cudd_Init(0, 0, CUDD_UNIQUE_SLOTS, CUDD_CACHE_SLOTS, 0);
}

void debug(ptBoolFct formula) {
    //Cudd_PrintDebug(_manager, (DdNode *) formula, 0, 4);
}

ptBoolFct dimacsFileToBool(char * filePath) {
	if(!filePath) return NULL;
	FILE* dimacsFile = fopen(filePath, "r");
	char format[100];
	if(dimacsFile != NULL) {
		fgets(format,100,dimacsFile);
		int currentNbr;
		//DdNode * conjunction = Cudd_ReadOne(_manager);
        //Cudd_Ref(conjunction);
        ptBoolFct conjunction = getTrue();
        //DdNode * disjunction = Cudd_Not(Cudd_ReadOne(_manager));
		//Cudd_Ref(disjunction);
        ptBoolFct disjunction = getFalse();
        //DdNode * tmp;
		//DdNode * var;
        while(fscanf(dimacsFile, "%d", &currentNbr) != EOF) {
			if(currentNbr == 0) {
				//tmp = Cudd_bddAnd(_manager, conjunction, disjunction);
				//Cudd_Ref(tmp);
                //Cudd_RecursiveDeref(_manager, conjunction);
                //Cudd_RecursiveDeref(_manager, disjunction);
				conjunction = addConjunction(conjunction, disjunction, 0, 0);
				//disjunction = Cudd_Not(Cudd_ReadOne(_manager));
				//Cudd_Ref(disjunction);
                disjunction = getFalse();
			} else {
				//if(currentNbr > 0) var = Cudd_bddIthVar(_manager, currentNbr);
				//else {
					//currentNbr = -currentNbr;
					//var = Cudd_bddIthVar(_manager, currentNbr);
					//var = Cudd_Not(var);
				//}
				//Cudd_Ref(var);
				//tmp = Cudd_bddOr(_manager, var, disjunction);
				//Cudd_Ref(tmp);
				//Cudd_RecursiveDeref(_manager, var);
				//Cudd_RecursiveDeref(_manager, disjunction);
                disjunction = addDisjunction(createLiteral(currentNbr), disjunction, 0, 0);
			}
		}
		//Cudd_RecursiveDeref(_manager, disjunction);
		fclose(dimacsFile);
        debug(conjunction);
		return conjunction;
	} else return NULL;
}


ptBoolFct createLiteral(int lit) {
	DdNode * var;
	if(lit > 0) var = Cudd_bddIthVar(_manager, lit);
	else {
		lit = -lit;
		var = Cudd_bddIthVar(_manager, lit);
        if(!var) failure("Out of memory (boolFct-cudd.c, createLiteral).\n");
        Cudd_Ref(var);
		var = Cudd_Not(var);
	}
	if(!var) failure("Out of memory (boolFct-cudd.c, createLiteral).\n");
	Cudd_Ref(var);
    debug(var);
	return var;
}

ptBoolFct createVariable(char * name) {
	if(!name) return NULL;
	ptBoolFct result = createLiteral(createMapping(name));
    debug(result);
    
    return result;
}

ptBoolFct addConjunction(ptBoolFct leftFct, ptBoolFct rightFct, byte preserveLeft, byte preserveRight) {
	if(!leftFct && !preserveRight) return rightFct;
	else if (!leftFct && preserveRight) return copyBool(rightFct);

	if(!rightFct && !preserveLeft) return leftFct;
	else if(!rightFct && preserveLeft) return copyBool(leftFct);

	DdNode * res = Cudd_bddAnd(_manager, (DdNode *) leftFct, (DdNode *) rightFct);
	if(!res) failure("Out of memory (boolFct-cudd.c, addConjunction).\n");
	Cudd_Ref(res);

	if(!preserveLeft) destroyBool(leftFct);
	if(!preserveRight) destroyBool(rightFct);
    debug(res);
	return res;
}

ptBoolFct addDisjunction(ptBoolFct leftFct, ptBoolFct rightFct, byte preserveLeft, byte preserveRight) {
	if(!leftFct && !preserveRight) return rightFct;
	else if (!leftFct && preserveRight) return copyBool(rightFct);

	if(!rightFct && !preserveLeft) return leftFct;
	else if(!rightFct && preserveLeft) return copyBool(leftFct);

	DdNode * res = Cudd_bddOr(_manager, (DdNode *) leftFct, (DdNode *) rightFct);
	if(!res) failure("Out of memory (boolFct-cudd.c, addDisjunction).\n");
	Cudd_Ref(res);

	if(!preserveLeft) destroyBool(leftFct);
	if(!preserveRight) destroyBool(rightFct);
    debug(res);
	return res;
}

ptBoolFct copyBool(ptBoolFct formula) {
	if(!formula) return NULL;
	Cudd_Ref(formula);
    debug(formula);
	return formula;
}

ptBoolFct negateBool(ptBoolFct formula) {
	if(!formula) return NULL;
	DdNode * res = Cudd_Not((DdNode *) formula);
	if(!res) failure("Out of memory (boolFct-cudd.c, negateBool).\n");
	Cudd_Ref(res);
	return res;
}

void destroyBool(ptBoolFct formula) {
	//if(formula) Cudd_Deref((DdNode *) formula);
    debug(formula);
}

byte isLogicZero(ptBoolFct fct) {
	if(fct && (fct == Cudd_ReadLogicZero(_manager) || fct == Cudd_ReadZero(_manager))) return 1;
	else return 0;
}

byte isLogicOne(ptBoolFct fct) {
	if(!fct) return 1;
	if(fct && (fct == Cudd_Not(Cudd_ReadLogicZero(_manager)) || fct == Cudd_Not(Cudd_ReadZero(_manager)))) return 1;
	else return 0;
}

ptBoolFct getTrue() {
    ptBoolFct t = Cudd_ReadOne(_manager);//Cudd_Not(Cudd_ReadLogicZero(_manager));
	Cudd_Ref(t);
    debug(t);
	return t;
}

ptBoolFct getFalse() {
	ptBoolFct t = Cudd_ReadLogicZero(_manager);
	Cudd_Ref(t);
    debug(t);
	return t;
}

void printBool(ptBoolFct formula) {
	if(!formula) printf("All");
	else if(isLogicZero(formula)) printf("None");
	else if(isLogicOne(formula)) printf("All");
	else {
		_manager->out = fopen("__printbool.tmp","w");
		Cudd_PrintMinterm(_manager, (DdNode *)formula);
		fclose(_manager->out);
		FILE * stream = fopen("__printbool.tmp", "r");
		char c = 'c';
		char * feature;
		char * operator;
		int i = 0;
		byte nextliteral = 0;
		byte nextminterm = 0;
		printf("(");
		while(c != EOF && fscanf(stream, "%c", &c) != EOF) {
			if(c == '0') {
				if(nextliteral) operator = (" & !");
				else if (nextminterm) operator = (") | (!");
				else operator = "!";
				feature = getFeatureIDName(i);
				printf("%s%s", operator, feature);
				nextliteral = 1;
				nextminterm = 0;
				i++;
			}
			else if (c == '1') {
				if(nextliteral) operator = (" & ");
				else if (nextminterm) operator = (") | (");
				else operator = "";
				feature = getFeatureIDName(i);
				printf("%s%s", operator, feature);
				i++;
				nextliteral = 1;
				nextminterm = 0;
			}
			else if(c == ' ') {
				while(c != '\n' && fscanf(stream, "%c", &c) != EOF);
				nextliteral = 0;
				nextminterm = 1;
				i = 0;
			}
			else i++;
		}
		printf(")");
		fclose(stream);

	}
}
