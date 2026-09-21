#define spoiler 0
#define duplicator 1

struct simHtTrans_ {
	struct simHtState_ * source;
	struct simHtState_ * target;
	ptBoolFct features;
#ifdef CLOCK
	ptClockZone guard;
#endif
};
typedef struct simHtTrans_ tSimHtTrans;
typedef struct simHtTrans_ * ptSimHtTrans;

struct simHtState_ {
	ptState s1;
	ptState s2;
	int h1;
	int h2;
	byte turn; // 0 => spoiler's turn; 1 => duplicator's turn
	ptList succ;
	ptList pred;
#ifdef CLOCK
	ptFederation fed; // zones and products for which s2 *DOES NOT* simulate s1
#else
	ptBoolFct features; // products for which s2 simulates s1
#endif
};
typedef struct simHtState_ tSimHtState;
typedef struct simHtState_ * ptSimHtState;

ptSimHtState createSimHtState(ptState s1, ptState s2, byte turn);
#ifdef CLOCK
ptSimHtTrans createSimHtTrans(ptSimHtState source, ptSimHtState target, ptBoolFct features, ptClockZone guard);
#else
ptSimHtTrans createSimHtTrans(ptSimHtState source, ptSimHtState target, ptBoolFct features);
#endif
void startSimulation(ptList props, ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptList props2, ptSymTabNode globalSymTab2, ptMTypeNode mtypes2);
void computeGameGraph(void * table, ptList props, ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptStack stack1, ptList props2, ptSymTabNode globalSymTab2, ptMTypeNode mtypes2, ptStack stack2);
void propagate(ptSimHtState shs, byte player);
void removeWinningStates(void * table, ptSimHtState initSimHtState);
void printSimulation(ptSimHtState init);

//ptBoolFct simulation(void * table, ptList props, ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptStack stack1, ptSymTabNode globalSymTab2, ptMTypeNode mtypes2, ptStack stack2);
