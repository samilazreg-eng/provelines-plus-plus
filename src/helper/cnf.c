#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "main.h"
#include "cnf.h"
#include "boolFct.h"
#include "tvl.h"

/*
 * CNF AND DIMACS FILES
 * * * * * * * * * * * * * * * * * * * * * * * */

#ifdef PROFILE_CNF
	PROFILER_REGISTER(pr_disjunctClauses, "disjunctClauses", 10);
	PROFILER_REGISTER(pr_addCNFConjunction, "addCNFConjunction", 2000);
	PROFILER_REGISTER(pr_addCNFDisjunction, "addCNFDisjunction", 2000);
	PROFILER_REGISTER(pr_negateCNF, "negateCNF", 10000);
#endif

/**
 * This function takes an arbitrary clause and formats it so that it satisfies the
 * precondition of most of the functions here, meaning that it
 *  - is ordered by literal (by absolute value)
 *  - has no duplicate literals or the same literal positive and negative.
 *
 * The original data structure will not be preserved.
 *
 * ATTENTION, this function will return NULL if formatting reveals that the clause is a trivial tautology.
 */
ptClause formatClause(ptClause list) {
    int listSize=1,numMerges,leftSize,rightSize;
    ptClause tail;
    ptClause left;
    ptClause right;
    ptClause next;
    if (!list || !list->disjunction) return list;  // Trivial case

    do { // For each power of two<=list length
        numMerges=0,left=list;tail=list=0; // Start at the start

        while (left) { // Do this list_len/listSize times:
            numMerges++,right=left,leftSize=0,rightSize=listSize;
            // Cut list into two halves (but don't overrun)
            while (right && leftSize<listSize) leftSize++,right=right->disjunction;
            // Run through the lists appending onto what we have so far.
            while (leftSize>0 || (rightSize>0 && right)) {
                // Left empty, take right OR Right empty, take left, OR compare.
                if (!leftSize)                  {next=right;right=right->disjunction;rightSize--;}
                else if (!rightSize || !right)  {next=left;left=left->disjunction;leftSize--;}
                else if (abs(left->lit) < abs(right->lit)
                		|| 	(abs(left->lit) == abs(right->lit)
                				&& left->lit < right->lit)) {next=left;left=left->disjunction;leftSize--;}
                else                            {next=right;right=right->disjunction;rightSize--;}
                // Update pointers to keep track of where we are:
                if (tail) tail->disjunction=next;  else list=next;
                // Sort prev pointer
                tail=next;
            }
            // Right is now AFTER the list we just sorted, so start the next sort there.
            left=right;
        }
        // Terminate the list, double the list-sort size.
        tail->disjunction=NULL,listSize<<=1;
    } while (numMerges>1); // If we only did one merge, then we just sorted the whole list.

    // After sorting, filter duplicates and literals that cancel each other out
    ptClause temp;
    int cancelout = 0;
    next = list;
    tail = NULL;
    list = NULL;
    while(next != NULL) {
    	if(next->lit == cancelout || (next->disjunction && next->disjunction->lit == next->lit)) {
    		temp = next->disjunction;
    		free(next);
    		next = temp;
    	} else if(next->disjunction && abs(next->disjunction->lit) == abs(next->lit)) {
    		temp = next->disjunction->disjunction;
    		cancelout = next->disjunction->lit;
    		free(next->disjunction);
    		free(next);
    		next = temp;
    	} else {
    		temp = next->disjunction;
    		if(tail) tail->disjunction = next;
    		next->disjunction = NULL;
			tail = next;
    		next = temp;
    	}
    	if(!list) list = tail;
    }
    return list;
}

/*
 * Will apply "formatClause" to every clause of the CNF.
 *
 * ATTENTION, this function will return NULL if formatting reveals that the CNF is a trivial tautology.
 */
