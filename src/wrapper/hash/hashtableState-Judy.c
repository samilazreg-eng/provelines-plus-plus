#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "error.h"
#include "main.h"
#include "list.h"
#include "stack.h"
#include "symbols.h"
#include "automata.h"
#include "state.h"
#include "execution.h"
#include "hashState.h"
#include "hashtableState.h"
#include <Judy.h>

#ifdef PROFILE_HT
	PROFILER_REGISTER(pr_htVisitedStatesInsert, "htVisitedStatesInsert", 10);
	PROFILER_REGISTER(pr_htVisitedStatesFind, "htVisitedStatesFind", 200);
#endif

#define HT_VISITED_SIZE 65536
#define HT_OUTER_SIZE 65536

void* _htVisited[HT_VISITED_SIZE] = { NULL };
void* _htOuter[HT_OUTER_SIZE] = { NULL };

long unsigned int htVisitedStatesNbFilledBuckets;
long unsigned int htVisitedStatesNbRecords;

void htVisitedStatesInit() {
	// Load hashtable into cache
	unsigned int count;
	for(count = 0; count < HT_VISITED_SIZE; count++) _htVisited[count] = NULL;
}

/*
 * Stored hash 1356096111
 * Size = 95, hash = 1356096111
 */

void htVisitedStatesInsert(tHtKey key, ptState state) {
	if(!state) return;
	#ifdef PROFILE_HT
		PROFILER_START(pr_htVisitedStatesInsert);
	#endif

	if(_htVisited[key % HT_VISITED_SIZE] == NULL) htVisitedStatesNbFilledBuckets++;
	htVisitedStatesNbRecords++;
	void** value = NULL;
	JHSI(value, _htVisited[key % HT_VISITED_SIZE], state->payload, state->payloadSize); // TODO: memory leak here
	if(value == PJERR) failure("Out of memory (inserting into hashtable).\n");
    *value = state;

	#ifdef PROFILE_HT
		PROFILER_END(pr_htVisitedStatesInsert);
	#endif
}

byte htVisitedStatesFind(tHtKey key, ptState state, ptState* foundState) {
	*foundState = NULL;
	void** value = NULL;
	JHSG(value, _htVisited[key % HT_VISITED_SIZE], state->payload, state->payloadSize);
	if(value) {
		*foundState = (ptState) *value;
		if(state->foundInDFS == (*foundState)->foundInDFS || (state->foundInDFS == DFS_OUTER && (*foundState)->foundInDFS == DFS_INNER)) {
			byte compare = stateCompare(state, *foundState);
			if(compare == STATES_SAME_S1_VISITED) {
				*foundState = NULL;

				#ifdef PROFILE_HT
					PROFILER_END(pr_htVisitedStatesFind);
				#endif
				return 1;
			} else if(compare == STATES_SAME_S1_FRESH) {

				#ifdef PROFILE_HT
					PROFILER_END(pr_htVisitedStatesFind);
				#endif
				return 0;
			} else {
				printf("Got bad state\n");
				exit(1);
			}
		} else {
			*foundState = NULL;
		}
	}

	#ifdef PROFILE_HT
		PROFILER_END(pr_htVisitedStatesFind);
	#endif
	return 0;
}

