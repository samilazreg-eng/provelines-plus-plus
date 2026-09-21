/*
 * Execution of FSMs
 * * * * * * * * * * * * * * * * * * * * * * * */

#define processTrans 0
#define directTrans 1

// ProcessTransitions are returned by the executables() function
struct processTransition_ {		//
	ptFsmTrans trans;			//  - The transition that can be fired
	struct processTransition_* response;		// 	- In case of a rendezvous request, this is the response transition.
	ptStateMask process;		//	- The mask of the process to which the transition belongs (from the state that was given to executables())
	ptBoolFct features;			//  - The feature expression of the state once it was fired (to avoid having to recalculate it afterwards).
    int delay;
};

typedef struct processTransition_   tProcessTransition;
typedef struct processTransition_* ptProcessTransition;

// DirectTransitions are returned by the executablesNonStutter() function
struct directTransition_ {		//
	ptState target;				//  - The state to reach.
	ptBoolFct features;			//  - The feature expression of the state once it was fired (to avoid having to recalculate it afterwards).
};

typedef struct directTransition_   tDirectTransition;
typedef struct directTransition_* ptDirectTransition;

// An element on the exploration stack (corresponds to a stack frame if the algorithm were implemented recursively).
// The (synchronous) product between the E_never and E transitions is calculated by iterating through the E list for
// each E_never element.  This means that if E_never is NULL, then the whole thing is done; if E is NULL, then the
// E_never list has to be advanced, and the E list reset to the beginning (E_save).
struct stackElt {
	ptState state;			// The state itself
	ptList E_never_save;	// A list of ptFsmTrans: the list of executable transitions in the never claim.
	ptList E_never;			// A list of ptFsmTrans: points to next transition in the E_never_save list.
	ptList E_save;			// A list of ptProcessTransition: the list of executable transitions of the FSMs.
	ptList E;				// A list of ptProcessTransition: points to next transition in the E_save list.
	unsigned char nbErrors;	// Number of errors encountered when the stack element was last updated.
    int smallestDelay;
    ptList onHold;          // A list of ptProcessTransition: the delayed transition that are partially elapsed
};

typedef struct stackElt   tStackElt;
typedef struct stackElt* ptStackElt;


/*
 * API
 * * * * * * * * * * * * * * * * * * * * * * * */

// Expression evaluation
#define EVAL_EXECUTABILITY 0
#define EVAL_EXPRESSION 1

int eval(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptState state, ptStateMask mask, struct expNode_ * expression, byte flag, ptBoolFct * dynamicF); // Return true <=> transition 'trans' is executable on process 'mask'.
byte checkEqualProps(ptList props, ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptState s, ptList props2, ptSymTabNode globalSymTab2, ptMTypeNode mtypes2, ptState s2);

// Executable transitions in state
ptList executables(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptState state, byte stutter, int nbErrors, byte* hasDeadlock, ptBoolFct* featuresOut, byte* allProductsOut, ptBoolFct* noOutgoing, byte* resetExclusivity, ptList previousTrans, int previousDelay);
ptList executablesNonStutter(ptList props, ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptState state, byte stutter, int nbErrors, byte* hasDeadlock, ptBoolFct* featuresOut, byte* allProductsOut, ptBoolFct* noOutgoing);
ptList executablesNever(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptState state);

ptProcessTransition createProcessTransition(ptStateMask process, ptFsmTrans trans, ptBoolFct features, ptProcessTransition response);
void destroyProcessTransition(ptProcessTransition ptrans);
ptProcessTransition copyProcessTransition(ptProcessTransition);
ptProcessTransition selectTransition(ptList transList); // Choose a transition and returns it.
void destroyProcTransList(ptList transList, byte process_or_direct);
void checkProcTransList(ptList list);

// Applying statements
ptState apply(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptState state, ptProcessTransition procTrans, byte preserve, byte* assertViolation); // Execute a transition on a given process.
ptState applyRepeated(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptState state, ptList procTrans, byte preserve, byte* assertViolation);
ptState applyNever(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptState state, struct fsmTrans_ * transition);

// Execution stack
ptStackElt createStackElement(ptState state, int nbErrors);
void destroyStackElement(ptStackElt elt, byte process_or_direct);
void printStackElementStack(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptStack stackPtr, ptState loopBegin, ptStackElt prevTopElt);
void destroyStackElementStack(ptStack stackPtr, byte process_or_direct);

// Normal execution, no verification
void launchExecution();