ptCNF formatCNF(ptCNF formula) {
    ptCNF current = formula;
    ptCNF tail = NULL, temp = NULL;
    formula = NULL;
    while(current) {
    	temp = current->conjunction;
    	current->clause = formatClause(current->clause);
    	if(!current->clause) free(current);
    	else {
    		if(tail) tail->conjunction = current;
    		current->conjunction = NULL;
    		tail = current;
    	}
    	current = temp;
    }
    return formula;
}

/**
 * Parses a DIMACS CNF file and produces the corresponding CNF structure.
 * Returns NULL if the file could not be read.
 */
ptCNF dimacsFileToCNF(char * filePath) {
	FILE* dimacsFile = fopen(filePath, "r");
	int currentNbr;
	char format[100];
	byte mallocCNF = 1;
	ptCNF currentCNF = NULL;
	ptCNF cnf;
	ptClause currentClause = NULL;
	if(dimacsFile != NULL) {
		fgets(format,100,dimacsFile);
		while(fscanf(dimacsFile, "%d", &currentNbr) != EOF) {
			switch(currentNbr) {
				case(0):
					mallocCNF = 1;
					cnf->clause = formatClause(cnf->clause);
					currentClause = NULL;
					break;
				default:
					if (mallocCNF == 1) {
						cnf = (ptCNF)malloc(sizeof(tCNF));
						if(!cnf) failure("Out of memory (creating tCNF).\n");
						cnf->clause = (ptClause) malloc(sizeof(tClause));
						if(!cnf->clause) failure("Out of memory (creating CNF clause).\n");
						cnf->conjunction = currentCNF;
						currentClause = cnf->clause;
						currentCNF = cnf;
						mallocCNF = 0;
					} else {
						currentClause->disjunction = (ptClause) malloc(sizeof(tClause));
						if(!currentClause->disjunction) failure("Out of memory (creating CNF clause).\n");
						currentClause = currentClause->disjunction;
					}
					currentClause->lit = currentNbr;
					currentClause->disjunction = NULL;
					break;
			}
		}
		fclose(dimacsFile);
		return cnf;
	} else return NULL;
}

/**
 * Registers the content of a CNF structure in a file, respecting the DIMACS CNF format.
 * Does not write anything if the formula is NULL.
 */
void CNFToDimacsFile(ptCNF formula, char * filePath) {
	FILE* dimacsFile = fopen(filePath, "w+");
	if(dimacsFile) {
		ptCNF currentCNF = formula;
		ptClause currentClause = NULL;
		fputs("p cnf 9 9\n", dimacsFile); /* Not right but Minisat does not care */
		while(currentCNF) {
			currentClause = currentCNF->clause;
			while(currentClause) {
				fprintf(dimacsFile, "%d ", currentClause->lit);
				currentClause = currentClause->disjunction;
			}
			fprintf(dimacsFile, "0\n");
			currentCNF = currentCNF->conjunction;
		}
		fclose(dimacsFile);
	}
}

/**
 * Creates a formula with one literal in it.
 */
ptCNF createCNFLiteral(int lit) {
	ptCNF cnf = (ptCNF) malloc(sizeof(tCNF));
	if(!cnf) failure("Out of memory (creating CNF).\n");
	cnf->conjunction = NULL;
	cnf->clause = (ptClause) malloc(sizeof(tClause));
	if(!cnf->clause) failure("Out of memory (creating clause).\n");
	cnf->clause->lit = lit;
	cnf->clause->disjunction = NULL;
	return cnf;
}

/**
 * Duplicates a clause.
 * Accepts a NULL pointer (returns NULL then).
 */
