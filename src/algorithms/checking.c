#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include "error.h"
#include "main.h"
#include "list.h"
#include "stack.h"
#include "boolFct.h"
#include "symbols.h"
#include "costFormula.h"
#include "automata.h"
#include "SAT.h"
#include "state.h"
#include "execution.h"
#include "hashState.h"
#include "hashtableState.h"
#include "tvl.h"
#include "fdg.h"
#include "checking.h"
#include "cegar.h"

PROFILER_REGISTER(pr_optimisation, "optimisation", 1000);

PROFILER_USE(pr_isSatisfiableWrtFD);
PROFILER_USE(pr_isSatisfiableWrtBaseFD);
PROFILER_USE(pr_isSatisfiable);
PROFILER_USE(pr_implies);
PROFILER_USE(pr_impliesWrtFD);
PROFILER_USE(pr_impliesWrtBaseFD);
PROFILER_USE(pr_executables);
PROFILER_USE(pr_apply);
PROFILER_USE(pr_eval);

/*
 * The following algorithms perform a nested depth first search.
 * They allow to check both safety and liveness properties.
 * A never claim (corresponding to an LTL formula) must have been declared for the model checker to work.
 */

// Statistics gathered during executions
static 		unsigned int _nbErrors = 0;				// Total number of encountered problems
static long unsigned int _nbStatesExplored = 1;		// Total of distinct states (without features) explored
static long unsigned int _nbStatesReExplored = 0;	// Total of states that had to be re-explored because new products were found to be able to reach them
static long unsigned int _nbStatesStops = 0;		// Total of states where exploration backtracked because they were already visited before
static long unsigned int _nbStatesExploredInner = 0;// As before, but for inner search.
static long unsigned int _nbStatesReExploredInner = 0;//As before, but for inner search.
static long unsigned int _nbStatesStopsInner = 0;	// As before, but for inner search.
static long unsigned int _depth = 0;				// Current exploration depth (inner and outer)

//#define DEBUG_PRINT(msg) printf(msg);
//#define DEBUG_PRINT_d(msg, d) printf(msg, d);
//#define DEBUG_PRINT_s(msg, s) printf(msg, s);
#define DEBUG_PRINT(msg)
#define DEBUG_PRINT_d(msg, d)
#define DEBUG_PRINT_s(msg, s)

/*#define TIME_REPORT \
		printf("#(Sat) : %lu\n",satCalls); \
		printf("T(Sat) : %lu\n",satTime); \
		printf("#(Boo) : %lu\n",junCalls); \
		printf("T(Boo) : %lu\n",junTime);*/

// These stats are printed regularly
#define STATS if(((_nbStatesExplored + _nbStatesReExplored) % 10000) == 0)	\
				printf(	"Explored %10lu, "												 	\
						"re-explored %10lu, "												\
						"backtracked %10lu, "												\
						"depth % 7ld, "														\
						"buckets %10lu, "													\
						"mean bucket size % 5.2Lf"  										\
						"\n",						 										\
					_nbStatesExplored,				  										\
					_nbStatesReExplored, 													\
					_nbStatesStops,															\
					_depth, 																\
					htVisitedStatesNbFilledBuckets,											\
					(long double) htVisitedStatesNbRecords / (long double) htVisitedStatesNbFilledBuckets);

// Macro used when an error is encountered (always the same stuff that's printed)
#define STOP_ERROR(msg, features, stackOuter, stackInner, loopStart) {						\
			_nbErrors++;																	\
			printf("%s", msg);																\
			printf(" [explored %lu states, re-explored %lu].\n",							\
					_nbStatesExplored, _nbStatesReExplored); 								\
			if(!_allProductsFail) {															\
				if(features) {																\
					_failProducts = addDisjunction(_failProducts, features, 0, 1);			\
					_allProductsFail = !addConstraintToFD(negateBool(features));			\
				} else {	 																\
					destroyBool(_failProducts);												\
					_failProducts = NULL;													\
				} 																			\
			}																				\
			if(!_failProducts) _allProductsFail = 1;										\
			if(features) {																	\
				printf(" - Products by which it is violated (as feature expression):\n   ");\
				printBool(features);														\
				printf("\n");																\
			} else {																		\
				printf(" - Violated by all products.\n");									\
			}																				\
			if(trace != NO_TRACE) {															\
				printf("\n - Stack trace:\n");												\
				printStackElementStack(globalSymTab, mtypes, stackOuter, loopStart, NULL);						\
				if(stackInner) printStackElementStack(globalSymTab, mtypes, stackInner, NULL, top(stackOuter));	\
			}																				\
			if(!exhaustive) { 																\
				PROFILER_REPORT(pr_optimisation);											\
				PROFILER_REPORT(pr_executables);											\
				PROFILER_REPORT(pr_apply);													\
				PROFILER_REPORT(pr_eval);													\
				PROFILER_REPORT(pr_isSatisfiable);											\
				PROFILER_REPORT(pr_isSatisfiableWrtFD); 									\
				PROFILER_REPORT(pr_isSatisfiableWrtBaseFD); 								\
				PROFILER_REPORT(pr_implies); 												\
				PROFILER_REPORT(pr_impliesWrtFD); 											\
				PROFILER_REPORT(pr_impliesWrtBaseFD); 										\
				exit(EXIT_FOUND_PROBLEM);													\
			}																				\
			if(trace != NO_TRACE) printf("\n\n ****\n");									\
			printf("\n");																	\
		}

#define STOP_ERROR_GLOBAL {																	\
			printf("\n");																	\
			printf("Exhaustive search finished ");											\
			printf(" [explored %lu states, re-explored %lu].\n",							\
					_nbStatesExplored, _nbStatesReExplored); 								\
			if(_nbErrors == 1) printf(" -  One problem found");								\
			else printf(" - %u problems were found", _nbErrors);							\
			if(_allProductsFail || isTautology(_failProducts)) 								\
				printf(" covering every product.\n");										\
			else {																			\
				printf(" covering the following products (others are ok):\n");				\
				printBool(_failProducts);													\
				printf("\n");																\
			}																				\
			printf("\n");																	\
			if(!keepTempFiles) {															\
				remove("__workingfile.tmp");												\
				remove("__workingfile.tmp.cpp");											\
			}																				\
			PROFILER_REPORT(pr_optimisation);												\
			PROFILER_REPORT(pr_executables);												\
			PROFILER_REPORT(pr_apply);														\
			PROFILER_REPORT(pr_eval);														\
			PROFILER_REPORT(pr_isSatisfiable);												\
			PROFILER_REPORT(pr_isSatisfiableWrtFD); 										\
			PROFILER_REPORT(pr_isSatisfiableWrtBaseFD); 									\
			PROFILER_REPORT(pr_implies); 													\
			PROFILER_REPORT(pr_impliesWrtFD); 												\
			PROFILER_REPORT(pr_impliesWrtBaseFD); 											\
			exit(EXIT_FOUND_PROBLEM);														\
		}


#define STOP_ERROR_NOPRINT(msg, features) {													\
			_nbErrors++;																	\
			printf("%s", msg);																\
			printf(" [explored %lu states, re-explored %lu].\n",							\
					_nbStatesExplored, _nbStatesReExplored); 								\
			if(!_allProductsFail) {															\
				if(features) {																\
					_failProducts = addDisjunction(_failProducts, features, 0, 1);			\
					_allProductsFail = !addConstraintToFD(negateBool(features));			\
				} else {	 																\
					destroyBool(_failProducts);												\
					_failProducts = NULL;													\
				} 																			\
			}																				\
			if(!_failProducts) _allProductsFail = 1;										\
			if(features) {																	\
				printf(" - Products by which it is violated (as feature expression):\n   ");\
				printBool(features);														\
				printf("\n");																\
			} else {																		\
				printf(" - Violated by all products.\n");									\
			}																				\
			if(!exhaustive) { 																\
				PROFILER_REPORT(pr_optimisation);											\
				PROFILER_REPORT(pr_executables);											\
				PROFILER_REPORT(pr_apply);													\
				PROFILER_REPORT(pr_eval);													\
				PROFILER_REPORT(pr_isSatisfiable);											\
				PROFILER_REPORT(pr_isSatisfiableWrtFD); 									\
				PROFILER_REPORT(pr_isSatisfiableWrtBaseFD); 								\
				PROFILER_REPORT(pr_implies); 												\
				PROFILER_REPORT(pr_impliesWrtFD); 											\
				PROFILER_REPORT(pr_impliesWrtBaseFD); 										\
				exit(EXIT_FOUND_PROBLEM);													\
			}																				\
			if(trace != NO_TRACE) printf("\n\n ****\n");									\
			printf("\n");																	\
		}


#define EXPLORATION_LIMIT(error) 															\
			if(limitExploration && _nbStatesExplored >= limitExploration) {					\
				printf("Reached exploration limit ");										\
				printf(" [explored %lu states, re-explored %lu].\n",						\
						limitExploration, _nbStatesReExplored);								\
				if(!keepTempFiles) {														\
					remove("__workingfile.tmp");											\
					remove("__workingfile.tmp.cpp");										\
				}																			\
				if(!error) {																\
					printf("So far, no problems were found.\n");							\
					exit(EXIT_REACHED_EXPLORATION_LIMIT);									\
				} else {																	\
					printf("So far, %u problem(s) were found covering the following products:\n", _nbErrors);	\
					printBool(_failProducts);												\
					printf("\n");															\
					exit(EXIT_FOUND_PROBLEM);												\
				}																			\
			}

