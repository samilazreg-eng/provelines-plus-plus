#define EXPLORE 0
#define NESTED 	1

struct counterExample {
	ptStack trace; 		// Non-cycling part of the trace
	ptStack cycle; 		// Cycling part of the trace
	ptBoolFct features; // products that executes the counterexample
	ptStack trans; 		// Fsm transitions that yield the non-cycling part of the trace
	ptStack transCycle;	// Same, but for the cycling part
};
typedef struct counterExample tCE;
typedef struct counterExample * ptCE;

ptCE createCounterExample(ptStack trace, ptStack cycle, ptBoolFct features);
ptFsm buildFeatureAbstractFSM(ptFsm fsm);
ptSymTabNode buildInitialAbstraction(ptSymTabNode globalSymTab);
ptBoolFct replayAndRefine(ptSymTabNode globalSymTab, ptCE counterexample, byte * refined);
void cegar(ptSymTabNode globalSymTab, ptMTypeNode mtypes, byte procedure);
