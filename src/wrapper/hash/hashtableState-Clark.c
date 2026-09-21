#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "error.h"
#include "main.h"
#include "list.h"
#include "stack.h"
#include "boolFct.h"
#include "symbols.h"
#include "automata.h"
#include "state.h"
#include "execution.h"
#include "hashtable.h"
#include "hashtable_itr.h"
#include "hashState.h"
#include "hashtableState.h"


#ifdef PROFILE_HT
	PROFILER_REGISTER(pr_htVisitedStatesInsert, "htVisitedStatesInsert", 10);
	PROFILER_REGISTER(pr_htVisitedStatesFind, "htVisitedStatesFind", 200);
#endif

struct value_ {
    ptList list;
};
typedef struct value_   tValue;
typedef struct value_* ptValue;

long unsigned int htVisitedStatesNbFilledBuckets;
long unsigned int htVisitedStatesNbRecords;

DEFINE_HASHTABLE_INSERT(insert_some, tHtKey, struct value_);
DEFINE_HASHTABLE_SEARCH(search_some, tHtKey, struct value_);
DEFINE_HASHTABLE_REMOVE(remove_some, tHtKey, struct value_);
DEFINE_HASHTABLE_ITERATOR_SEARCH(search_itr_some, tHtKey);

static unsigned int hashfromkey(void* k) {
    return *((ptHtKey) k);
}

static int equalkeys(void* k1, void* k2) {
    return *((ptHtKey) k1) == *((ptHtKey) k2);
}

static struct hashtable* _table;
static struct hashtable* _tableOuter;

void htVisitedStatesInit() {
	_table = create_hashtable(2^16, hashfromkey, equalkeys);
}

void htOuterStatesInit() {
	_tableOuter = create_hashtable(2^16, hashfromkey, equalkeys);
}



void _htInsert(struct hashtable* table, tHtKey key, ptState state, byte foundInDFS) {
	if(!state) return;
	ptHtKey keyP = (ptHtKey) malloc(sizeof(tHtKey));
	if(!keyP) failure("Out of memory (creating hashtable key).\n");
	*keyP = key;
	ptValue valP;
	valP = remove_some(table, keyP);
	if(!valP) {
		valP = (ptValue) malloc(sizeof(tValue));
		if(!valP) failure("Out of memory (creating hashtable value).\n");
		valP->list = NULL;
		if(table == _table) htVisitedStatesNbFilledBuckets++;
	}
	if(table == _table) htVisitedStatesNbRecords++;

	ptHtState hs = (ptHtState) malloc(sizeof(tHtState));
	hs->payload = state->payload;
	hs->foundInDFS = foundInDFS;
	hs->outerFeatures = state->features;
	hs->innerFeatures = NULL;
    hs->time = state->time;
    hs->cost = state->cost;
    hs->qualityLoss = state->qualityLoss;
	valP->list = listAdd(valP->list, hs);
	hs = NULL;

	if(!insert_some(table, keyP, valP)) failure("Out of memory (inserting state in hashtable)\n");
}

void _htRemove(struct hashtable * table, tHtKey key, ptHtState htState) {
	if(!htState) return;
	ptHtKey keyP = &key;
	ptValue valP = search_some(_table, keyP);
	valP->list = listRemove(valP->list, htState);
	if(!valP->list)
		remove_some(_table, keyP);
	free(valP);
}

/**
 * Inserts an element into the states hashtable.
 *
 * This function does NOT check whether the state is already
 * there, it blindly inserts it.
 */
void htVisitedStatesInsert(tHtKey key, ptState state, byte foundInDFS) {
	#ifdef PROFILE_HT
		PROFILER_START(pr_htVisitedStatesInsert);
	#endif
	_htInsert(_table, key, state, foundInDFS);
	#ifdef PROFILE_HT
		PROFILER_END(pr_htVisitedStatesInsert);
	#endif
}