#define STOP_NOERROR(msg) {																	\
			printf(msg);																	\
			printf(" [explored %lu states, re-explored %lu].\n",							\
					_nbStatesExplored, _nbStatesReExplored); 								\
			if(_nbStatesExploredInner != 0) 			 									\
				printf("The inner search explored %lu states and re-explored %lu.\n",		\
						_nbStatesExploredInner, _nbStatesReExploredInner); 					\
			if(!keepTempFiles) {															\
				remove("__workingfile.tmp");												\
				remove("__workingfile.tmp.cpp");											\
			}																				\
			PROFILER_REPORT(pr_optimisation);												\
			PROFILER_REPORT(pr_executables);												\
			PROFILER_REPORT(pr_apply);														\
			PROFILER_REPORT(pr_eval);														\
			PROFILER_REPORT(pr_isSatisfiable);												\
			PROFILER_REPORT(pr_isSatisfiableWrtFD); 										\
			PROFILER_REPORT(pr_isSatisfiableWrtBaseFD); 									\
			PROFILER_REPORT(pr_implies); 													\
			PROFILER_REPORT(pr_impliesWrtFD); 												\
			PROFILER_REPORT(pr_impliesWrtBaseFD); 											\
			exit(EXIT_SUCCESS);																\
		}


// For exhaustive search we keep a boolean expression that records all products known to violate
// the property.  This is used to prevent exploration of a path that belongs to products that
// are known to violate the property (and hence, nothing new can be learned on the path).
static ptBoolFct _failProducts = NULL; // boolean function; NULL means no violations yet
static byte _allProductsFail = 0; // = 1 if all of the products violate the property.
static ptBoolFct _successProducts = NULL;


int smallestDelay(ptList l) {
    int result = INT_MAX;
    
    ptList current = l;
    while (current) {
        ptProcessTransition trans = (ptProcessTransition) (current->value);
        if (trans->delay < result) {
            result = trans->delay;
        }
        current = current->next;
    }
    
    return result;
}

/*void updateDelays(ptList newTs, ptList prevTs, int timeElapsed) {
    ptList currentNew = newTs;
    
    //printf("Updating delays (time elapsed = %d)\n", timeElapsed);
    
    while (currentNew) {
        ptProcessTransition newT = (ptProcessTransition) currentNew->value;
        ptList currentPrev = prevTs;
        while (currentPrev) {
            ptProcessTransition prevT = (ptProcessTransition) currentPrev->value;
            
            if (newT->trans == prevT->trans) {
                //printf("Delay of transition TL%03d changed from %d to %d\n", newT->trans->lineNb, newT->delay, prevT->delay - timeElapsed);
                newT->delay = prevT->delay - timeElapsed;
                currentPrev = NULL;
            } else {
                currentPrev = currentPrev->next;
            }
            
        }
        currentNew = currentNew->next;
    }
}*/

void updateDelays(ptList newTs, int timeElapsed) {
    ptList currentNew = newTs;
    
    //printf("[checking] Updating delays (time elapsed = %d)\n", timeElapsed);
    
    while (currentNew) {
        ptProcessTransition newT = (ptProcessTransition) currentNew->value;
        //printf("\t [checking] Delay of transition TL%03d changed from %d to %d\n", newT->trans->lineNb, newT->delay, newT->delay - timeElapsed);
        newT->delay = newT->delay - timeElapsed;
        currentNew = currentNew->next;
    }
}

ptList sampleTransition(ptList newTs) {
    ptList result = NULL;
    
    int size = listCount(newTs);
    
    if (size > 0) {
        int rng = rand() % size;
        
        ptList current = newTs;
        while (current && !result) {
            if (rng == 0) {
                result = listAdd(result, copyProcessTransition(current->value));
            }
            rng--;
            current = current->next;
        }
    }
    
    return result;
}

// Simple exploration
void startSamplingExploration(int samples, ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptCostFormula property) {
    
    int optimalScoreGlobal = INT_MAX;
    srand(time(NULL));
    
    int _totalStatesExplored = 0;
    
    for(int i = 0; i < samples; i++) {
        
        _successProducts = getFalse();
        
        //for(int j = 0; j < 50; j++) {
            
            int optimalScore = INT_MAX;
            _nbStatesExplored = 0;
            _nbStatesReExplored = 0;
            
            // Initialise
            initSolverWithFD(getFeatureModelClauses());
            
            _failProducts = getFalse();
            _allProductsFail = 0;
            
            if (isSatisfiableWrtFD(_successProducts)) {
                addConstraintToFD(_successProducts);
            }
            
            htVisitedStatesInit();
            
            
            //printf("Starting explore (sampling).\n");
            
            // Create initial state
            ptState init = stateCreateInitial(globalSymTab, mtypes);
            init->payloadHash = hashState(init);
            htVisitedStatesInsert(init->payloadHash, init, DFS_OUTER);
            
            ptBoolFct noOutgoing = NULL;
            byte resetExclusivity = false;
            ptStackElt elt = createStackElement(init, _nbErrors);
            ptStack stack = push(NULL, elt);
            elt->E = executables(globalSymTab, mtypes, init, 1, _nbErrors, NULL, NULL, NULL, &noOutgoing, &resetExclusivity, NULL, 0);
            elt->E_save = elt->E;
            
            // Here we do the sampling
            elt->E = sampleTransition(elt->E);
            destroyProcTransList(elt->E_save, processTrans);
            elt->E_save = elt->E;
            
            // time
            elt->smallestDelay = smallestDelay(elt->E);
            
            if(!elt->E) STOP_ERROR("Initial state has no outgoing transition", NULL, stack, NULL, NULL);
            if(fullDeadlockCheck && noOutgoing) {
                if(isSatisfiableWrtBaseFD(noOutgoing)) STOP_ERROR("Found trivially invalid end state; the following set of products can reach the state, but has no outgoing transition.", noOutgoing, stack, NULL, NULL);
                destroyBool(noOutgoing);
                noOutgoing = NULL;
            }
            //printState(mtypes, init, NULL);
            
            if (samplingExplore(globalSymTab, mtypes, stack, property, &optimalScore) == 0) {
                if (optimalScoreGlobal > optimalScore) {
                    optimalScoreGlobal = optimalScore;
                }
                _totalStatesExplored += _nbStatesExplored;
            }
        //}
        //printf("Best score of the product: %d\n", optimalScoreGlobal);
    }
    printf("Optimal cost is: %d\n", optimalScoreGlobal);
    printf("[explored: %d]\n", _totalStatesExplored);
}

/**
 * Returns false if no assert violations or deadlocks were found.
 */
