#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "error.h"
#include "main.h"
#include "list.h"
#include "stack.h"
#include "hashtableGen.h"
#include "boolFct.h"
#include "symbols.h"
#include "automata.h"
#include "SAT.h"
#ifdef CLOCK
	#include "clockZone.h"
	#include "federation.h"
#endif
#include "state.h"
#include "execution.h"
#include "hashState.h"
#include "tvl.h"
#include "simulation.h"

byte _nbErrors = 0;


int _count = 0;
int _removed = 0;
int _stacked = 0;


ptSimHtState createSimHtState(ptState s1, ptState s2, byte turn) {
	ptSimHtState shs = (ptSimHtState) malloc(sizeof(tSimHtState));
	if(!shs) failure("[createSimHtState] Out of memory.\n");
	shs->s1 = s1->payload;
	shs->s2 = s2->payload;
	shs->h1 = s1->payloadHash;
	shs->h2 = s2->payloadHash;
	shs->turn = turn;
#ifdef CLOCK
	shs->fed = NULL;
#else
	shs->features = getTrue();
#endif
	shs->succ = NULL;
	shs->pred = NULL;
	return shs;
}

destroySimHtState(ptSimHtState shs) {
	if(shs) {
		if(shs->s1) free(shs->s1);
		if(shs->s2) free(shs->s2);
#ifdef CLOCK
		if(shs->fed) destroyFederation(shs->fed, false);
#else
		if(shs->features) destroyBool(shs->features);
#endif
	}
}

