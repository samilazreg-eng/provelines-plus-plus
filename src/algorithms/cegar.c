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
#include "SAT.h"
#ifdef CLOCK
	#include "clockZone.h"
	#include "federation.h"
#endif
#include "state.h"
#include "execution.h"
#include "hashState.h"
#include "hashtableGen.h"
#include "tvl.h"
#include "fdg.h"
#include "checking.h"
#include "cegar.h"

#define DEBUG_CEGAR
#ifdef PROFILE_CEGAR
	PROFILER_REGISTER(pr_createCounterExample, "createCounterExample", 1000);
	PROFILER_REGISTER(pr_replayAndRefine, "Refine", 1000);
#endif

#ifdef CEGAR
ptCE createCounterExample(ptStack trace, ptStack cycle, ptBoolFct features) {
#ifdef PROFILE_CEGAR
	PROFILER_START(pr_createCounterExample);
#endif
	ptCE ce = (ptCE) malloc(sizeof(tCE));
	if(!ce) failure("[automata/cegar] Out of memory (creating counterexample).\n");
	ce->features = copyBool(features);
	ce->trace = NULL;
	ce->cycle = NULL;
	ce->trans = NULL;
	ce->transCycle = NULL;
	ptStack stack_iter = trace;
	while(stack_iter) {
		if(((ptStackElt) stack_iter->value)->trans && ((ptStackElt) stack_iter->value)->trans->origFeatures && !((ptStackElt) stack_iter->value)->trans->features) {
			ce->trace = push(ce->trace, stateDuplicate(((ptStackElt) stack_iter->value)->state));
			ce->trans = push(ce->trans, ((ptStackElt) stack_iter->value)->trans);
		}
		stack_iter = stack_iter->prev;
	}
	stack_iter = cycle;
	while(stack_iter) {
		if(((ptStackElt) stack_iter->value)->trans && ((ptStackElt) stack_iter->value)->trans->origFeatures && !((ptStackElt) stack_iter->value)->trans->features) {
			ce->cycle = push(ce->cycle, stateDuplicate(((ptStackElt) stack_iter->value)->state));
			ce->transCycle = push(ce->transCycle, ((ptStackElt) stack_iter->value)->trans);
		}
		stack_iter = stack_iter->prev;
	}
#ifdef PROFILE_CEGAR
	PROFILER_END(pr_createCounterExample);
#endif
	return ce;
}

ptFsm buildFeatureAbstractFSM(ptFsm fsm) {
#ifdef DEBUG_CEGAR
		printf("Building abstraction for proctype %p\n", fsm);
#endif
	if(!fsm) failure("[automata/cegar] fsm is NULL.\n");
	ptHashtable table = createHashtable();

	ptFsm abs = createFsm();
	abs->symTab = fsm->symTab;
	ptFsmNode absInit = copyFsmNode(abs, fsm->init);
	abs->init = absInit;

	ptStack stackFsm = push(NULL, fsm->init);
	ptStack stackAbs = push(NULL, abs->init);
	while(stackFsm && stackAbs) {
		ptFsmNode currentFsm = pop(&stackFsm);
		ptFsmNode currentAbs = pop(&stackAbs);

		htInsert(table, (int)currentFsm, currentAbs);
#ifdef DEBUG_CEGAR
		printf("\tInserting node %p at key %d\n", currentFsm, currentFsm->lineNb);
#endif
		ptList trans_iter = currentFsm->trans;
		while(trans_iter) {
			ptFsmTrans transFsm = (ptFsmTrans) trans_iter->value;
			ptFsmTrans transAbs = copyFsmTrans(abs, currentAbs, transFsm);

			destroyBool(transAbs->features);
			transAbs->features = NULL;

			ptFsmNode targetAbs = NULL;
			ptList prev = htSearch(table, (int)transFsm->target);
			if(!prev) {
#ifdef DEBUG_CEGAR
				printf("\t\tNew node %p with key %d\n", transFsm->target, transFsm->target->lineNb);
#endif
				targetAbs = copyFsmNode(abs, transFsm->target);
				stackFsm = push(stackFsm, transFsm->target);
				stackAbs = push(stackAbs, targetAbs);
			}
			else {
#ifdef DEBUG_CEGAR
				printf("\t\tOld node %p with key %d\n", transFsm->target, transFsm->target->lineNb);
#endif
				targetAbs = (ptFsmNode) prev->value;
			}
			transAbs->target = targetAbs;
			targetAbs->trans_in = listAdd(targetAbs->trans_in, transAbs);
			trans_iter = trans_iter->next;
		}
	}
	return abs;
}

ptSymTabNode buildInitialAbstraction(ptSymTabNode globalSymTab) {
/*	ptSymTabNode node_iter = globalSymTab;
	while(node_iter) {
		if(node_iter->type == T_PROC) {
			node_iter->fsm = buildFeatureAbstractFSM(node_iter->orig);
		}
		node_iter = node_iter->next;
	}
	return globalSymTab;*/
}

