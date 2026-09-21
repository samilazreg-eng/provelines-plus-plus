#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "main.h"
#include "cnf.h"
#include "boolFct.h"
#include "tvl.h"

void initBoolFct() {} // Nothing to do

ptBoolFct dimacsFileToBool(char * filePath) {
	return dimacsFileToCNF(filePath);
}

ptBoolFct createLiteral(int lit) {
	return createCNFLiteral(lit);
}

ptBoolFct addConjunction(ptBoolFct leftFct, ptBoolFct rightFct, byte preserveLeft, byte preserveRight) {
	return addCNFConjunction((ptCNF) leftFct, (ptCNF) rightFct, preserveLeft, preserveRight);
}

ptBoolFct addDisjunction(ptBoolFct leftFct, ptBoolFct rightFct, byte preserveLeft, byte preserveRight) {
	return addCNFDisjunction((ptCNF) leftFct, (ptCNF) rightFct, preserveLeft, preserveRight);
}
ptBoolFct copyBool(ptBoolFct formula) {
	return copyCNF((ptCNF) formula);
}

ptBoolFct negateBool(ptBoolFct formula) {
	return negateCNF((ptCNF) formula);
}

void destroyBool(ptBoolFct formula) {
	destroyCNF((ptCNF) formula);
}

void printBool(ptBoolFct formula) {
	printCNF((ptCNF) formula);
}