byte samplingExplore(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptStack stackOuter, ptCostFormula property, int * optimalScore) {
    ptStackElt current, new;
    ptFsmNode neverNode;
    ptState s_;
    ptHtState prevS_;
    ptBoolFct noOutgoing = NULL;
    
    byte resetExclusivity = false;
    
    // Set if an error was found
    byte error = 0;
    byte assertViolation = 0;
    byte hasDeadlock = 0;
    
    // time
    int optimalCost = INT_MAX;
    
    // Execution continues as long as the
    //  - stack is not empty
    //  - no error was found (except in the exhaustive case)
    //  - not all products are known to fail already
    while(!empty(stackOuter) && (!error || exhaustive) && !_allProductsFail) {
        EXPLORATION_LIMIT(error);
        
        current = top(stackOuter);
        
        //printState(mtypes, current->state, NULL);
        
        DEBUG_PRINT_d(" - exploring, state: %u", current->state->payloadHash);
        DEBUG_PRINT_d(", explored %lu", _nbStatesExplored);
        DEBUG_PRINT_d(", depth %lu\n", _depth);
        
        // If the current features are contained in the set of products known to violate the
        // property, then we do not have to go beyond the state
        
        if(current->nbErrors < _nbErrors && !isSatisfiableWrtFD(current->state->features)) {
            DEBUG_PRINT("    +-> is known to violate, backtrack.\n");
            pop(&stackOuter);
            destroyStackElement(current, processTrans);
            _depth--;
            
            // Otherwise, the state can be explored (or exploration continue)
        } else {
            DEBUG_PRINT("    +-> exploring...\n");
            current->nbErrors = _nbErrors;
            
            int stateCost = costFunction(current->state->time, current->state->cost, current->state->qualityLoss);
            
            if (optim) {
                if (stateCost > optimalCost) {
                    //printf("    +-> worse time than optimal, backtrack.\n");
                    _allProductsFail = !addConstraintToFD(negateBool(current->state->features));
                    pop(&stackOuter);
                    destroyStackElement(current, processTrans);
                    _depth--;
                    current = NULL;
                }
            }
            
            if (current && property) {
                if (current->state->time <= property->within && current->state->cost <= property->maxCost && current->state->qualityLoss <= property->maxQualityLoss) {
                    if (eval(globalSymTab, mtypes, (ptState) current->state, ((ptState) current->state)->mask, property->property, EVAL_EXECUTABILITY, NULL)) {
                        printf("    +-> found satisfying state (%u with time = %d, cost = %d, qualityLoss = %d, cost function = %d), backtrack.\n", current->state->payloadHash, current->state->time, current->state->cost, current->state->qualityLoss, stateCost);
                        
                        if (optim) {
                            if (stateCost == optimalCost) {
                                _allProductsFail = !addConstraintToFD(negateBool(current->state->features));
                                _successProducts = addDisjunction(_successProducts, current->state->features, 0, 1);
                            } else if (stateCost < optimalCost) {
                                //reinitSolverWithFD();
                                _allProductsFail = !addConstraintToFD(negateBool(current->state->features));
                                _successProducts = addDisjunction(_successProducts, current->state->features, 0, 1);
                                optimalCost = stateCost;
                            } else {
                                failure("Should never get here");
                            }
                            
                        } else {
                            _allProductsFail = !addConstraintToFD(negateBool(current->state->features));
                            _successProducts = addDisjunction(_successProducts, current->state->features, 0, 1);
                        }
                        pop(&stackOuter);
                        destroyStackElement(current, processTrans);
                        _depth--;
                        current = NULL;
                        
                        /*printf("Products satisfying without problems: ");
                        printBool(addConjunction(_successProducts, negateBool(_failProducts), 1, 0));
                        printf("\n");*/
                        break;
                    }
                } else {
                    printf("    +-> time or cost or quality loss exceeded, backtrack.\n");
                    _allProductsFail = !addConstraintToFD(negateBool(current->state->features));
                    pop(&stackOuter);
                    destroyStackElement(current, processTrans);
                    _depth--;
                    current = NULL;
                    break;
                }
            }
            
            if (current) {
                
                // time
                while(current->E && ((ptProcessTransition) current->E->value)->delay > current->smallestDelay) {
                    current->E = current->E->next;
                }
                
                if(!current->E) {
                    DEBUG_PRINT("    +-> all transitions of state fired, backtracking...\n");
                    pop(&stackOuter);
                    destroyStackElement(current, processTrans);
                    _depth--;
                    
                } else {
                    if (((ptProcessTransition) current->E->value)->trans) {
                        s_ = apply(globalSymTab, mtypes, current->state, (ptProcessTransition) current->E->value, 1, &assertViolation);
                        s_->payloadHash = hashState(s_);
                        
                        DEBUG_PRINT_d(" got %u\n", s_->payloadHash);
                        if(assertViolation) {
                            char msg[40];
                            sprintf(msg, "Assertion at line %d violated", ((ptProcessTransition) current->E->value)->trans->lineNb);
                            STOP_ERROR(msg, s_->features, stackOuter, NULL, NULL);
                            error = 1;
                            stateDestroy(s_, false);
                            s_ = NULL;
                            
                        } else {
                            ptList previous = NULL;
                            new = NULL;
                            resetExclusivity = false;
                            if(!htVisitedStatesFindList(s_->payloadHash, s_, DFS_OUTER, &previous)) {
                                new = createStackElement(s_, _nbErrors);
                                
                                // time
                                ptList e;
                                if (current->onHold) {
                                    e = current->onHold;
                                    while(e) {
                                        if (((ptProcessTransition) e->value)->trans != ((ptProcessTransition) current->E->value)->trans) {
                                            new->onHold = listAdd(new->onHold, copyProcessTransition(e->value));
                                        }
                                        e = e->next;
                                    }
                                }
                                
                                if (((ptProcessTransition) current->E->value)->delay > 0) {
                                    e = current->E_save;
                                    while(e) {
                                        if (((ptProcessTransition) e->value)->trans != ((ptProcessTransition) current->E->value)->trans) {
                                            new->onHold = listAdd(new->onHold, copyProcessTransition(e->value));
                                        }
                                        e = e->next;
                                    }
                                    updateDelays(new->onHold, s_->time - current->state->time);
                                }
                                
                                new->E = executables(globalSymTab, mtypes, s_, 1, _nbErrors, &hasDeadlock, NULL, NULL, &noOutgoing, &resetExclusivity, new->onHold, s_->time - current->state->time);
                                new->E_save = new->E;
                                
                                // Here we do the sampling
                                new->E = sampleTransition(new->E);
                                destroyProcTransList(new->E_save, processTrans);
                                new->E_save = new->E;
                                
                                // time
                                new->smallestDelay = smallestDelay(new->E_save);
                                
                                if(resetExclusivity) {
                                    stateSetValue(s_->payload, OFFSET_EXCLUSIVE, T_BYTE, NO_PROCESS);
                                    s_->payloadHash = hashState(s_);
                                    DEBUG_PRINT_d("         - lost exclusivity, state became %u\n", s_->payloadHash);
                                    
                                    prevS_ = NULL;
                                    
                                    if(htVisitedStatesFindList(s_->payloadHash, s_, DFS_OUTER, &previous)) {
                                        new->state = NULL;
                                        destroyStackElement(new, processTrans);
                                        new = NULL;
                                    }
                                }
                            }
                            if(!new) {
                                DEBUG_PRINT("         - state already visited.\n");
                                stateDestroy(s_, false);
                                s_ = NULL;
                                _nbStatesStops++;
                                
                            } else {
                                
                                if (previous) {
                                    free(s_->payload);
                                    s_->payload = ((ptHtState) previous->value)->payload;
                                }
                                
                                for (ptList previousIt = previous; previousIt; previousIt = previousIt->next) {
                                    ptHtState prevS_ = (ptHtState) previousIt->value;
                                    
                                    DEBUG_PRINT("         - state visited but fresh, pushing on stack.\n");
                                    
                                    if (prevS_->time == s_->time && prevS_->cost == s_->cost && prevS_->qualityLoss == s_->qualityLoss) { // all costs equal -> merge feature expressions
                                        ptBoolFct negPrev = negateBool(prevS_->outerFeatures);
                                        if(s_->features == NULL) {
                                            destroyBool(prevS_->outerFeatures);
                                            prevS_->outerFeatures = getTrue();
                                        } else {
                                            prevS_->outerFeatures = addDisjunction(prevS_->outerFeatures, s_->features, 0, 1);
                                        }
                                        s_->features = addConjunction(negPrev, s_->features, 0, 0);
                                    } else if (prevS_->time <= s_->time && prevS_->cost <= s_->cost && prevS_->qualityLoss <= s_->qualityLoss) { // reached with all costs higher -> discard the new state except for new products
                                        if (prevS_->outerFeatures == NULL) {
                                            s_->features = getFalse();
                                        } else {
                                            ptBoolFct neg = negateBool(prevS_->outerFeatures);
                                            s_->features = addConjunction(neg, s_->features, 0, 0);
                                        }
                                    } else if (prevS_->time > s_->time && prevS_->cost > s_->cost && prevS_->qualityLoss > s_->qualityLoss) { // reached with all costs better -> discard the previous state except for products that don't reach the new state
                                        if(s_->features == NULL) {
                                            htVisitedStatesRemove(s_->payloadHash, prevS_);
                                            destroyHtState(prevS_);
                                        } else {
                                            ptBoolFct neg = negateBool(s_->features);
                                            prevS_->outerFeatures = addConjunction(neg, prevS_->outerFeatures, 0, 0);
                                            if (!isSatisfiableWrtBaseFD(prevS_->outerFeatures)) {
                                                htVisitedStatesRemove(s_->payloadHash, prevS_);
                                                destroyHtState(prevS_);
                                            }
                                        }
                                    }
                                    _nbStatesReExplored++;
                                    //STATS;
                                }
                                listDestroy(previous);
                                if (isSatisfiableWrtFD(s_->features)) {
                                    DEBUG_PRINT("         - state fresh, pushing on stack.\n");
                                    
#ifdef DEBUGSTATE
                                    printf("Inserting state:\n");
                                    //printState(s_, NULL);
#endif
                                    htVisitedStatesInsert(s_->payloadHash, s_, DFS_OUTER);
                                    _nbStatesExplored++;
                                    //STATS;
                                    
                                    stackOuter = push(stackOuter, new);
                                    _depth++;
                                }
                                
                            } // fresh state
                        } // no assert violation
                    } else {
                        // time: this is where we win
                        failure("Should never reach a final state\n");
                        printf("    +-> final state reached in %d time units\n", current->state->time);
                        printBool(current->state->features);
                        //printState(mtypes, current->state, NULL);
                        printf("");
                        printf("    +-> final state reached, backtracking...\n");
                        
                    } // stutter transition
                    // Next transition
                    current->E = current->E->next;
                    
                } // fire transition
            } //
        } // explore state
    } // end while
    /*printf("Products satisfying the property: ");
    printBool(_successProducts);
    printf("\n");
    printf("Products leading to problems: ");
    printBool(_failProducts);
    printf("\n");*/
    
    if(optim) {
        //printf("Optimal cost is: %d\n", optimalCost);
        if (optimalScore) {
            *optimalScore = optimalCost;
        }
    }
    
    if(error) STOP_ERROR_GLOBAL;
    destroyStackElementStack(stackOuter, processTrans);
    return error;
}


// Simple exploration
void startExploration(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptCostFormula property) {
    // Initialise
    initSolverWithFD(getFeatureModelClauses());
    htVisitedStatesInit();
    _nbStatesExplored = 0;
    _nbStatesReExplored = 0;
    
    printf("Starting explore.\n");
    
    // Create initial state
    ptState init = stateCreateInitial(globalSymTab, mtypes);
    init->payloadHash = hashState(init);
    htVisitedStatesInsert(init->payloadHash, init, DFS_OUTER);
    
    ptBoolFct noOutgoing = NULL;
    byte resetExclusivity = false;
    ptStackElt elt = createStackElement(init, _nbErrors);
    ptStack stack = push(NULL, elt);
    elt->E = executables(globalSymTab, mtypes, init, 1, _nbErrors, NULL, NULL, NULL, &noOutgoing, &resetExclusivity, NULL, 0);
    elt->E_save = elt->E;
    
    // time
    elt->smallestDelay = smallestDelay(elt->E);
    
    if(!elt->E) STOP_ERROR("Initial state has no outgoing transition", NULL, stack, NULL, NULL);
    if(fullDeadlockCheck && noOutgoing) {
        if(isSatisfiableWrtBaseFD(noOutgoing)) STOP_ERROR("Found trivially invalid end state; the following set of products can reach the state, but has no outgoing transition.", noOutgoing, stack, NULL, NULL);
        destroyBool(noOutgoing);
        noOutgoing = NULL;
    }
    _failProducts = getFalse();
    _successProducts = getFalse();
    //printState(mtypes, init, NULL);
    if(explore(globalSymTab, mtypes, stack, property) == 0) STOP_NOERROR("No assertion violations or deadlocks found");
}

