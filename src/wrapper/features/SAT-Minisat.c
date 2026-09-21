#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "main.h"
#include "cnf.h"
#include "boolFct.h"
#include "SAT.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This implementation of the the SAT wrapper uses the MiniSat library.  *
 * See ../lib/minisat/core/interface.h                                   *
 * There are two solvers:                                                *
 *  - The "main" solver is always loaded with the CNF of the feature     *
 *    diagram.  The function isSatisfiableWrtFD() then checks            *
 *    satisfiability of an arbitrary CNF against the CNF of the FD using *
 *    this solver.                                                       *
 *  - The "temporary" solver is used to check "normal" satisfaction,     *
 *    implication, and tautology.  It is created anew for each check.    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

static int _solverUses = 0; // counts the number of times the FD solver was used, after SAT_REINITIALISE times, it is reinitialised
static ptBoolFct _FDFormula = NULL;	// the formula of the FD
static ptBoolFct _BaseFDFormula = NULL; // the formula of the original FD

/**
 * Initializes the solver with a formula.
 */
void initSolverWithFD(ptBoolFct formula) {
	if(formula) {
		if(_FDFormula) destroyBool(_FDFormula);
		if(_BaseFDFormula) destroyBool(_BaseFDFormula);
		ptCNF cnf = (ptCNF)formula;
		_FDFormula = formula;
		minisat_mainSolverCreate();
		while(cnf) {
			minisat_mainSolverAddClause(cnf->clause);
			cnf = cnf->conjunction;
		}
		_BaseFDFormula = copyBool(_FDFormula);
	}
}

void reinitialiseFD() {
	destroyBool(_FDFormula);
	_FDFormula = copyBool(_BaseFDFormula);
}

/**
 * Modifies the FD formula by adding a constraint to it.
 * The resulting FD formula will be equal to: 'FD' && 'formula'.
 * WARNING: The formula of the constraint is NOT preserved.
 *
 * Returns:
 * 	- 1 iff the resulting FD is satisfiable (i.e. iff ('old.FD' && 'formula') is satisfiable)
 * 	- 0 otherwise.
 */
byte addConstraintToFD(ptBoolFct constraint) {
	_FDFormula = addConjunction(_FDFormula, constraint, 0, 0);
	ptCNF formula = (ptCNF) constraint;
	while(formula) {
		minisat_mainSolverAddClause(formula->clause);
		formula = formula->conjunction;
	}
	return minisat_mainSolverCheckSAT();
}

#ifdef PROFILE_SAT
	PROFILER_REGISTER(pr_isSatisfiableWrtFD, "isSatisfiableWrtFD", 1000);
	PROFILER_REGISTER(pr_isSatisfiable, "isSatisfiable", 1000);
	PROFILER_REGISTER(pr_isTautology, "isTautology", 1000);
	PROFILER_REGISTER(pr_implies, "implies", 1000);
	PROFILER_REGISTER(pr_impliesWrtFD, "impliesWrtFD", 1000);
#endif

/**
 * Uses temporary solver preloaded with the FD clauses, adds the formula, and checks
 * satisfiability.
 *
 * If the formula is NULL, the function will return true.
 */
byte isSatisfiableWrtFD(ptBoolFct fct) {
	if(!fct) return 1;
	ptCNF formula = (ptCNF) fct;
	#ifdef PROFILE_SAT
		PROFILER_START(pr_isSatisfiableWrtFD);
	#endif

	// Get ID of a temporary variable and count the number of times we do this
	_solverUses++;
	int temp = minisat_mainSolverGetNextVarId();
	while(formula) {
		// Add (~temp | clause) to the solver.
		// When solving, temp is used as an assumption, so that the added clauses are enforced.
		minisat_mainSolverAddTempClause(formula->clause, temp);
		formula = formula->conjunction;
	}

	// Check with the assumption of temp being true (so that the clauses we just added are taken into account).
	byte result = (minisat_mainSolverCheckSATAssump(temp) > 0);

	// Neutralise the clauses we just added by adding the clause ~temp
	// The clauses we just added are then trivially satisfied and not taken into account the next time.
	minisat_mainSolverRemoveTempClauses(temp);

	// After a certain number of iterations, we reinitialise the solver to get rid of all the temp variables.
	if (_solverUses >= SAT_REINITIALISE) {
		minisat_mainSolverDestroy();
		initSolverWithFD(_FDFormula);
		_solverUses = 0;
	}
	#ifdef PROFILE_SAT
		PROFILER_END(pr_isSatisfiableWrtFD);
	#endif
	return result;
}

byte isSatisfiableWrtBaseFD(ptBoolFct fct) {
	if(!fct) return 1;
	ptCNF conjunct = (ptCNF) addConjunction(fct, _BaseFDFormula, 1, 1);
	byte result = isSatisfiable(fct);
	destroyBool(conjunct);
	return result;
}

/**
 * Initialises a temporary solver, loads the formula, calls the solve function then destroys it.
 * If the formula is NULL, the function will return true.
 */