void htVisitedStatesRemove(tHtKey key, ptHtState state) {
	_htRemove(_table, key, state);
}

/**
 * Inserts an element into the outer states hashtable.
 */
void htOuterStatesInsert(tHtKey key, ptState state) {
	_htInsert(_tableOuter, key, state, DFS_OUTER);
}


/**
 * Returns true in case the state was already visited.  That is, if there is s2
 * so that stateCompare(s, s2) == STATES_SAME_S1_VISITED.  The foundInDFS parameter
 * specifies on which DFS the state was supposedly visited.
 *
 * Possible scenarios:
 *
 * (A) If the state was visited during the specified DFS, the function returns true.
 *
 * (B) If the state was not visited at all, the return value is false and foundState is NULL.
 *
 * (C) If the state was visited during the specified DFS, but with less features, then the function
 *     returns false and writes a reference to the previously visited state into foundState.
 *
 * (D) If DFS_INNER is required and the state was already visited during DFS_OUTER, then
 *     the function returns false and writes a reference to the previously visited state
 *     into foundState.  The foundState->foundOnDFS is DFS_OUTER.  The caller can then set
 *     the foundState->innerFeatures and change foundState->foundInDFS to DFS_INNER
 *
 * To distinguish C from D in the case where DFS_INNER is required (not necessary for DFS_OUTER),
 * the foundState->foundInDFS has to be tested.
 */
byte htVisitedStatesFind(tHtKey key, ptState state, byte foundInDFS, ptHtState* foundState) {
#ifdef PROFILE_HT
    PROFILER_START(pr_htVisitedStatesFind);
#endif
    if(foundState) *foundState = NULL;
    ptHtKey keyP = (ptHtKey) malloc(sizeof(tHtKey));
    if(!keyP) failure("Out of memory (creating hashtable key).\n");
    *keyP = key;
    ptValue valP;
    valP = search_some(_table, keyP);
    free(keyP);
    if(valP) {
        ptList listElement = valP->list;
        byte compare;
        ptHtState candidateState;
        while(listElement) {
            candidateState = (ptHtState) listElement->value;
            compare = stateCompare(state, candidateState->payload, foundInDFS == DFS_OUTER ? candidateState->outerFeatures : candidateState->innerFeatures, candidateState->time, candidateState->cost, candidateState->qualityLoss);
            if(compare != STATES_DIFF) {
                // Cases A, C
                if(foundInDFS == candidateState->foundInDFS || (foundInDFS == DFS_OUTER && candidateState->foundInDFS == DFS_INNER)) {
                    if(compare == STATES_SAME_S1_VISITED) {
#ifdef PROFILE_HT
                        PROFILER_END(pr_htVisitedStatesFind);
#endif
                        return 1;
                    } else if(compare == STATES_SAME_S1_FRESH) {
                        *foundState = candidateState;
#ifdef PROFILE_HT
                        PROFILER_END(pr_htVisitedStatesFind);
#endif
                        return 0;
                    }
                } else if(foundInDFS == DFS_INNER /* && candidateState->foundInDFS == DFS_OUTER */) {
                    *foundState = candidateState;
#ifdef PROFILE_HT
                    PROFILER_END(pr_htVisitedStatesFind);
#endif
                    return 0;
                }
            }
            listElement = listElement->next;
        }
    }
#ifdef PROFILE_HT
    PROFILER_END(pr_htVisitedStatesFind);
#endif
    return 0;
}