ptBoolFct replayAndRefine(ptSymTabNode globalSymTab, ptCE ce, byte * refined) {
	if(!ce)
		return getTrue();
#ifdef PROFILE_CEGAR
	PROFILER_START(pr_replayAndRefine);
#endif
#ifdef DEBUG_CEGAR
	//printf("\t[Replay and refine]\n");
#endif
	ptState currentState;
	ptFsmTrans currentTrans;
	ptBoolFct badProducts = ce->features;
	byte issat = isSatisfiable(badProducts);
	while(ce->trace && ce->trans && issat) {
		currentState = (ptState) pop(&(ce->trace));
		currentTrans = (ptFsmTrans) pop(&(ce->trans));
		if(currentTrans) {
			if(currentTrans->origFeatures) {
				currentTrans->features = currentTrans->origFeatures;
				badProducts = addConjunction(badProducts, currentTrans->origFeatures, 0, 1);
				if(refined) *refined = true;
				//printf("\t\tRefined! Added feature: ");
				//printBool(currentTrans->origFeatures);
				//printf("\n");
				issat = isSatisfiable(badProducts);
				ptFsmNode source = currentTrans->source;
				if(source) {
					ptList trans_iter = source->trans;
					while(trans_iter) {
						ptFsmTrans sourceTrans = (ptFsmTrans) trans_iter->value;
						if (sourceTrans->origFeatures && !sourceTrans->features) {
							sourceTrans->features = sourceTrans->origFeatures;
						}
						trans_iter = trans_iter->next;
					}
				}
			}
		}
		stateDestroy(currentState, 0);
	}
	if(!issat) {
		while(ce->trace && ce->trans) {
			currentState = (ptState) pop(&(ce->trace));
			stateDestroy(currentState, 0);
			pop(&(ce->trans));
		}
	}
	while(ce->cycle && ce->transCycle && issat) {
		currentState = (ptState) pop(&(ce->cycle));
		currentTrans = (ptFsmTrans) pop(&(ce->transCycle));
		if(currentTrans) {
			if(currentTrans->origFeatures) {
				currentTrans->features = currentTrans->origFeatures;
				badProducts = addConjunction(badProducts, currentTrans->origFeatures, 0, 1);
				if(refined) *refined = true;
				//printf("Refined! Added feature: ");
				//printBool(currentTrans->origFeatures);
				//printf("\n");
				issat = isSatisfiable(badProducts);
				ptFsmNode source = currentTrans->source;
				if(source) {
					ptList trans_iter = source->trans;
					while(trans_iter) {
						ptFsmTrans sourceTrans = (ptFsmTrans) trans_iter->value;
						if (sourceTrans->origFeatures && !sourceTrans->features) {
							sourceTrans->features = sourceTrans->origFeatures;
						}
						trans_iter = trans_iter->next;
					}
				}
			}
		}
		stateDestroy(currentState, 0);
	}
	if(!issat) {
		while(ce->cycle && ce->transCycle) {
			currentState = (ptState) pop(&(ce->cycle));
			stateDestroy(currentState, 0);
			pop(&(ce->transCycle));
		}
	}
#ifdef PROFILE_CEGAR
	PROFILER_END(pr_replayAndRefine);
#endif
	printf("\t\tReal bad products are: ");
	printBool(badProducts);
	printf("\n");
	return badProducts;
}

void cegar(ptSymTabNode globalSymTab, ptMTypeNode mtypes, byte procedure) {
	int _explored = 0, _reexplored = 0;
	//ptSymTabNode abstractSymtab = buildInitialAbstraction(globalSymTab);
	//printSymTab(globalSymTab, 0, "Global");
	//printMTypes(mtypes);
	ptSymTabNode abstractSymtab = globalSymTab;
	ptBoolFct badProducts = getFalse();
	byte refined = true;
	ptList ces;
	if(procedure == EXPLORE)
		ces = startExploration(abstractSymtab, mtypes, badProducts, &_explored, &_reexplored);
	else
		ces = startNestedDFS(abstractSymtab, mtypes, badProducts, &_explored, &_reexplored);
	while(refined && ces) {
		ptList ces_iter = ces;
		int i = 0;
		refined = false;
		while(ces_iter) {
			badProducts = addDisjunction(badProducts, replayAndRefine(abstractSymtab, (ptCE) ces_iter->value, &refined), 0, 0);
			ces_iter = ces_iter->next;
		}
		if(ces && refined) {
			// destroy ces
			//printSymTab(globalSymTab,0, "Global");
			//printf("badProducts = ");
			//printBool(badProducts);
			//printf("\n");
			if(procedure == EXPLORE)
				ces = startExploration(abstractSymtab, mtypes, badProducts, &_explored, &_reexplored);
			else
				ces = startNestedDFS(abstractSymtab, mtypes, badProducts, &_explored, &_reexplored);
		}
	}
#ifdef PROFILER
	PROFILER_REPORT(pr_createCounterExample);
	PROFILER_REPORT(pr_replayAndRefine);
#endif
	if(!isSatisfiable(badProducts)) {
		printf("No assertion violations or deadlocks found [explored %d states, re-explored %d states]\n", _explored, _reexplored);
		exit(EXIT_SUCCESS);
	}
	else {
		printf("Property violated by the following products [explored %d states, re-explored %d states] : \n", _explored, _reexplored);
		if(isTautology(badProducts))
			printf("All the products.\n");
		else {
			printBool(badProducts);
			printf("\n");
		}
		exit(EXIT_FOUND_PROBLEM);
	}
}
#endif