/**
 * Returns false if no assert violations or deadlocks were found.
 */
byte explore(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptStack stackOuter, ptCostFormula property) {
    ptStackElt current, new;
    ptFsmNode neverNode;
    ptState s_;
    ptHtState prevS_;
    ptBoolFct noOutgoing = NULL;
    
    byte resetExclusivity = false;
    
    // Set if an error was found
    byte error = 0;
    byte assertViolation = 0;
    byte hasDeadlock = 0;
    
    // time
    int optimalCost = INT_MAX;
    
    // Execution continues as long as the
    //  - stack is not empty
    //  - no error was found (except in the exhaustive case)
    //  - not all products are known to fail already
    while(!empty(stackOuter) && (!error || exhaustive) && !_allProductsFail) {
        EXPLORATION_LIMIT(error);
        
        current = top(stackOuter);
        
        DEBUG_PRINT_d(" - exploring, state: %u", current->state->payloadHash);
        DEBUG_PRINT_d(", explored %lu", _nbStatesExplored);
        DEBUG_PRINT_d(", depth %lu\n", _depth);
        
        // If the current features are contained in the set of products known to violate the
        // property, then we do not have to go beyond the state
        
        if(current->nbErrors < _nbErrors && !isSatisfiableWrtFD(current->state->features)) {
            DEBUG_PRINT("    +-> is known to violate, backtrack.\n");
            pop(&stackOuter);
            destroyStackElement(current, processTrans);
            _depth--;
            
            // Otherwise, the state can be explored (or exploration continue)
        } else {
            DEBUG_PRINT("    +-> exploring...\n");
            current->nbErrors = _nbErrors;
            
            int stateCost = costFunction(current->state->time, current->state->cost, current->state->qualityLoss);
            
            if (optim) {
                if (stateCost > optimalCost) {
                    //printf("    +-> worse time than optimal, backtrack.\n");
                    _allProductsFail = !addConstraintToFD(negateBool(current->state->features));
                    pop(&stackOuter);
                    destroyStackElement(current, processTrans);
                    _depth--;
                    current = NULL;
                }
            }
            
            if (current && property) {
                if (current->state->time <= property->within && current->state->cost <= property->maxCost && current->state->qualityLoss <= property->maxQualityLoss) {
                    if (eval(globalSymTab, mtypes, (ptState) current->state, ((ptState) current->state)->mask, property->property, EVAL_EXECUTABILITY, NULL)) {
                        printf("    +-> found satisfying state (%u with time = %d, cost = %d, qualityLoss = %d, cost function = %d), backtrack.\n", current->state->payloadHash, current->state->time, current->state->cost, current->state->qualityLoss, stateCost);
                        //printf("    +-> products able to execute: ");
                        //printBool(current->state->features);
                        //printf("\n");
                        if (optim) {
                            if (stateCost == optimalCost) {
                                _allProductsFail = !addConstraintToFD(negateBool(current->state->features));
                                _successProducts = addDisjunction(_successProducts, current->state->features, 0, 1);
                            } else if (stateCost < optimalCost) {
                                //reinitSolverWithFD();
                                _allProductsFail = !addConstraintToFD(negateBool(current->state->features));
                                _successProducts = addDisjunction(_successProducts, current->state->features, 0, 1);
                                optimalCost = stateCost;
                            } else {
                                failure("Should never get here");
                            }
                            
                        } else {
                            _allProductsFail = !addConstraintToFD(negateBool(current->state->features));
                            _successProducts = addDisjunction(_successProducts, current->state->features, 0, 1);
                        }
                        pop(&stackOuter);
                        destroyStackElement(current, processTrans);
                        _depth--;
                        current = NULL;
                    }
                } else {
                    DEBUG_PRINT("    +-> time or cost or quality loss exceeded, backtrack.\n");
                    _allProductsFail = !addConstraintToFD(negateBool(current->state->features));
                    pop(&stackOuter);
                    destroyStackElement(current, processTrans);
                    _depth--;
                    current = NULL;
                }
            }
            
            if (current) {
                
                // time
                while(current->E && ((ptProcessTransition) current->E->value)->delay > current->smallestDelay) {
                    current->E = current->E->next;
                }
                
                if(!current->E) {
                    DEBUG_PRINT("    +-> all transitions of state fired, backtracking...\n");
                    pop(&stackOuter);
                    destroyStackElement(current, processTrans);
                    _depth--;
                    
                } else {
                    if (((ptProcessTransition) current->E->value)->trans) {
                        s_ = apply(globalSymTab, mtypes, current->state, (ptProcessTransition) current->E->value, 1, &assertViolation);
                        s_->payloadHash = hashState(s_);
                        
                        DEBUG_PRINT_d(" got %u\n", s_->payloadHash);
                        if(assertViolation) {
                            char msg[40];
                            sprintf(msg, "Assertion at line %d violated", ((ptProcessTransition) current->E->value)->trans->lineNb);
                            STOP_ERROR(msg, s_->features, stackOuter, NULL, NULL);
                            error = 1;
                            stateDestroy(s_, false);
                            s_ = NULL;
                            
                        } else {
                            ptList previous = NULL;
                            new = NULL;
                            resetExclusivity = false;
                            if(!htVisitedStatesFindList(s_->payloadHash, s_, DFS_OUTER, &previous)) {
                                new = createStackElement(s_, _nbErrors);
                                
                                // time
                                ptList e;
                                if (current->onHold) {
                                    e = current->onHold;
                                    while(e) {
                                        if (((ptProcessTransition) e->value)->trans != ((ptProcessTransition) current->E->value)->trans) {
                                            new->onHold = listAdd(new->onHold, copyProcessTransition(e->value));
                                        }
                                        e = e->next;
                                    }
                                }
                                
                                if (((ptProcessTransition) current->E->value)->delay > 0) {
                                    e = current->E_save;
                                    while(e) {
                                        if (((ptProcessTransition) e->value)->trans != ((ptProcessTransition) current->E->value)->trans) {
                                            new->onHold = listAdd(new->onHold, copyProcessTransition(e->value));
                                        }
                                        e = e->next;
                                    }
                                    updateDelays(new->onHold, s_->time - current->state->time);
                                }
                                

                                
                                new->E = executables(globalSymTab, mtypes, s_, 1, _nbErrors, &hasDeadlock, NULL, NULL, &noOutgoing, &resetExclusivity, new->onHold, s_->time - current->state->time);
                                new->E_save = new->E;
                                
                                
                                
                                // time
                                new->smallestDelay = smallestDelay(new->E_save);
                                
                                if(resetExclusivity) {
                                    stateSetValue(s_->payload, OFFSET_EXCLUSIVE, T_BYTE, NO_PROCESS);
                                    s_->payloadHash = hashState(s_);
                                    DEBUG_PRINT_d("         - lost exclusivity, state became %u\n", s_->payloadHash);
                                    
                                    prevS_ = NULL;
                                    
                                    if(htVisitedStatesFindList(s_->payloadHash, s_, DFS_OUTER, &previous)) {
                                        new->state = NULL;
                                        destroyStackElement(new, processTrans);
                                        new = NULL;
                                    }
                                }
                            }
                            if(!new) {
                                DEBUG_PRINT("         - state already visited.\n");
                                stateDestroy(s_, false);
                                s_ = NULL;
                                _nbStatesStops++;
                                
                            } else {
                                
                                if (previous) {
                                    free(s_->payload);
                                    s_->payload = ((ptHtState) previous->value)->payload;
                                }
                                
                                for (ptList previousIt = previous; previousIt; previousIt = previousIt->next) {
                                    ptHtState prevS_ = (ptHtState) previousIt->value;
                                    
                                    DEBUG_PRINT("         - state visited but fresh, pushing on stack.\n");
                                    
                                    if (prevS_->time == s_->time && prevS_->cost == s_->cost && prevS_->qualityLoss == s_->qualityLoss) { // all costs equal -> merge feature expressions
                                        ptBoolFct negPrev = negateBool(prevS_->outerFeatures);
                                        if(s_->features == NULL) {
                                            destroyBool(prevS_->outerFeatures);
                                            prevS_->outerFeatures = getTrue();
                                        } else {
                                            prevS_->outerFeatures = addDisjunction(prevS_->outerFeatures, s_->features, 0, 1);
                                        }
                                        s_->features = addConjunction(negPrev, s_->features, 0, 0);
                                    } else if (prevS_->time <= s_->time && prevS_->cost <= s_->cost && prevS_->qualityLoss <= s_->qualityLoss) { // reached with all costs higher -> discard the new state except for new products
                                        if (prevS_->outerFeatures == NULL) {
                                            s_->features = getFalse();
                                        } else {
                                            ptBoolFct neg = negateBool(prevS_->outerFeatures);
                                            s_->features = addConjunction(neg, s_->features, 0, 0);
                                        }
                                    } else if (prevS_->time > s_->time && prevS_->cost > s_->cost && prevS_->qualityLoss > s_->qualityLoss) { // reached with all costs better -> discard the previous state except for products that don't reach the new state
                                        if(s_->features == NULL) {
                                            htVisitedStatesRemove(s_->payloadHash, prevS_);
                                            destroyHtState(prevS_);
                                        } else {
                                            ptBoolFct neg = negateBool(s_->features);
                                            prevS_->outerFeatures = addConjunction(neg, prevS_->outerFeatures, 0, 0);
                                            if (!isSatisfiableWrtBaseFD(prevS_->outerFeatures)) {
                                                htVisitedStatesRemove(s_->payloadHash, prevS_);
                                                destroyHtState(prevS_);
                                            }
                                        }
                                    }
                                    _nbStatesReExplored++;
                                    //STATS;
                                }
                                listDestroy(previous);
                                if (isSatisfiableWrtFD(s_->features)) {
                                    DEBUG_PRINT("         - state fresh, pushing on stack.\n");
                                    
#ifdef DEBUGSTATE
                                    printf("Inserting state:\n");
                                    //printState(s_, NULL);
#endif
                                    htVisitedStatesInsert(s_->payloadHash, s_, DFS_OUTER);
                                    _nbStatesExplored++;
                                    //STATS;
                                    
                                    stackOuter = push(stackOuter, new);
                                    _depth++;
                                }
                                
                            } // fresh state
                        } // no assert violation
                    } else {
                        // time: this is where we win
                        failure("Should never reach a final state\n");
                        printf("    +-> final state reached in %d time units\n", current->state->time);
                        printBool(current->state->features);
                        //printState(mtypes, current->state, NULL);
                        printf("");
                        printf("    +-> final state reached, backtracking...\n");
                        
                    } // stutter transition
                    // Next transition
                    current->E = current->E->next;
                    
                } // fire transition
            } //
        } // explore state
    } // end while
    printf("Products satisfying the property: ");
    printBool(_successProducts);
    printf("\n");
    printf("Products leading to problems: ");
    printBool(_failProducts);
    printf("\n");
    printf("Products satisfying without problems: ");
    printBool(addConjunction(_successProducts, negateBool(_failProducts), 1, 0));
    printf("\n");
    
    if(optim) {
        printf("Optimal cost is: %d\n", optimalCost);
    }
    
    if(error) STOP_ERROR_GLOBAL;
    destroyStackElementStack(stackOuter, processTrans);
    return error;
}

