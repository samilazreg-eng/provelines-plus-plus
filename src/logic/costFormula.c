#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "main.h"
#include "symbols.h"
#include "costFormula.h"

ptCostFormula createCostFormula(ptExpNode property, int maxTime, int maxCost, int maxQualityLoss) {
	ptCostFormula formula = (ptCostFormula) malloc(sizeof(tCostFormula));
	if(!formula) failure("Out of memory (creating tCostFormula).\n");
	formula->maxCost = maxCost;
    formula->within = maxTime;
    formula->maxQualityLoss = maxQualityLoss;
	if(!property) failure("[createCostFormula] Property inside formula cannot be NULL.\n");
	formula->property = property;
	return formula;
}

void destroyCostFormula(ptCostFormula formula) {
	if(formula) {
		free(formula);
	}
}

int costFunction(int time, int cost, int qualityLoss) {
    return 1 * time + 10 * cost + 100 * qualityLoss;
}