ptClause copyClause(ptClause original) {
	if(!original)	return NULL;
	ptClause currentClause = original;
	ptClause copyHead = (ptClause) malloc(sizeof(tClause));
	if(!copyHead)	failure("Out of memory (creating clause).\n");
	copyHead->lit = currentClause->lit;
	ptClause copyBody = copyHead;
	while(currentClause->disjunction) {
		copyBody->disjunction = (ptClause) malloc(sizeof(tClause));
		if(!copyBody->disjunction)	failure("Out of memory (creating clause).\n");
		copyBody->disjunction->lit = currentClause->disjunction->lit;
		copyBody = copyBody->disjunction;
		currentClause = currentClause->disjunction;
	}
	copyBody->disjunction = NULL;

	return copyHead;
}

/**
 * Duplicates a CNF formula.
 * Accepts a NULL pointer (returns NULL then).
 */
ptCNF copyCNF(ptCNF formula) {
	if(!formula) return NULL;
	ptCNF currentCNF = formula;
	ptCNF copyHead = (ptCNF) malloc(sizeof(tCNF));
	if(!copyHead) failure("Out of memory (creating CNF).\n");
	copyHead->clause = copyClause(currentCNF->clause);
	ptCNF copy = copyHead;
	while(currentCNF->conjunction) {
		copy->conjunction = (ptCNF) malloc(sizeof(tCNF));
		if(!copy->conjunction) failure("Out of memory (creating CNF).\n");
		copy->conjunction->clause = copyClause(currentCNF->conjunction->clause);
		copy = copy->conjunction;
		currentCNF = currentCNF->conjunction;
	}
	copy->conjunction = NULL;
	return copyHead;
}

/**
 * Frees the memory used by a clause structure.
 */
void destroyClause(ptClause clause) {
	if (clause) {
		destroyClause(clause->disjunction);
		free(clause);
	}
}

/**
 * Frees the memory used by a CNF structure.
 */
void destroyCNF(ptCNF formula) {
	if(formula) {
		destroyCNF(formula->conjunction);
		destroyClause(formula->clause);
		free(formula);
	}
}

/**
 * Checks whether clauses are equal literal by literal.
 * The "limit" parameter makes this into an approximation, meaning
 * the function will only check clauses of that length, everything
 * of greater size will be considered different.
 */
byte clausesEqual(ptClause a, ptClause b, short limit) {
	while(limit > 0) {
		if(!a && !b) return 1;
		if(!a || !b) return 0;
		if(a->lit != b->lit) return 0;
		a = a->disjunction;
		b = b->disjunction;
		limit--;
	}
	return 0;
}

/**
 * Conjunct a clause (a disjunction) and a CNF formula.  The clause will just be added in front of the CNF.
 * Returns a pointer to the new CNF (CNF could have been empty).
 * If a preserve* parameter is set, then the item in question will be duplicated before it is inserted into the formula.
 * Accepts NULL parameters (if one is NULL, the other will be returned).
 */
ptCNF addClauseConjunction(ptCNF formula, ptClause clause, byte preserveCNF, byte preserveClause) {
	if(!clause) {
		if(!preserveCNF) return formula;
		else return copyCNF(formula);
	}
#ifdef CNF_OPTIM
	ptCNF iter = formula;
	while(iter) {
		if(clausesEqual(clause, iter->clause, CNF_OPTIM_LIMIT)) {
			if(!preserveCNF) return formula;
			else return copyCNF(formula);
		}
		iter = iter->conjunction;
	}
#endif
	ptCNF newCNF = (ptCNF) malloc (sizeof(tCNF));
	if(!newCNF) failure("Out of memory (creating CNF).\n");

	if(preserveClause) newCNF->clause = copyClause(clause);
	else newCNF->clause = clause;

	if(preserveCNF == 0) newCNF->conjunction = formula;
	else newCNF->conjunction = copyCNF(formula);
	return newCNF;
}

/**
 * Will create a clause by merging the two input clauses.
 * Both are supposed to be ordered.  The function will NOT preserve the input clauses.
 *
 * ATTENTION: The function will return NULL if the disjunction results in a tautology.
 */