byte htVisitedStatesFindList(tHtKey key, ptState state, byte foundInDFS, ptList* foundStates) {
#ifdef PROFILE_HT
    PROFILER_START(pr_htVisitedStatesFind);
#endif
    if(foundStates) *foundStates = NULL;
    ptHtKey keyP = (ptHtKey) malloc(sizeof(tHtKey));
    if(!keyP) failure("Out of memory (creating hashtable key).\n");
    *keyP = key;
    ptValue valP;
    valP = search_some(_table, keyP);
    free(keyP);
    if(valP) {
        ptList listElement = valP->list;
        byte compare;
        ptHtState candidateState;
        while(listElement) {
            candidateState = (ptHtState) listElement->value;
            compare = stateCompare(state, candidateState->payload, foundInDFS == DFS_OUTER ? candidateState->outerFeatures : candidateState->innerFeatures, candidateState->time, candidateState->cost, candidateState->qualityLoss);
            if(compare != STATES_DIFF) {
                // Cases A, C
                if(compare == STATES_SAME_S1_VISITED) {
                    return 1;
                } else if(compare == STATES_SAME_S1_FRESH) {
                    *foundStates = listAdd(*foundStates, candidateState);
                }
            }
            listElement = listElement->next;
        }
    }
#ifdef PROFILE_HT
    PROFILER_END(pr_htVisitedStatesFind);
#endif
    return 0;
}


/**
 * Checks whether a state is in the backlinks hashtable.
 *
 * For this check it is sufficient to check that the state exists; the set of
 * products of the state in the hashtable will necessarily include the set of
 * products of the state to be tested since we're testing a path in which the
 * states in the hashtable are all ancestors of the state to be tested.
 */
ptHtState htOuterStatesFind(tHtKey key, ptState state) {
	ptHtKey keyP = (ptHtKey) malloc(sizeof(tHtKey));
	if(!keyP) failure("Out of memory (creating hashtable key).\n");
	*keyP = key;
	ptValue valP;
	valP = search_some(_tableOuter, keyP);
	free(keyP);
	if(valP) {
		ptList listElement = valP->list;
		while(listElement) {
			// Here we pass NULL as the feature expression of the candidate state instead
			// of the actual feature expression.  This avoids a implies() check because we
			// know that state->features necessarily implies candidate->features (if they
			// are both equal).
            
            // time: idem, 0 is passed as old state time
			if(stateCompare(state, ((ptHtState) listElement->value)->payload, NULL, 0, 0, 0) == STATES_SAME_S1_VISITED) return (ptHtState) listElement->value;
			listElement = listElement->next;
		}
	}
	return NULL;
}

/**
 * Removes a state from the backlinks hashtable.
 */
void htOuterStatesRemove(tHtKey key, void* payload, unsigned int payloadSize) {
	if(payload) {
		ptHtKey keyP = (ptHtKey) malloc(sizeof(tHtKey));
		if(!keyP) failure("Out of memory (creating hashtable key).\n");
		*keyP = key;
		ptValue valP = search_some(_tableOuter, keyP); // Getting the list of htStates registered at the given key.
		if(valP) {
			ptList stateList = valP->list;
			ptList previous = NULL;
			ptHtState currentHtState;
			byte stop = 0;
			byte empty = 0;
			while(stateList && !stop) { // stop holds iff the searched htState has been found and removed.
				currentHtState = (ptHtState) stateList->value;
				if(memcmp(payload, currentHtState->payload, payloadSize) == 0) {
					/*if(previous) previous->next = stateList->next; // removing the found htState from the list.
					else if(stateList->next) valP->list = stateList->next; // The searched state was the first element.
					else empty = 1; // The list will be empty after the removal because there was only the searched state in it.
					free(currentHtState);
					free(stateList);
					stop = 1;*/
					valP->list = listRemove(valP->list, currentHtState);
					free(currentHtState);
					stop = 1;
				} else {
					previous = stateList;
					stateList = stateList->next;
				}
			}
			if(!valP->list) { // The list registered at the given key is now empty: it can be removed from the hashtable.
				valP = remove_some(_tableOuter, keyP);
				free(valP);
			}
		}
		free(keyP);
	}
}

void destroyHtState(ptHtState state) {
    destroyBool(state->outerFeatures);
    destroyBool(state->innerFeatures);
    free(state);
}