byte isSatisfiable(ptBoolFct fct) {
	if(!fct) return 1;
	ptCNF formula = (ptCNF) fct;
	#ifdef PROFILE_SAT
		PROFILER_START(pr_isSatisfiable);
	#endif
	minisat_tempSolverCreate();
	while(formula) {
		minisat_tempSolverAddClause(formula->clause);
		formula = formula->conjunction;
	}
	byte result = minisat_tempSolverCheckSAT();
	minisat_tempSolverDestroy();
	#ifdef PROFILE_SAT
		PROFILER_END(pr_isSatisfiable);
	#endif
	return result;
}

/**
 * WARNING: The two CNF are supposed to be not NULL.
 * Returns:
 * 	- 1 iff a -> b,
 *  - 0 otherwise.
 */
byte implies(ptBoolFct fct_a, ptBoolFct fct_b) {
	if(!fct_b) return 1; // (a -> true) is always true.
	if(!fct_a) return isTautology(fct_b); // (true -> b) iff b is a tautology.

	#ifdef PROFILE_SAT
		PROFILER_START(pr_implies);
	#endif
	byte result = 0;
	ptBoolFct notB = negateBool(fct_b);
	// negateBool might return NULL, which means the negation is a tautology
	if(!notB) result = !isSatisfiable(fct_a); // (a -> false) iff a is always false.
	else {
		ptBoolFct a_notImplies_b = addConjunction(fct_a, notB, 1, 0); /* (a & !b) */

		if(a_notImplies_b && !isSatisfiable(a_notImplies_b)) result = 1;
		destroyBool(a_notImplies_b);
	}

	#ifdef PROFILE_SAT
		PROFILER_END(pr_implies);
	#endif
	return result;
}

byte impliesWrtFD(ptBoolFct fct_a, ptBoolFct fct_b) {
	if(!fct_b) return 1; // (a -> true) is always true.
	if(!fct_a) return isTautologyWrtFD(fct_b); // (true -> b) iff b is a tautology wrt the FD.

	#ifdef PROFILE_SAT
		PROFILER_START(pr_impliesWrtFD);
	#endif
	byte result = 0;
	ptBoolFct notB = negateBool(fct_b);
	// negateBool might return NULL, which means the negation is a tautology
	if(!notB) result = !isSatisfiableWrtFD(fct_a); // (a -> false) iff a is always false.
	else {
		ptBoolFct a_notImplies_b = addConjunction(fct_a, notB, 1, 0); /* (a & !b) */

		if(a_notImplies_b && !isSatisfiableWrtFD(a_notImplies_b)) result = 1;
		destroyBool(a_notImplies_b);
	}

	#ifdef PROFILE_SAT
		PROFILER_END(pr_impliesWrtFD);
	#endif
	return result;
}

byte impliesWrtBaseFD(ptBoolFct fct_a, ptBoolFct fct_b) {
	if(!fct_b) return 1; // (a -> true) is always true.
	if(!fct_a) return isTautologyWrtBaseFD(fct_b); // (true -> b) iff b is a tautology wrt the FD.

	#ifdef PROFILE_SAT
		PROFILER_START(pr_impliesWrtFD);
	#endif
	byte result = 0;
	ptBoolFct notB = negateBool(fct_b);
	// negateBool might return NULL, which means the negation is a tautology
	if(!notB) result = !isSatisfiableWrtBaseFD(fct_a); // (a -> false) iff a is always false.
	else {
		ptBoolFct a_notImplies_b = addConjunction(fct_a, notB, 1, 0); /* (a & !b) */

		if(a_notImplies_b && !isSatisfiableWrtBaseFD(a_notImplies_b)) result = 1;
		destroyBool(a_notImplies_b);
	}

	#ifdef PROFILE_SAT
		PROFILER_END(pr_impliesWrtFD);
	#endif
	return result;
}

/**
 * The formula can be NULL, in which case the function returns true.
 */
byte isTautology(ptBoolFct fct) {
	if(!fct) return 1;
	#ifdef PROFILE_SAT
		PROFILER_START(pr_isTautology);
	#endif
	ptBoolFct negation = negateBool(fct);
	byte sat = isSatisfiable(negation);
	destroyBool(negation);
	#ifdef PROFILE_SAT
		PROFILER_END(pr_isTautology);
	#endif
	return !sat;
}

/**
 * The formula can be NULL, in which case the function returns true.
 */
byte isTautologyWrtFD(ptBoolFct fct) {
	if(!fct) return 1;
	#ifdef PROFILE_SAT
		PROFILER_START(pr_isTautology);
	#endif
	ptBoolFct negation = negateBool(fct);
	byte sat = isSatisfiableWrtFD(negation);
	destroyBool(negation);
	#ifdef PROFILE_SAT
		PROFILER_END(pr_isTautology);
	#endif
	return !sat;
}

/**
 * The formula can be NULL, in which case the function returns true.
 */
byte isTautologyWrtBaseFD(ptBoolFct fct) {
	if(!fct) return 1;
	#ifdef PROFILE_SAT
		PROFILER_START(pr_isTautology);
	#endif
	ptBoolFct negation = negateBool(fct);
	byte sat = isSatisfiableWrtBaseFD(negation);
	destroyBool(negation);
	#ifdef PROFILE_SAT
		PROFILER_END(pr_isTautology);
	#endif
	return !sat;
}