/**
 * Checks for deadlocks in a stack element.  Returns true if there are any, false
 * otherwise.
 *
 * State->features defines the products in which the state is reachable.  For no
 * deadlock to be possible, there has to be an outgoing transition in each of these
 * products.  So let OUT be the expression defining the products for which there is
 * an outgoing transition; we need to check whether  state->features  \subset  out
 * (there should be "more" outgoing that incoming).
 */
/*byte hasDeadlock(ptStackElt elt) {
	if(!elt->E_save) return 1;
	if(elt->E_save && !fullDeadlockCheck) return 0;
	ptBoolFct featuresOut = NULL;
	byte result = 1;
	ptList transList = elt->E_save;
	while(transList && result) {
		// This has to be handled separately
		if(((ptProcessTransition) transList->value)->features) {
			featuresOut = addDisjunction(featuresOut, ((ptProcessTransition) transList->value)->features, 0, 1);
		} else {
			result = 0;
			if(featuresOut) {
				destroyBool(featuresOut);
				featuresOut = NULL;
			}
		}
		transList = transList->next;
	}
	if(result == 0) return 0;
	else {
		result = !impliesWrtBaseFD(elt->state->features, featuresOut);
		if(result) {
			// TODO integrate with STOP_ERROR
			printf("State reachable by the following products\n");
			printf(" - ");printBool(elt->state->features);printf("\n");
			printf("Outgoing transitions only for the following products\n");
			printf(" - ");printBool(featuresOut);printf("\n");
		}
		destroyBool(featuresOut);
	}
	return result;
}*/

void startNestedDFS(ptSymTabNode globalSymTab, ptMTypeNode mtypes) {
	// Initialise
	initSolverWithFD(getFeatureModelClauses());
	htVisitedStatesInit();
	htOuterStatesInit();
	_nbStatesExplored = 0;
	_nbStatesReExplored = 0;
	printf("[startNestedDFS]\n");
	// Create initial state
	ptState init = stateCreateInitial(globalSymTab, mtypes);
	init->payloadHash = hashState(init);
	htVisitedStatesInsert(init->payloadHash, init, DFS_OUTER);
	htOuterStatesInsert(init->payloadHash, init);

	// Sanity checks
	if(!init->never) failure("init->never is NULL\n");
	ptFsmNode neverNode = getNodePointer(init, init->never);
	if(!neverNode) failure("init->never->node is NULL\n");
	if(!neverNode->trans) failure("No transition leaving NL%02d\n", neverNode->lineNb);

	ptStackElt elt = createStackElement(init, _nbErrors);
	ptStack stack = push(NULL,elt);
	if(outerDFS(globalSymTab, mtypes, stack) == 0) STOP_NOERROR("Property satisfied")
}

/**
 * Returns true if a violation (safety, liveness) was found (the error was already printed then).
 * Returns false otherwise.
 *
 * Assert violations and deadlocks cause an immediate exit() when detected.
 */
