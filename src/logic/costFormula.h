struct _costFormula {
	int within;
    int maxCost;
    int maxQualityLoss;
	ptExpNode property;
    
};
typedef struct _costFormula tCostFormula;
typedef struct _costFormula * ptCostFormula;

ptCostFormula createCostFormula(ptExpNode property, int maxTime, int maxCost, int maxQualityLoss);
void destroyCostFormula(ptCostFormula formula);

int costFunction(int time, int cost, int qualityLoss);