#ifdef CLOCK
ptSimHtTrans createSimHtTrans(ptSimHtState source, ptSimHtState target, ptBoolFct features, ptClockZone guard) {
#else
ptSimHtTrans createSimHtTrans(ptSimHtState source, ptSimHtState target, ptBoolFct features) {
#endif
	if(!source || !target) failure("[createSimHtTrans] source or target is NULL\n");
	ptSimHtTrans trans = (ptSimHtTrans) malloc(sizeof(tSimHtTrans));
	trans->source = source;
	trans->target = target;
	trans->features = features;
#ifdef CLOCK
	trans->guard = guard;
#endif
	return trans;
}

ptSimHtState simSearch(void * table, ptState s1, ptState s2, byte turn) {
	ptList prevs = htSearch(table, s1->payloadHash + s2->payloadHash);
	ptList prevs_ = prevs;
	ptSimHtState prev = NULL;
	byte visited = 0;
	while(prevs_ && !visited) {
		prev = (ptSimHtState) prevs_->value;
		if(prev->turn == turn && (memcmp(prev->s1, s1->payload, s1->payloadSize) == 0) && (memcmp(prev->s2, s2->payload, s2->payloadSize) == 0)) {
			visited = 1;
		}
		prevs_ = prevs_->next;
	}
	if(visited) return prev;
	else return NULL;
}

/*
 * For debugging.
 */
void printSimulation(ptSimHtState initSimHtState) {
	void * table = createHashtable();
	ptStack stack = push(NULL, initSimHtState);
	htInsert(table, initSimHtState->h1 + initSimHtState->h2, initSimHtState);
	while(!empty(stack)) {
		ptSimHtState current = top(stack);
		pop(&stack);
		printf("%p (%s's turn)\n", current, current->turn == spoiler ? "Spoiler" : "Duplicator");
		ptList tmp = current->succ;
		if(!tmp)
			printf("\t NO SUCCESSOR.\n");
		byte found = 0;
		while(tmp) {
			ptSimHtTrans trans = (ptSimHtTrans) tmp->value;
			ptSimHtState succ = trans->target;
			if(!htFind(table, succ->h1+succ->h2, succ)) {
				stack = push(stack, succ);
				htInsert(table, succ->h1 + succ->h2, succ);
				found = 1;
			}
			printf("\t");
			if(trans->features)
				printBool(trans->features);
			printf(" ----> %p (%s's turn)\n", succ, succ->turn == spoiler ? "Spoiler" : "Duplicator");
			tmp = tmp->next;
		}
		/*tmp = current->pred;
		if(!tmp)
			printf("\t NO PREDECESSOR.\n");
		while(tmp) {
			ptSimHtState pred = ((ptSimHtTrans) tmp->value)->source;
			printf("\t <--- %d (%s's turn)\n", pred, pred->turn == spoiler ? "Spoiler" : "Duplicator");
			tmp = tmp->next;
		}*/
		printf("\n");
	}
}


void startSimulation(ptList props, ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptList props2, ptSymTabNode globalSymTab2, ptMTypeNode mtypes2) {
	initSolverWithFD(getFeatureModelClauses());
	htVisitedStatesInit();

	// Create initial state
	ptState init = stateCreateInitial(globalSymTab, mtypes);
	init->payloadHash = hashState(init);
	//htVisitedStatesInsert(init->payloadHash, init, DFS_OUTER);

	ptState init2 = stateCreateInitial(globalSymTab2, mtypes2);
	init2->payloadHash = hashState(init2);
	//htVisitedStatesInsert(init2->payloadHash, init2, DFS_OUTER);

	if(!checkEqualProps(props, globalSymTab, mtypes, init, props2, globalSymTab2, mtypes2, init2)) {
		printf("Initial states are different.\n");
		printState(mtypes, init, NULL);
		printState(mtypes2, init2, NULL);
		exit(EXIT_SUCCESS);
	}

	byte resetExclusivity = false;

	ptStackElt elt = createStackElement(init, _nbErrors);
	if(stutterStep)
		elt->E = executablesNonStutter(props, globalSymTab, mtypes, init, 1, _nbErrors, NULL, NULL, NULL, NULL);
	else
		elt->E = executables(globalSymTab, mtypes, init, 1, _nbErrors, NULL, NULL, NULL, NULL, &resetExclusivity);
	elt->E_save = elt->E;
	ptStack stack = push(NULL, elt);

	ptStackElt elt2 = createStackElement(init2, _nbErrors);
	if(stutterStep)
		elt2->E = executablesNonStutter(props, globalSymTab2, mtypes2, init2, 1, _nbErrors, NULL, NULL, NULL, NULL);
	else
		elt2->E = executables(globalSymTab2, mtypes2, init2, 1, _nbErrors, NULL, NULL, NULL, NULL, &resetExclusivity);
	elt2->E_save = elt2->E;
	ptStack stack2 = push(NULL, elt2);

	if(!elt->E && !elt2->E) printf("Simulation holds for all the products.\n");
	if((!elt->E && elt2->E) || (elt->E && !elt2->E)) printf("Simulation holds for no product.\n");

	void * table = createHashtable();

	ptSimHtState initSimHtState = createSimHtState(init, init2, spoiler);
	htInsert(table, init->payloadHash + init2->payloadHash, initSimHtState);
	computeGameGraph(table, props, globalSymTab, mtypes, stack, props2, globalSymTab2, mtypes2, stack2);
	removeWinningStates(table, initSimHtState);
	destroyHashtable(table);
#ifdef CLOCK
#else
	printf("Simulation holds for the following products: \n");
	if(initSimHtState->features) {
		if(isTautologyWrtFD(initSimHtState->features))
			printf("All products\n");
		else {
			printBool(initSimHtState->features);
			printf("\n");
		}
	}
	else
		printf("All products\n");
#endif
	exit(EXIT_SUCCESS);
}

void computeNextState(void * table, ptList playerProps, ptSymTabNode playerSymTab, ptMTypeNode playerMtypes, ptStack * playerStack, ptList opponentProps, ptSymTabNode opponentSymTab, ptMTypeNode opponentMtypes, ptStack * opponentStack, byte * turn, ptSimHtState currentShs) {
	ptSimHtState visited, new;
	ptState playerNextState;
	byte resetExclusivity = false;
	ptStackElt playerElt = top(*playerStack);
	ptStackElt opponentElt = top(*opponentStack);
	ptState opponentState = opponentElt->state;
	ptList E;
play:
	if(!playerElt->E) {
		pop(opponentStack);
		stateDestroy(opponentElt->state, true);
		opponentElt->state = NULL;
		destroyStackElement(opponentElt, stutterStep ? directTrans : processTrans);
		playerElt->E = playerElt->E_save;
	}
	else {
		playerNextState = stutterStep ? stateDuplicate(((ptDirectTransition) playerElt->E->value)->target) : apply(playerSymTab, playerMtypes, playerElt->state, (ptProcessTransition) playerElt->E->value, 1, NULL);
		ptBoolFct transFeatures = stutterStep ? ((ptDirectTransition) playerElt->E->value)->features : ((ptProcessTransition) playerElt->E->value)->features;
		destroyBool(playerNextState->features);
		playerNextState->features = NULL;
#ifdef CLOCK
		ptClockZone transGuard = ((ptProcessTransition) playerElt->E->value)->guard;
		zoneDestroy(playerNextState->zone);
		playerNextState->zone = NULL;
#endif
		resetExclusivity = false;
		if(stutterStep)
			E = executablesNonStutter(playerProps, playerSymTab, playerMtypes, playerNextState, 0, 0, NULL, NULL, NULL, NULL);
		else
			E = executables(playerSymTab, playerMtypes, playerNextState, 0, 0, NULL, NULL, NULL, NULL, &resetExclusivity);
		if(resetExclusivity) {
			stateSetValue(playerNextState->payload, OFFSET_EXCLUSIVE, T_BYTE, NO_PROCESS);
		}
		playerNextState->payloadHash = hashState(playerNextState);

		playerElt->E = playerElt->E->next;
		if(*turn == duplicator && !checkEqualProps(playerProps, playerSymTab, playerMtypes, playerNextState, opponentProps, opponentSymTab, opponentMtypes, opponentState)) {
			stateDestroy(playerNextState, false);
			if(stutterStep)
				destroyProcTransList(E, directTrans);
			else
				destroyProcTransList(E, processTrans);
			E = NULL;
			goto play;
		}
		visited = *turn == spoiler ? simSearch(table, playerNextState, opponentState, duplicator) : simSearch(table, opponentState, playerNextState, spoiler);
		if(visited) {
#ifdef CLOCK
			ptSimHtTrans shsTrans = createSimHtTrans(currentShs, visited, transFeatures, transGuard);
#else
			ptSimHtTrans shsTrans = createSimHtTrans(currentShs, visited, transFeatures);
#endif
			currentShs->succ = listAdd(currentShs->succ, shsTrans);
			visited->pred = listAdd(visited->pred, shsTrans);
			stateDestroy(playerNextState, false);
			if(stutterStep)
				destroyProcTransList(E, directTrans);
			else
				destroyProcTransList(E, processTrans);
			E = NULL;
			goto play;
		}
		else {
			_count++;
			if(*turn == spoiler)
				new = createSimHtState(playerNextState, opponentState, duplicator);
			else
				new = createSimHtState(opponentState, playerNextState, spoiler);
#ifdef CLOCK
			ptSimHtTrans shsTrans = createSimHtTrans(currentShs, new, transFeatures, transGuard);
#else
			ptSimHtTrans shsTrans = createSimHtTrans(currentShs, new, transFeatures);
#endif
			currentShs->succ = listAdd(currentShs->succ, shsTrans);
			new->pred = listAdd(new->pred, shsTrans);
			htInsert(table, playerNextState->payloadHash + opponentState->payloadHash, new);
			ptStackElt playerNextElt = createStackElement(playerNextState, 0);
			resetExclusivity = false;
			playerNextElt->E = E;
			playerNextElt->E_save = playerNextElt->E;
			*playerStack = push(*playerStack, playerNextElt);
		}
	}
	*turn = *turn == spoiler ? duplicator : spoiler;
}

void computeGameGraph(void * table, ptList props, ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptStack stack, ptList props2, ptSymTabNode globalSymTab2, ptMTypeNode mtypes2, ptStack stack2) {
	ptStackElt current = NULL, current2 = NULL;
	ptSimHtState currentShs = NULL;
	byte turn = 0; // Spoiler's turn
	while(!empty(stack) && !empty(stack2)) {
		current = top(stack);
		current2 = top(stack2);
		currentShs = simSearch(table, current->state, current2->state, turn);
		if(!currentShs)
			failure("[simulation] State on stack not registered in Hashtable.\n");
		if(turn == spoiler)
			computeNextState(table, props, globalSymTab, mtypes, &stack, props2, globalSymTab2, mtypes2, &stack2, &turn, currentShs);
		else
			computeNextState(table, props2, globalSymTab2, mtypes2, &stack2, props, globalSymTab, mtypes, &stack, &turn, currentShs);
	}
	current = top(stack);
	stateDestroy(current->state, true);
	current->state = NULL;
	destroyStackElement(current, stutterStep ? directTrans : processTrans);
	pop(&stack);
}

void propagate(ptSimHtState shs, byte player) {
	ptStack stack = push(NULL, shs);
	_removed++;
	while(!empty(stack)) {
		ptSimHtState current = top(stack);
		pop(&stack);
		//printf("pop\n");
		ptList tmp = current->pred;
		while(tmp) {
			ptSimHtTrans predTrans = (ptSimHtTrans) tmp->value;
			tmp = tmp->next;
			ptSimHtState pred = predTrans->source;
			//pred->succ = listRemove(pred->succ, predTrans);
			//current->pred = listRemove(current->pred, predTrans);
			if(pred->turn == duplicator) {
				if(listCount(pred->succ) == 0) {
#ifdef CLOCK
					pred->fed = NULL;
#else
					pred->features = negateBool(getTrue());
#endif
					stack = push(stack, pred);
				}
				else {
					ptList tmp2 = pred->succ;
					ptBoolFct acc = negateBool(getTrue());
					while(tmp2) {
						ptSimHtTrans trans = (ptSimHtTrans) tmp2->value;
#ifdef CLOCK
#else
						acc = trans->features ? addDisjunction(acc, addConjunction(trans->features, trans->target->features, 1, 1), 0, 0) : addDisjunction(acc, trans->target->features, 0, 1);
#endif
						tmp2 = tmp2->next;
					}
#ifdef CLOCK
#else
					if(!equalsWrtFD(pred->features, acc)) {
						stack = push(stack, pred);
						destroyBool(pred->features);
						pred->features = acc;
						/*printf("Pushing duplicator: ");
						printBool(pred->features);
						printf("\n");*/
					}
					else
						destroyBool(acc);
#endif
				}
			}
			else { // pred->turn == spoiler
				ptList tmp2 = pred->succ;
				ptBoolFct acc = getTrue();
				while(tmp2) {
					ptSimHtTrans trans = (ptSimHtTrans) tmp2->value;
#ifdef CLOCK
#else
					acc = trans->features ? addConjunction(acc, addDisjunction(negateBool(trans->features), trans->target->features, 0, 1), 0, 0) : addConjunction(acc, trans->target->features, 0, 1);
#endif
					tmp2 = tmp2->next;
				}
#ifdef CLOCK
#else
				if(!equalsWrtFD(pred->features, acc)) {
					destroyBool(pred->features);
					pred->features = acc;
					stack = push(stack, pred);
				}
				else
					destroyBool(acc);
#endif
			}
		}
	}
}

void removeWinningStates(void * table, ptSimHtState initSimHtState) {
	ptStack stack = push(NULL, initSimHtState);
	htRemove(table, initSimHtState->h1 + initSimHtState->h2, initSimHtState);
	while(!empty(stack)) {
		ptSimHtState current = top(stack);
		ptList tmp = current->succ;
		byte found = 0;
		while(tmp) {
			ptSimHtState succ = ((ptSimHtTrans) tmp->value)->target;
			if(htFind(table, succ->h1+succ->h2, succ)) {
				stack = push(stack, succ);
				htRemove(table, succ->h1 + succ->h2, succ);
				found = 1;
			}
			tmp = tmp->next;
		}
		if(!found) {
			pop(&stack);
			// accumulate features // if different than ->features, propagate
			if(current->turn == duplicator) {
				if(!current->succ) {
#ifdef CLOCK
#else
					destroyBool(current->features);
					current->features = negateBool(getTrue());
#endif
					propagate(current, spoiler);
				}
				else {
					tmp = current->succ;
					ptBoolFct acc = negateBool(getTrue());
					while(tmp) {
						ptSimHtTrans trans = (ptSimHtTrans) tmp->value;
#ifdef CLOCK
#else
						acc = trans->features ? addDisjunction(acc, addConjunction(trans->features, trans->target->features, 1, 1), 0, 0) : addDisjunction(acc, trans->target->features, 0, 1);
#endif
						tmp = tmp->next;
					}
#ifdef CLOCK
#else
					if(!equalsWrtFD(current->features, acc)) {
						destroyBool(current->features);
						current->features = acc;
						propagate(current, spoiler);
					}
					else
						destroyBool(acc);
#endif
				}
			}
		}
	}
}