ptClause disjunctClauses(ptClause a, ptClause b) {
	if(a == NULL) {
		return b;
	} else if(b == NULL) {
		return a;
	} else {
		#ifdef PROFILE_CNF
			PROFILER_START(pr_disjunctClauses);
		#endif
		// Step through both lists and interleave by moving elements from b into a.
		ptClause tail = NULL, head = NULL;
		ptClause temp1, temp2;

		// printf("a = ");printClause(a);printf("\n");
		// printf("b = ");printClause(b);printf("\n");

		while(b) {
			// printf("b->lit = %d  /  a->lit = %d  /  result->lit = %d\n", b->lit, a ? a->lit : 0, tail ? tail->lit : 0);

			if(a && abs(a->lit) < abs(b->lit)) {
				// printf(" A - advance in a\n");
				temp2 = a->disjunction;
				if(tail) tail->disjunction = a;
				tail = a;
				tail->disjunction = NULL;
				a = temp2;
			} else {
				temp1 = b->disjunction;
				if(!a) {
					// printf(" B.1 - insert b at tail\n");
					// insert b at tail
					if(tail) tail->disjunction = b;
					tail = b;
					tail->disjunction = NULL;
				} else if(a->lit == b->lit) {
					// printf(" B.3 - do not insert, the copy from a is going to be inserted\n");
					// do not insert, the copy from a is going to be inserted
					free(b);
				} else if(abs(a->lit) == abs(b->lit)) {
					// printf(" B.2 - both nodes can be ignored, advance in both, and free both\n");
					// both nodes can be ignored, advance in both, and free both
					temp2 = a->disjunction;
					free(a);
					free(b);
					a = temp2;
				} else {
					// printf(" B.4 - insert in the middle, in front of anode\n");
					// insert in the middle, in front of anode
					if(tail) tail->disjunction = b;
					tail = b;
					tail->disjunction = NULL;
				}
				b = temp1;
			}

			if(!head) head = tail;
			// printf(" --> result->lit = %d\n", tail ? tail->lit : 0);
		}

		if(tail) tail->disjunction = a;
		else head = a;

		#ifdef PROFILE_CNF
			PROFILER_END(pr_disjunctClauses);
		#endif
		return head;
	}
}

/**
 * Disjunct a clause (a disjunction already) and a CNF formula.  The clause will just be appended to each clause of the CNF.
 * Returns a pointer to the new CNF (CNF could have been empty).
 * If a preserve* parameter is set, then the item in question will be duplicated before it is inserted into the formula.
 * Accepts NULL parameters (if one is NULL, the other will be returned).
 *
 * ATTENTION: This function will also return NULL if none of the parameters is NULL, but the resulting formula would be a tautology.
 */
ptCNF addClauseDisjunction(ptCNF formula, ptClause clause, byte preserveCNF, byte preserveClause) {
	ptCNF result;

	if(!formula && !clause) return NULL;
	else if(!formula) return addClauseConjunction(NULL, clause, preserveCNF, preserveClause);
	else if(!clause) return addClauseConjunction(formula, NULL, preserveCNF, preserveClause);

	if(preserveCNF == 0) result = formula;
	else				 result = copyCNF(formula);

	// Add the clause to each of the clauses that already there
	ptCNF currentCNF = result;
	ptCNF tail = NULL, temp = NULL;
	result = NULL;
	while(currentCNF) {
		temp = currentCNF->conjunction;
		//currentCNF->clause = disjunctClauses(currentCNF->clause, (temp != NULL || preserveClause) ? copyClause(clause) : clause);
		currentCNF->clause = disjunctClauses(currentCNF->clause, copyClause(clause));

		if(currentCNF->clause) {
			// Add clause
			if(tail) tail->conjunction = currentCNF;
			currentCNF->conjunction = NULL;
			tail = currentCNF;
		} else {
			free(currentCNF);
		}
		currentCNF = temp;

		if(!result) result = tail;
	}

	if(!preserveClause) destroyClause(clause);
	return result;
}


