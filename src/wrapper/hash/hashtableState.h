/*
 * STATE HASHTABLE
 * * * * * * * * * * * * * * * * * * * * * * * */

typedef unsigned int   tHtKey;
typedef unsigned int* ptHtKey;

#define DFS_OUTER 1
#define DFS_INNER 2

// A state in the hashtable is a reduced version of a "normal" state
// TODO: we need to keep the payload length here as well if two states have same hash but different payloadlength, the memcmp on them will result in a segmentation fault
struct htState {
	void * payload;
	byte foundInDFS;			// Indicates on which search the state was found: DFS_OUTER or DFS_INNER (which means DFS_OUTER and DFS_INNER)

								// The inner DFS starts with the deepest violating state of the outer DFS.
								// It is thus guaranteed that all states found during the inner DFS have already been visited by the outer DFS.
								// This is because before it can even reach states NOT visited by the outer search, it must "hit" the prefix
								// of the outer search, and thus stop (because a violation was found).

								// Therefore, the foundInDFS flag DFS_INNER is used to mean that the state was visited by *both*, the inner
								// and the outer DFS.
	ptBoolFct outerFeatures;	// The features required to reach the state on the outer DFS
	ptBoolFct innerFeatures;	// The features required to reach the state on the inner DFS
    
    // time
    int time;
    int cost;
    int qualityLoss;
};

typedef struct htState tHtState;
typedef struct htState * ptHtState;


/*
 * API
 * * * * * * * * * * * * * * * * * * * * * * * */

// Hashtable keeping track of the visited states
void htVisitedStatesInit();
void htVisitedStatesInsert(tHtKey key, ptState state, byte foundInDFS);
void htVisitedStatesRemove(tHtKey key, ptHtState state);
byte htVisitedStatesFind(tHtKey key, ptState state, byte foundInDFS, ptHtState* foundState);
byte htVisitedStatesFindList(tHtKey key, ptState state, byte foundInDFS, ptList* foundStates);

// These values should only be read
extern long unsigned int htVisitedStatesNbFilledBuckets;
extern long unsigned int htVisitedStatesNbRecords;

// Hashtable containing states visited during the outer search to get to a violating state
void htOuterStatesInit();
void htOuterStatesInsert(tHtKey key, ptState state);
void htOuterStatesRemove(tHtKey key, void* payload, unsigned int payloadSize);
ptHtState htOuterStatesFind(tHtKey key, ptState state);

void destroyHtState(ptHtState state);
