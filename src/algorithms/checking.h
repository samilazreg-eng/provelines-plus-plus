// Automata-based model checking
void startNestedDFS(ptSymTabNode globalSymTab, ptMTypeNode mtypes);
byte outerDFS(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptStack stackOuter);
byte innerDFS(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptStack stackOuter, ptStack stackInner);

void startSamplingExploration(int samples, ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptCostFormula property);
byte samplingExplore(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptStack stackOuter, ptCostFormula property, int * optimalScore);

// Exhaustive state-space exploration for assertion- and deadlock checking
void startExploration(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptCostFormula property);
byte explore(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptStack stackOuter, ptCostFormula property);

void startExplorationWithFDG(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptFdg fdg);
byte exploreWithFDG(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptStack stackOuter, ptFdg fdg);

void startExplorationBFS(ptSymTabNode globalSymTab, ptMTypeNode mtypes);
byte exploreBFS(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptList stateList);