/**
 * Negate a clause (a disjunction); the result is a CNF formula (a conjunction).
 * This function does not preserve the original formula.
 * For example: negateClause(a | b) will return: -b & -a.
 */
ptCNF negateClause(ptClause clause) {
	if(!clause)	return NULL;
	ptClause currentClause = clause;
	ptCNF negation = (ptCNF) malloc(sizeof(tCNF));
	if(!negation)	failure("Out of memory (creating CNF).\n");

	negation->clause = (ptClause) malloc(sizeof(tClause));
	if(!negation->clause) failure("Out of memory (creating clause).\n");
	negation->clause->lit = -(currentClause->lit);
	negation->clause->disjunction = NULL;

	ptCNF currentNeg = negation;
	while(currentClause->disjunction) {
		currentNeg->conjunction = (ptCNF) malloc(sizeof(tCNF));
		if(!currentNeg->conjunction) failure("Out of memory (creating CNF).\n");

		currentNeg->conjunction->clause = (ptClause) malloc(sizeof(tClause));
		if(!currentNeg->conjunction->clause) failure("Out of memory (creating clause).\n");

		currentNeg->conjunction->clause->lit = -(currentClause->disjunction->lit);
		currentNeg->conjunction->clause->disjunction = NULL;
		currentNeg = currentNeg->conjunction;
		currentClause = currentClause->disjunction;
	}
	currentNeg->conjunction = NULL;
	return negation;
}

/**
 * Conjunct two CNF.  They are basically attached to one another.
 * Returns the pointer to the new formula (the original one could have been empty).
 * If a preserve* parameter is set, then the item in question will be duplicated before it is inserted into the formula.
 * Accepts NULL pointers; if one input is NULL, the other is returned.
 */
ptCNF addCNFConjunction(ptCNF left, ptCNF right, byte preserveLeft, byte preserveRight) {
	#ifdef PROFILE_CNF
		PROFILER_START(pr_addCNFConjunction);
	#endif

	ptCNF result;
	if(preserveLeft == 0) result = left;
	else result = copyCNF(left);
	if(!result) {
		#ifdef PROFILE_CNF
			PROFILER_END(pr_addCNFConjunction);
		#endif
		if(preserveRight == 0) return right;
		else return copyCNF(right);
	}

	if(preserveRight) right = copyCNF(right);

#ifdef CNF_OPTIM
	{
		ptCNF tail = NULL;
		ptCNF temp;
		ptCNF iter1 = right;
		ptCNF iter2;
		byte equal;
		right = NULL;
		while(iter1) {
			iter2 = left;
			equal = 0;
			while(!equal && iter2) {
				if(clausesEqual(iter1->clause, iter2->clause, CNF_OPTIM_LIMIT)) equal = 1;
				iter2 = iter2->conjunction;
			}

			temp = iter1->conjunction;
			if(equal) {
				iter1->conjunction = NULL;
				destroyCNF(iter1);
			} else {
				if(tail) tail->conjunction = iter1;
				tail = iter1;
				tail->conjunction = NULL;
			}

			if(!right) right = tail;
			iter1 = temp;
		}
	}
#endif

	ptCNF currentCNF = result;
	while(currentCNF->conjunction) currentCNF = currentCNF->conjunction;
	currentCNF->conjunction = right;

	#ifdef PROFILE_CNF
		PROFILER_END(pr_addCNFConjunction);
	#endif
	return result;
}

/**
 * Disjunct two CNF.  The right one is distributed over the left one.
 * Returns the pointer to the new formula (the original one could have been empty).
 * If a preserve* parameter is set, then the item in question will be duplicated before it is inserted into the formula.
 * Accepts NULL pointers; if one input is NULL, the other is returned.
 *
 * ATTNETION, this function will return NULL if the result is a tautology!
 */
