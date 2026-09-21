#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "list.h"
#include "clockZone.h"
#include "tctl.h"


ptTctlFormula createTctlFormula(byte type, void * premisse, int bound, void * property) {
	ptTctlFormula formula = (ptTctlFormula) malloc(sizeof(tTctlFormula));
	if(!formula) failure("Out of memory (creating tTctlFormula).\n");
	formula->type = type;
	formula->bound = bound;
	formula->zone = NULL;
	formula->premisse = premisse;
	if(!property) failure("[createFormula] Property inside formula cannot be NULL.\n");
	formula->property = property;
	return formula;
}

void destroyTctlFormula(ptTctlFormula formula) {
	if(formula) {
		free(formula);
	}
}