byte outerDFS(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptStack stackOuter) {
	ptStackElt current, new;
	ptFsmNode neverNode;
	ptState s_;
	ptHtState prevS_;
	ptBoolFct noOutgoing = NULL;

	byte resetExclusivity = false;
	ptList E = NULL;

	// Set if an error was found
	byte error = 0;
	byte assertViolation = 0;
	byte hasDeadlock = 0;

	byte temp; // TODO remove

	// Execution continues as long as the
	//  - stack is not empty
	//  - no error was found (except in the exhaustive case)
	//  - not all products are known to fail already
	while(!empty(stackOuter) && (!error || exhaustive) && !_allProductsFail) {
		EXPLORATION_LIMIT(error);

		current = top(stackOuter);
		neverNode = getNodePointer(current->state, current->state->never);

		DEBUG_PRINT_d(" - outer loop, state: %u", current->state->payloadHash);
		DEBUG_PRINT_d(", explored %lu", _nbStatesExplored);
		DEBUG_PRINT_d(", depth %lu\n", _depth);
		// If the current features are contained in the set of products known to violate the
		// property, then we do not have to go beyond the state
		if(0 < _nbErrors) {
			PROFILER_START(pr_optimisation);
			temp = !isSatisfiableWrtFD(current->state->features);
			PROFILER_END(pr_optimisation);
		}

		if(0 < _nbErrors && temp) {
			DEBUG_PRINT("    +-> is known to violate, backtrack.\n");
			pop(&stackOuter);
			htOuterStatesRemove(current->state->payloadHash, current->state->payload, current->state->payloadSize);
			destroyStackElement(current, processTrans);
			_depth--;
		// If the node of the never claim is NULL, then it had a loose end which was taken in the
		// previous transition.  This means that we are in a final state, which is assumed to be
		// accepting; hence:
		} else if(!neverNode) {
			// Safety property violated.
			// We have to pop two states off the stack to get to the violating state:
			//  -> the current top is a skip transition fired from an accepting state
			//  -> the state below that is the accepting state
			//  -> the state below that is the state that actually led to the accepting state to be reachable.
			//     i.e. this state is the actual violating state.
			pop(&stackOuter);
			ptStackElt newTop = pop(&stackOuter);
			STOP_ERROR("Safety property violated", ((ptStackElt) top(stackOuter))->state->features, stackOuter, NULL, NULL);
			error = 1;
			htOuterStatesRemove(current->state->payloadHash, current->state->payload, current->state->payloadSize);
			destroyStackElement(current, processTrans);
			destroyStackElement(newTop, processTrans);
			newTop = pop(&stackOuter);
			destroyStackElement(newTop, processTrans);
			_depth = _depth - 3;

		// Otherwise, the state can be explored (or exploration continue)
		} else {
			DEBUG_PRINT("    +-> exploring...\n");
			current->nbErrors = _nbErrors;

			// If the element is uninitialised; the executable transitions have to be determined
			if(!current->E_save && !current->E_never_save) {
				DEBUG_PRINT("    +-> initialising...\n");
				if(E) {
					current->E = E;
					E = NULL;
				}
				else
					current->E = executables(globalSymTab, mtypes, current->state, 1, _nbErrors, &hasDeadlock, NULL, NULL, &noOutgoing, &resetExclusivity, NULL, 0);
				current->E_save = current->E;
				current->E_never = executablesNever(globalSymTab, mtypes, current->state);
				current->E_never_save = current->E_never;
				// Check for deadlocks
				if(hasDeadlock) {
					STOP_ERROR("Found deadlock", current->state->features, stackOuter, NULL, NULL);
					error = 1;
					current->E = NULL; // This will cause backtracking
				} else if(!current->E_never) current->E = NULL;
				if(fullDeadlockCheck && noOutgoing) {
					if(isSatisfiableWrtFD(noOutgoing)) {
						STOP_ERROR("Found trivially invalid end state; the following set of products can reach the state, but has no outgoing transition.", noOutgoing, stackOuter, NULL, NULL);
						error = 1;
					}
					destroyBool(noOutgoing);
					noOutgoing = NULL;
				}
			}
			// If we have explored all transitions of the state (!current->E_never; see "struct stackElt"
			// in stack.h), we check whether the state is accepting and start a backlink search if it is;
			// otherwise just backtrack
			if(!current->E) {
				DEBUG_PRINT("    +-> all transitions of state fired, acceptance check and backtracking...\n");
				// Back these values up, the inner search will free current->state before returning
				void* payloadBak = current->state->payload;
				unsigned int payloadHashBak = current->state->payloadHash;
				unsigned int payloadSizeBak = current->state->payloadSize;
				if((neverNode->flags & N_ACCEPT) == N_ACCEPT) {
					DEBUG_PRINT("    +-> found accepting, starting inner...\n");
					new = createStackElement(current->state, _nbErrors);
					ptStack stackInner = push(NULL, new);
					_depth++;
					_nbStatesExploredInner++;
					error = innerDFS(globalSymTab, mtypes, stackOuter, stackInner) || error; // error needs to be to the right, for otherwise lazy evaluation might cause the innerDFS call to be skipped
					current->state = NULL; // it will have been destroyed when the innerDFS backtracked for the last time
				}
				pop(&stackOuter);
				htOuterStatesRemove(payloadHashBak, payloadBak, payloadSizeBak);
				destroyStackElement(current, processTrans);
				_depth--;

			// ..., or there is a transition to be executed:
			} else if(current->E) {
				DEBUG_PRINT_d("    +-> firing transition TL%02d...", ((ptProcessTransition) current->E->value)->trans ? ((ptProcessTransition) current->E->value)->trans->lineNb : -1);
				s_ = apply(globalSymTab, mtypes, current->state, (ptProcessTransition) current->E->value, 1, &assertViolation);
				s_ = applyNever(globalSymTab, mtypes, s_, (ptFsmTrans) current->E_never->value);
				E = executables(globalSymTab, mtypes, s_, 1, _nbErrors, &hasDeadlock, NULL, NULL, &noOutgoing, &resetExclusivity, NULL, 0);
				if(resetExclusivity) {
					stateSetValue(s_->payload, OFFSET_EXCLUSIVE, T_BYTE, NO_PROCESS);
					DEBUG_PRINT_d("         - lost exclusivity, state became %u\n", s_->payloadHash);
				}

				s_->payloadHash = hashState(s_);
				DEBUG_PRINT_d(" got %u\n", s_->payloadHash);
				if(assertViolation) {
					char msg[40];
					sprintf(msg, "Assertion at line %d violated", ((ptProcessTransition) current->E->value)->trans->lineNb);
					STOP_ERROR(msg, s_->features, stackOuter, NULL, NULL);
					error = 1;
					stateDestroy(s_, false);
					s_ = NULL;
					destroyProcTransList(E, processTrans);
					E = NULL;

				} else {
					prevS_ = NULL;
					if(htVisitedStatesFind(s_->payloadHash, s_, DFS_OUTER, &prevS_)) {
						DEBUG_PRINT("         - state already visited.\n");
						stateDestroy(s_, false);
						s_ = NULL;
						destroyProcTransList(E, processTrans);
						E = NULL;
						_nbStatesStops++;

					} else {
						if(prevS_) {
							DEBUG_PRINT("         - state visited but features fresh, pushing on stack.\n");
							// The state was visited already, but the current copy is "fresher".
							// No need to insert it into the hash table, just update the feature expression

							// Important: PrevS_ can only be a state that was fully explored with the features
							// it has now. This is because:
							//  - it has been visited already (otherwise, it wouldn't be in the hashtab)
							//  - it is not a state on the current stack (otherwise, it wouldn't be fresh)
							// This means, that all states that could be visited with prevS_->features have
							// been visited already.  So, when we continue, we use s_->features and not
							// s_->features || prevS_->features.
							ptBoolFct negPrev = negateBool(prevS_->outerFeatures);
							if(s_->features == NULL) {
								destroyBool(prevS_->outerFeatures);
								prevS_->outerFeatures = getTrue();
							} else {
								prevS_->outerFeatures = addDisjunction(prevS_->outerFeatures, s_->features, 0, 1);

								#ifdef CHECK_TAUTOLOGY
									if(prevS_->outerFeatures && isTautology(prevS_->outerFeatures)) {
										destroyBool(prevS_->outerFeatures);
										prevS_->outerFeatures = getTrue();
									}
								#endif
							}
							s_->features = addConjunction(negPrev, s_->features, 0, 0);
							free(s_->payload);
							s_->payload = prevS_->payload;

							// The state is not a new state:
							_nbStatesReExplored++;
							STATS;

						} else {
							DEBUG_PRINT("         - state fresh, pushing on stack.\n");
							// The state was not visited at all
							htVisitedStatesInsert(s_->payloadHash, s_, DFS_OUTER);
							_nbStatesExplored++;
							STATS;

						}
						new = createStackElement(s_, _nbErrors);
						stackOuter = push(stackOuter, new);
						htOuterStatesInsert(s_->payloadHash, s_);
						_depth++;
					} // fresh state
				} // no assert violation
				// Simulate nested loop: when at the end of E, restart the E and advance the E_never
				// The deadlock test (E empty) is already done.  This also guarantees that E->value
				// is never NULL in the above apply(globalSymTab, mtypes, ).
				current->E_never = current->E_never->next;
				if(!current->E_never) {
					current->E = current->E->next;
					current->E_never = current->E_never_save;
				}
			} // fire transition
		} // explore state
	} // end while

	// If error is true and we end up here, then we're in exhaustive mode. A summary has to be printed
	if(error /* not needed: && exhaustive */) STOP_ERROR_GLOBAL;
	destroyStackElementStack(stackOuter, processTrans);
	return error;
}

/**
 * Returns true if a violation (liveness, deadlock) was found (the error was already printed then).
 * Returns false otherwise.
 *
 * Assert violations cause an immediate exit() when detected.
 */
byte innerDFS(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptStack stackOuter, ptStack stackInner) {
	ptStackElt current, new;
	ptFsmNode neverNode;
	ptState s_;
	ptHtState prevS_, onSt;
	ptBoolFct noOutgoing = NULL;

	byte resetExclusivity = false;
	ptList E = NULL;
	byte temp;

	byte error = 0;
	byte assertViolation = 0;
	byte hasDeadlock = 0;

	// Same conditions as for the outerDFS loop
	while(!empty(stackInner) && (!error || exhaustive) && !_allProductsFail) {
		EXPLORATION_LIMIT(error);

		current = top(stackInner);
		neverNode = getNodePointer(current->state, current->state->never);

		DEBUG_PRINT_d("         - inner loop, state: %u", current->state->payloadHash);
		DEBUG_PRINT_d(", explored %lu", _nbStatesExplored);
		DEBUG_PRINT_d(", depth %lu\n", _depth);

		// If the current features are contained in the set of products known to violate the
		// property, then we do not have to go beyond the state
		temp = 0;
		if(current->nbErrors < _nbErrors) {
			PROFILER_START(pr_optimisation);
			temp = !isSatisfiableWrtFD(current->state->features);
			PROFILER_END(pr_optimisation);
		}

		if(current->nbErrors < _nbErrors && temp) {
			DEBUG_PRINT("            +-> is known to violate, backtrack.\n");
			pop(&stackInner);
			destroyStackElement(current, processTrans);
			_depth--;

		// Otherwise, explore state
		} else {
			DEBUG_PRINT("            +-> exploring.\n");
			current->nbErrors = _nbErrors;

			// If the element is uninitialised; the executable transitions have to be determined
			if(!current->E_save && !current->E_never_save) {
				DEBUG_PRINT("            +-> initialising.\n");
				if(E) {
					current->E = E;
					E = NULL;
				}
				else
					current->E = executables(globalSymTab, mtypes, current->state, 1, _nbErrors, &hasDeadlock, NULL, NULL, &noOutgoing, &resetExclusivity, NULL, 0);
				current->E_save = current->E;
				current->E_never = executablesNever(globalSymTab, mtypes, current->state);
				current->E_never_save = current->E_never;

				// Check for deadlocks
				if(hasDeadlock) {
					STOP_ERROR("Found deadlock", current->state->features, stackOuter, stackInner, NULL);
					error = 1;
					current->E_never = NULL; // This will cause backtracking
				} else if(!current->E_never) current->E = NULL;

				if(fullDeadlockCheck && noOutgoing) {
					if(isSatisfiableWrtFD(noOutgoing)) {
						STOP_ERROR("Found trivially invalid end state; the following set of products can reach the state, but has no outgoing transition.", noOutgoing, stackOuter, stackInner, NULL);
						error = 1;
					}
					destroyBool(noOutgoing);
					noOutgoing = NULL;
				}
			}

			// When there are no more transitions to execute for the state, backtrack
			if(!current->E) {
				DEBUG_PRINT("            +-> all transitions of state fired, backtracking.\n");
				pop(&stackInner);
				destroyStackElement(current, processTrans);
				_depth--;

			// Otherwise, execute the current transition
			} else {
				DEBUG_PRINT_d("            +-> firing transition TL%02d...", ((ptProcessTransition) current->E->value)->trans ? ((ptProcessTransition) current->E->value)->trans->lineNb : -1);
				s_ = apply(globalSymTab, mtypes, current->state, (ptProcessTransition) current->E->value, 1, &assertViolation);
				s_ = applyNever(globalSymTab, mtypes, s_, (ptFsmTrans) current->E_never->value);
				E = executables(globalSymTab, mtypes, s_, 1, _nbErrors, &hasDeadlock, NULL, NULL, &noOutgoing, &resetExclusivity, NULL, 0);
				if(resetExclusivity) {
					stateSetValue(s_->payload, OFFSET_EXCLUSIVE, T_BYTE, NO_PROCESS);
					DEBUG_PRINT_d("         - lost exclusivity, state became %u\n", s_->payloadHash);
				}
				s_->payloadHash = hashState(s_);
				DEBUG_PRINT_d(" got %u\n", s_->payloadHash);

				// Check whether back link or assert violation, if yes: do not explore further
				// onSt = stateOnStack(s_, stackOuter, STACK_ELT);
				onSt = htOuterStatesFind(s_->payloadHash, s_);
				if(onSt || assertViolation) {
					new = createStackElement(s_, _nbErrors);
					stackInner = push(stackInner, new); // push on stack for printing purpose

					if(onSt) {
						STOP_ERROR("Property violated", s_->features, stackOuter, stackInner, s_)
					}
					else {
						char msg[40];
						sprintf(msg, "Assertion at line %d violated", ((ptProcessTransition) current->E->value)->trans->lineNb);
						STOP_ERROR(msg, s_->features, stackOuter, stackInner, NULL);
					}

					error = 1;

					// Destroy the state and undo the push(stackInner) done for printing before
					stateDestroy(s_, false);
					s_ = NULL;
					destroyProcTransList(E, processTrans);
					E = NULL;
					((ptStackElt) top(stackInner))->state = NULL; // otherwise, destroyStackElement will access the freed state
					destroyStackElement(top(stackInner), processTrans);
					pop(&stackInner);

				// If no: continue
				} else {
					prevS_ = NULL;
					if(htVisitedStatesFind(s_->payloadHash, s_, DFS_INNER, &prevS_)) {
						DEBUG_PRINT("                 - state already visited\n");
						stateDestroy(s_, false);
						s_ = NULL;
						destroyProcTransList(E, processTrans);
						E = NULL;
						_nbStatesStopsInner++;

					} else {
						if(prevS_) {
							if(prevS_->foundInDFS == DFS_INNER) {
								DEBUG_PRINT("                 - state visited, but features fresh\n");
								_nbStatesReExploredInner++;
							} else {
								DEBUG_PRINT("                 - state only visited during outer search\n");
								prevS_->foundInDFS = DFS_INNER;
								_nbStatesExploredInner++;
							}
							STATS;

							// The state was visited already, but the current copy is "fresher".
							// No need to insert it into the hash table, just update the feature expression
							ptBoolFct negPrev = negateBool(prevS_->innerFeatures);
							if(s_->features == NULL) {
								destroyBool(prevS_->innerFeatures);
								prevS_->innerFeatures = getTrue();
							} else {
								prevS_->innerFeatures = addDisjunction(prevS_->innerFeatures, s_->features, 0, 1);
								#ifdef CHECK_TAUTOLOGY
									if(prevS_->innerFeatures && isTautology(prevS_->innerFeatures)) {
										destroyBool(prevS_->innerFeatures);
										prevS_->innerFeatures = getTrue();
									}
								#endif
							}
							s_->features = addConjunction(negPrev, s_->features, 0, 0);
							free(s_->payload);
							s_->payload = prevS_->payload;

						} else {
							printState(mtypes, s_,NULL);
							printf("Bug! The above state was found during the inner DFS but not during the outer! Aborting.\n");
							exit(EXIT_ERROR);
						}

						// Continue DFS
						new = createStackElement(s_, _nbErrors);
						stackInner = push(stackInner, new);
						_depth++;
					} // Fresh
				} // No back link
				// Walk through transition lists
				current->E_never = current->E_never->next;
				if(!current->E_never) {
					current->E = current->E->next;
					current->E_never = current->E_never_save;
				}
			} // fire transition
		} // explore state
	} // end while

	DEBUG_PRINT("         - done, returning to outer.\n");
	destroyStackElementStack(stackInner, processTrans);
	return error;
}