ptCNF addCNFDisjunction(ptCNF left, ptCNF right, byte preserveLeft, byte preserveRight) {
	if(!left &&  preserveRight) return copyCNF(right);
	if(!left && !preserveRight) return right;
	if(!right &&  preserveLeft) return copyCNF(left);
	if(!right && !preserveLeft) return left;

	#ifdef PROFILE_CNF
		PROFILER_START(pr_addCNFDisjunction);
	#endif

	ptCNF willy;
	ptCNF curElt = right;
	ptCNF result = NULL;
	ptCNF temp;

	while(curElt) {
		willy = curElt;
		temp = addClauseDisjunction(left, curElt->clause, (curElt->conjunction != NULL) || preserveLeft ? 1 : 0, preserveRight);
		result = addCNFConjunction(result, temp, 0, 0);
		curElt = curElt->conjunction;
		if(!preserveRight) free(willy);
	}

	#ifdef PROFILE_CNF
		PROFILER_END(pr_addCNFDisjunction);
	#endif
	return result;
}


/**
 * Creates a CNF which is the negation of another formula in CNF. Does NOT modify the original formula.
 * The principle is to negates every clause then add it to the current CNF negation using distributivity.
 * It does NOT modify the original formula.
 *
 * ATTENTION, this function will return NULL if the negation of a formula is a trivial tautology.
 * ATTENTION 2, it will also return NULL when the input is NULL; which is not compatible with the
 *              return type convention that NULL means true!  So check the input to be NOT NULL!
 */
ptCNF negateCNF(ptCNF formula) {
	#ifdef PROFILE_CNF
		PROFILER_START(pr_negateCNF);
	#endif

	ptCNF negation = NULL;
	ptCNF currentCNF = formula;
	while(currentCNF) {
		negation = addCNFDisjunction(negation, negateClause(currentCNF->clause), 0, 0);
		currentCNF = currentCNF->conjunction;
	}

	#ifdef PROFILE_CNF
		PROFILER_END(pr_negateCNF);
		if(PROFILER_CRITICAL(pr_negateCNF)) {
			printf(" +-> input size:  ");
			printCNFSize(formula);
			printf("\n");
			printf(" +-> output size: ");
			printCNFSize(negation);
			printf("\n");
		}
	#endif
	return negation;
}
/**
 * Prints the content of a clause.
 */
void printClause(ptClause clause) {
	ptClause currClause = clause;
	char* fname;
	while(currClause) {

		fname = getFeatureIDName((int) abs(currClause->lit));
		if(fname == NULL) printf("%s%d", currClause->lit < 0 ? "!" : "", (int) abs(currClause->lit));
		else printf("%s%s",  (currClause->lit < 0 ? "!" : ""), fname);
		if(currClause->disjunction) printf(" | ");
		currClause = currClause->disjunction;
	}
}

/**
 * Prints the content of a CNF; ids are supposed to be features.
 */
void printCNF(ptCNF formula) {
	ptCNF currentCNF = formula;
	while(currentCNF) {
		if(formula->conjunction && currentCNF->clause && currentCNF->clause->disjunction) printf("(");
		printClause(currentCNF->clause);
		if(formula->conjunction && currentCNF->clause && currentCNF->clause->disjunction) printf(")");
		if(currentCNF->conjunction) printf(" & ");
		currentCNF = currentCNF->conjunction;
	}
}

/**
 * Prints nb clauses, literals of the formula
 */
void printCNFSize(ptCNF formula) {
	ptClause clause;
	int nbClauses = 0;
	int nbLiterals = 0;
	while(formula) {
		nbClauses++;
		clause = formula->clause;
		while(clause) {
			nbLiterals++;
			clause = clause->disjunction;
		}
		formula = formula->conjunction;
	}
	printf("%4d clauses, %4d literals, %.2f literals per clause", nbClauses, nbLiterals, nbLiterals == 0 ? 0.0 : ((double) nbLiterals / (double) nbClauses));
}