void startExplorationBFS(ptSymTabNode globalSymTab, ptMTypeNode mtypes) {
	// Initialise
	initSolverWithFD(getFeatureModelClauses());
	htVisitedStatesInit();

	// Create initial state
	ptState init = stateCreateInitial(globalSymTab, mtypes);
	init->payloadHash = hashState(init);
	htVisitedStatesInsert(init->payloadHash, init, DFS_OUTER);

	ptBoolFct noOutgoing = NULL;
	byte resetExclusivity = false;
	ptStackElt elt = createStackElement(init, _nbErrors);
	ptList stateList = listAdd(NULL, elt);
	elt->E = executables(globalSymTab, mtypes, init, 1, _nbErrors, NULL, NULL, NULL, &noOutgoing, &resetExclusivity, NULL, 0);
	elt->E_save = elt->E;
	if(!elt->E) STOP_ERROR_NOPRINT("Initial state has no outgoing transition", NULL);
	if(fullDeadlockCheck && noOutgoing) {
		if(isSatisfiableWrtBaseFD(noOutgoing)) STOP_ERROR_NOPRINT("Found trivially invalid end state; the following set of products can reach the state, but has no outgoing transition.", noOutgoing);
		destroyBool(noOutgoing);
		noOutgoing = NULL;
	}
	if(exploreBFS(globalSymTab, mtypes, stateList) == 0) STOP_NOERROR("No assertion violations or deadlocks found");
}

/**
 * Returns false if no assert violations or deadlocks were found.
 */
byte exploreBFS(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptList stateList) {
	ptStackElt current, new;
	ptFsmNode neverNode;
	ptState s_;
	ptHtState prevS_;
	ptBoolFct noOutgoing = NULL;
	ptList tmp;
	byte resetExclusivity = false;

	// Set if an error was found
	byte error = 0;
	byte assertViolation = 0;
	byte hasDeadlock = 0;

	// Execution continues as long as the
	//  - stack is not empty
	//  - no error was found (except in the exhaustive case)
	//  - not all products are known to fail already
	while(stateList && (!error || exhaustive) && !_allProductsFail) {
		EXPLORATION_LIMIT(error);

		current = (ptStackElt) stateList->value;

		DEBUG_PRINT_d(" - outer loop, state: %u", current->state->payloadHash);
		DEBUG_PRINT_d(", explored %lu", _nbStatesExplored);
		DEBUG_PRINT_d(", depth %lu\n", _depth);

		// If the current features are contained in the set of products known to violate the
		// property, then we do not have to go beyond the state
		if(current->nbErrors < _nbErrors && !isSatisfiableWrtFD(current->state->features)) {
			DEBUG_PRINT("    +-> is known to violate, backtrack.\n");
			stateList = listRemove(stateList, stateList->value);
			destroyStackElement(current, processTrans);
			_depth--;
		// Otherwise, the state can be explored (or exploration continue)
		} else {
			DEBUG_PRINT("    +-> exploring...\n");
			current->nbErrors = _nbErrors;

			while(current->E) {
				DEBUG_PRINT_d("    +-> firing transition TL%02d...", ((ptProcessTransition) current->E->value)->trans ? ((ptProcessTransition) current->E->value)->trans->lineNb : -1);
				s_ = apply(globalSymTab, mtypes, current->state, (ptProcessTransition) current->E->value, 1, &assertViolation);
				s_->payloadHash = hashState(s_);
				DEBUG_PRINT_d(" got %u\n", s_->payloadHash);
				if(assertViolation) {
					char msg[40];
					sprintf(msg, "Assertion at line %d violated", ((ptProcessTransition) current->E->value)->trans->lineNb);
					STOP_ERROR_NOPRINT(msg, s_->features);

					error = 1;
					stateDestroy(s_, false);
					s_ = NULL;

				} else {
					prevS_ = NULL;
					new = NULL;
					resetExclusivity = false;
					if(!htVisitedStatesFind(s_->payloadHash, s_, DFS_OUTER, &prevS_)) {
						new = createStackElement(s_, _nbErrors);
						new->E = executables(globalSymTab, mtypes, s_, 1, _nbErrors, &hasDeadlock, NULL, NULL, &noOutgoing, &resetExclusivity, NULL, 0);
						new->E_save = new->E;
						if(resetExclusivity) {
							stateSetValue(s_->payload, OFFSET_EXCLUSIVE, T_BYTE, NO_PROCESS);
							s_->payloadHash = hashState(s_);
							DEBUG_PRINT_d("         - lost exclusivity, state became %u\n", s_->payloadHash);

							prevS_ = NULL;

							if(htVisitedStatesFind(s_->payloadHash, s_, DFS_OUTER, &prevS_)) {
								new->state = NULL;
								destroyStackElement(new, processTrans);
								new = NULL;
							}
						}
					}
					if(!new) {
						DEBUG_PRINT("         - state already visited.\n");
						stateDestroy(s_, false);
						s_ = NULL;
						_nbStatesStops++;

					} else {
						stateList = listAdd(stateList, new);
						if(prevS_) {
							DEBUG_PRINT("         - state visited but features fresh, pushing on stack.\n");
							ptBoolFct negPrev = negateBool(prevS_->outerFeatures);
							if(s_->features == NULL) {
								destroyBool(prevS_->outerFeatures);
								prevS_->outerFeatures = getTrue();
							} else {
								prevS_->outerFeatures = addDisjunction(prevS_->outerFeatures, s_->features, 0, 1);
#ifdef CHECK_TAUTOLOGY
								if(prevS_->outerFeatures && isTautology(prevS_->outerFeatures)) {
									destroyBool(prevS_->outerFeatures);
									prevS_->outerFeatures = getTrue();
								}
#endif
							}
							s_->features = addConjunction(negPrev, s_->features, 0, 0);
							free(s_->payload);
							s_->payload = prevS_->payload;

							_nbStatesReExplored++;
							STATS;
						} else {
							DEBUG_PRINT("         - state fresh, pushing on stack.\n");

							// The state was not visited at all
#ifdef DEBUGSTATE
							printf("Inserting state:\n");
							printState(s_, NULL);
#endif
							htVisitedStatesInsert(s_->payloadHash, s_, DFS_OUTER);
							_nbStatesExplored++;
							STATS;
						}

						if(new && hasDeadlock) {
							STOP_ERROR_NOPRINT("Found deadlock", s_->features);
							error = 1;
							tmp = stateList;
							stateList = stateList->next;
							free(tmp);
							_depth--;
							stateDestroy(new->state, false);
							new->state = NULL;
							destroyStackElement(new, processTrans);

						} else if(new && !new->E){
							// Even without deadlock, the list of transitions might be empty; account for that:
							/*tmp = stateList;
							stateList = stateList->next;
							free(tmp);
							_depth--;
							stateDestroy(new->state, false);
							new->state = NULL;
							destroyStackElement(new, processTrans);*/
						}

						if(new && fullDeadlockCheck && noOutgoing) {
							if(isSatisfiableWrtFD(noOutgoing)) {
								STOP_ERROR_NOPRINT("Found trivially invalid end state; the following set of products can reach the state, but has no outgoing transition.", noOutgoing);
								error = 1;
							}
							destroyBool(noOutgoing);
							noOutgoing = NULL;
						}

					} // fresh state
				} // no assert violation

				// Next transition
				current->E = current->E->next;
			} // fire transition
			DEBUG_PRINT("    +-> all transitions of state fired, removing state from list...\n");
			stateList = listRemove(stateList, stateList->value);
			destroyStackElement(current, processTrans);
			_depth++;
		} // explore state
	} // end while

	if(error) STOP_ERROR_GLOBAL;

	//destroyStackElementStack(stackOuter, processTrans);
	return error;
}


// Simple exploration

void startExplorationWithFDG(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptFdg fdg) {
	// Initialise
	initSolverWithFD(getFeatureModelClauses());
	htVisitedStatesInit();

	// Create initial state
	ptState init = stateCreateInitial(globalSymTab, mtypes);
	init->payloadHash = hashState(init);
	htVisitedStatesInsert(init->payloadHash, init, DFS_OUTER);

	ptBoolFct noOutgoing = NULL;
	byte resetExclusivity = false;
	ptStackElt elt = createStackElement(init, _nbErrors);
	ptStack stack = push(NULL, elt);
	elt->E = executables(globalSymTab, mtypes, init, 1, _nbErrors, NULL, NULL, NULL, &noOutgoing, &resetExclusivity, NULL, 0);
	elt->E_save = elt->E;
	if(!elt->E) STOP_ERROR("Initial state has no outgoing transition", NULL, stack, NULL, NULL);
	if(fullDeadlockCheck && noOutgoing) {
		if(isSatisfiableWrtBaseFD(noOutgoing)) STOP_ERROR("Found trivially invalid end state; the following set of products can reach the state, but has no outgoing transition.", noOutgoing, stack, NULL, NULL);
		destroyBool(noOutgoing);
		noOutgoing = NULL;
	}
	if(exploreWithFDG(globalSymTab, mtypes, stack, fdg) == 0) STOP_NOERROR("No assertion violations or deadlocks found");
}

/**
 * Returns false if no assert violations or deadlocks were found.
 */
byte exploreWithFDG(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptStack stackOuter, ptFdg fdg) {
	ptStackElt current, new;
	ptFsmNode neverNode;
	ptState s_;
	ptHtState prevS_;
	ptBoolFct noOutgoing = NULL;

	byte resetExclusivity = false;

	// Set if an error was found
	byte error = 0;
	byte assertViolation = 0;
	byte hasDeadlock = 0;

	ptFdgNode currentFdgNode = fdg->init;

	// Execution continues as long as the
	//  - stack is not empty
	//  - no error was found (except in the exhaustive case)
	//  - not all products are known to fail already
	while(!empty(stackOuter) && (!error || exhaustive) && !_allProductsFail) {
		EXPLORATION_LIMIT(error);

		current = top(stackOuter);

		DEBUG_PRINT_d(" - outer loop, state: %u", current->state->payloadHash);
		DEBUG_PRINT_d(", explored %lu", _nbStatesExplored);
		DEBUG_PRINT_d(", depth %lu\n", _depth);

		// If the current features are contained in the set of products known to violate the
		// property, then we do not have to go beyond the state
		if(current->nbErrors < _nbErrors && !isSatisfiableWrtFD(current->state->features)) {
			DEBUG_PRINT("    +-> is known to violate, backtrack.\n");
			pop(&stackOuter);
			destroyStackElement(current, processTrans);
			_depth--;

		// Otherwise, the state can be explored (or exploration continue)
		} else {
			DEBUG_PRINT("    +-> exploring...\n");
			current->nbErrors = _nbErrors;

			if(!current->E) {
				DEBUG_PRINT("    +-> all transitions of state fired, backtracking...\n");
				pop(&stackOuter);
				destroyStackElement(current, processTrans);
				_depth--;

			} else {
				DEBUG_PRINT_d("    +-> firing transition TL%02d...", ((ptProcessTransition) current->E->value)->trans ? ((ptProcessTransition) current->E->value)->trans->lineNb : -1);
				s_ = apply(globalSymTab, mtypes, current->state, (ptProcessTransition) current->E->value, 1, &assertViolation);
				s_->payloadHash = hashState(s_);
				DEBUG_PRINT_d(" got %u\n", s_->payloadHash);
				if(assertViolation) {
					char msg[40];
					sprintf(msg, "Assertion at line %d violated", ((ptProcessTransition) current->E->value)->trans->lineNb);
					STOP_ERROR(msg, s_->features, stackOuter, NULL, NULL);

					error = 1;
					stateDestroy(s_, false);
					s_ = NULL;

				} else {
					prevS_ = NULL;
					new = NULL;
					resetExclusivity = false;
					if(!htVisitedStatesFind(s_->payloadHash, s_, DFS_OUTER, &prevS_)) {
						new = createStackElement(s_, _nbErrors);
						new->E = executables(globalSymTab, mtypes, s_, 1, _nbErrors, &hasDeadlock, NULL, NULL, &noOutgoing, &resetExclusivity, NULL, 0);
						new->E_save = new->E;
						if(resetExclusivity) {
							stateSetValue(s_->payload, OFFSET_EXCLUSIVE, T_BYTE, NO_PROCESS);
							s_->payloadHash = hashState(s_);
							DEBUG_PRINT_d("         - lost exclusivity, state became %u\n", s_->payloadHash);

							prevS_ = NULL;

							if(htVisitedStatesFind(s_->payloadHash, s_, DFS_OUTER, &prevS_)) {
								new->state = NULL;
								destroyStackElement(new, processTrans);
								new = NULL;
							}
						}
					}
					if(!new) {
						DEBUG_PRINT("         - state already visited.\n");
						stateDestroy(s_, false);
						s_ = NULL;
						_nbStatesStops++;

					} else {
						stackOuter = push(stackOuter, new);
						_depth++;
						if(prevS_) {
							DEBUG_PRINT("         - state visited but features fresh, pushing on stack.\n");
							ptBoolFct negPrev = negateBool(prevS_->outerFeatures);
							if(s_->features == NULL) {
								destroyBool(prevS_->outerFeatures);
								prevS_->outerFeatures = getTrue();
							} else {
								prevS_->outerFeatures = addDisjunction(prevS_->outerFeatures, s_->features, 0, 1);
#ifdef CHECK_TAUTOLOGY
								if(prevS_->outerFeatures && isTautology(prevS_->outerFeatures)) {
									destroyBool(prevS_->outerFeatures);
									prevS_->outerFeatures = getTrue();
								}
#endif
							}
							s_->features = addConjunction(negPrev, s_->features, 0, 0);
							free(s_->payload);
							s_->payload = prevS_->payload;

							_nbStatesReExplored++;
							STATS;
						} else {
							DEBUG_PRINT("         - state fresh, pushing on stack.\n");

							// The state was not visited at all
#ifdef DEBUGSTATE
							printf("Inserting state:\n");
							printState(s_, NULL);
#endif
							htVisitedStatesInsert(s_->payloadHash, s_, DFS_OUTER);
							_nbStatesExplored++;
							STATS;
						}

						if(new && hasDeadlock) {
							STOP_ERROR("Found deadlock", s_->features, stackOuter, NULL, NULL);
							error = 1;
							pop(&stackOuter);
							_depth--;
							stateDestroy(new->state, false);
							new->state = NULL;
							destroyStackElement(new, processTrans);

						} else if(new && !new->E){
							// Even without deadlock, the list of transitions might be empty; account for that:
							pop(&stackOuter);
							_depth--;
							stateDestroy(new->state, false);
							new->state = NULL;
							destroyStackElement(new, processTrans);
						}

						if(new && fullDeadlockCheck && noOutgoing) {
							if(isSatisfiableWrtFD(noOutgoing)) {
								STOP_ERROR("Found trivially invalid end state; the following set of products can reach the state, but has no outgoing transition.", noOutgoing, stackOuter, NULL, NULL);
								error = 1;
							}
							destroyBool(noOutgoing);
							noOutgoing = NULL;
						}

					} // fresh state
				} // no assert violation

				// Next transition
				current->E = current->E->next;

			} // fire transition
		} // explore state
	} // end while

	if(error) STOP_ERROR_GLOBAL;

	destroyStackElementStack(stackOuter, processTrans);
	return error;
}
