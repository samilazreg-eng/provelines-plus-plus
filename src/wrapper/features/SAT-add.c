#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "main.h"
#include "mtr.h"
#include "epd.h"
#include "cudd.h"
#include "boolFct.h"
#include "SAT.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This implementation of the the SAT wrapper uses the cudd library.     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

static ptBoolFct _FDFormula;	// the formula of the FD
static ptBoolFct _BaseFDFormula; // the formula of the original FD

extern DdManager* _manager;

/**
 * Initializes the solver with a formula.
 */
void initSolverWithFD(ptBoolFct formula) {
	_FDFormula = formula;
	_BaseFDFormula = copyBool(_FDFormula);
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
byte addConstraintToFD(ptBoolFct formula) {
	_FDFormula = addConjunction(_FDFormula, formula, 0, 0);
	return isSatisfiable(_FDFormula);
}

#ifdef PROFILE_SAT
PROFILER_REGISTER(pr_isSatisfiableWrtFD, "isSatisfiableWrtFD", 1000);
PROFILER_REGISTER(pr_isSatisfiableWrtBaseFD, "isSatisfiableWrtBaseFD", 1000);
PROFILER_REGISTER(pr_isSatisfiable, "isSatisfiable", 1000);
PROFILER_REGISTER(pr_isTautology, "isTautology", 1000);
PROFILER_REGISTER(pr_implies, "implies", 1000);
PROFILER_REGISTER(pr_impliesWrtFD, "impliesWrtFD", 1000);
PROFILER_REGISTER(pr_impliesWrtBaseFD, "impliesWrtBaseFD", 1000);
#endif

/**
 * If the formula is NULL, the function will return true.
 */
byte isSatisfiableWrtFD(ptBoolFct fct) {
	if(!fct) return 1;
#ifdef PROFILE_SAT
	PROFILER_START(pr_isSatisfiableWrtFD);
#endif
	ptBoolFct temp = addConjunction(_FDFormula, fct, 1 , 1);
	byte result = isSatisfiable(temp);
	destroyBool(temp);
#ifdef PROFILE_SAT
	PROFILER_END(pr_isSatisfiableWrtFD);
#endif
	return result;
}

/**
 * If the formula is NULL, the function will return true.
 */
byte isSatisfiableWrtBaseFD(ptBoolFct fct) {
	if(!fct) return 1;
#ifdef PROFILE_SAT
	PROFILER_START(pr_isSatisfiableWrtBaseFD);
#endif
	ptBoolFct temp = addConjunction(_BaseFDFormula, fct, 1 , 1);
	byte result = isSatisfiable(temp);
	destroyBool(temp);
#ifdef PROFILE_SAT
	PROFILER_END(pr_isSatisfiableWrtBaseFD);
#endif
	return result;
}

/**
 * Check if a formula (represented as a BDD) is satisfiable.
 * If the formula is NULL, the function will return true.
 */

byte isSatisfiable(ptBoolFct fct) {
	if(!fct) return 1;
#ifdef PROFILE_SAT
	PROFILER_START(pr_isSatisfiable);

#endif
#ifdef TIME
	satCalls++;
	clock_t c = clock();
#endif
	byte res = 1;
	if(isLogicZero(fct)) res = 0;
#ifdef PROFILE_SAT
	PROFILER_END(pr_isSatisfiable);
#endif
#ifdef TIME
	satTime += (clock() - c);
#endif
	return res;
}

/**
 * WARNING: The two CNF are supposed to be not NULL.
 * Returns:
 * 	- 1 iff a -> b,
 *  - 0 otherwise.
 */
byte implies(ptBoolFct fct_a, ptBoolFct fct_b) {
	if(!fct_b) return 1; // (a -> true) is always true.
	if(!fct_a) return isTautology(fct_b);

#ifdef PROFILE_SAT
	PROFILER_START(pr_implies);
#endif
	byte result = Cudd_addGeq(_manager, fct_a, fct_b);
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
	PROFILER_START(pr_impliesWrtBaseFD);
#endif
	byte result = 0;

	ptBoolFct notB = negateBool(fct_b);
	// negateBool might return NULL, which means the negation is a tautology
	if(!notB) result = !isSatisfiableWrtFD(fct_a); // (a -> false) iff a is always false.
	else {
		ptBoolFct a_notImplies_b = addConjunction(fct_a, notB, 1, 0); /* (a & !b) */

		if(a_notImplies_b && !isSatisfiableWrtBaseFD(a_notImplies_b)) result = 1;
		destroyBool(a_notImplies_b);
	}

#ifdef PROFILE_SAT
	PROFILER_END(pr_impliesWrtBaseFD);
#endif
	return result;
}

byte equals(ptBoolFct fct_a, ptBoolFct fct_b) {
	if(!fct_b) return (!fct_a || isTautology(fct_b));
	if(!fct_a) return isTautology(fct_b);

	byte result = 0;
	ptBoolFct notB = negateBool(fct_b);
	ptBoolFct notA = negateBool(fct_a);
	ptBoolFct a_notImplies_b = addConjunction(fct_a, notB, 1, 0);
	ptBoolFct b_notImplies_a = addConjunction(fct_b, notA, 1, 0);
	ptBoolFct a_notEquals_b = addDisjunction(a_notImplies_b, b_notImplies_a, 0, 0);
	if(a_notEquals_b && !isSatisfiable(a_notEquals_b)) result = 1;
	destroyBool(a_notImplies_b);

	return result;
}

byte equalsWrtFD(ptBoolFct fct_a, ptBoolFct fct_b) {
	if(!fct_b) return (!fct_a || isTautologyWrtFD(fct_b));
	if(!fct_a) return isTautologyWrtFD(fct_b);

	byte result = 0;
	ptBoolFct notB = negateBool(fct_b);
	ptBoolFct notA = negateBool(fct_a);
	ptBoolFct a_notImplies_b = addConjunction(fct_a, notB, 1, 0);
	ptBoolFct b_notImplies_a = addConjunction(fct_b, notA, 1, 0);
	ptBoolFct a_notEquals_b = addDisjunction(a_notImplies_b, b_notImplies_a, 0, 0);
	if(a_notEquals_b && !isSatisfiableWrtFD(a_notEquals_b)) result = 1;
	destroyBool(a_notImplies_b);

	return result;
}

byte equalsWrtBaseFD(ptBoolFct fct_a, ptBoolFct fct_b) {
	if(!fct_b) return (!fct_a || isTautologyWrtBaseFD(fct_b));
	if(!fct_a) return isTautologyWrtBaseFD(fct_b);

	byte result = 0;
	ptBoolFct notB = negateBool(fct_b);
	ptBoolFct notA = negateBool(fct_a);
	ptBoolFct a_notImplies_b = addConjunction(fct_a, notB, 1, 0);
	ptBoolFct b_notImplies_a = addConjunction(fct_b, notA, 1, 0);
	ptBoolFct a_notEquals_b = addDisjunction(a_notImplies_b, b_notImplies_a, 0, 0);
	if(a_notEquals_b && !isSatisfiableWrtBaseFD(a_notEquals_b)) result = 1;
	destroyBool(a_notImplies_b);

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
#ifdef TIME
	satCalls++;
	clock_t c = clock();
#endif
	byte res = 0;
	ptBoolFct epsilon = createConstant(0.0000000001);
	if(implies(epsilon,fct)) res = 1;
#ifdef TIME
	satTime += (clock() - c);
#endif
#ifdef PROFILE_SAT
	PROFILER_END(pr_isTautology);
#endif
	destroyBool(epsilon);
	return res;
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

ptBoolFct getFD() {
	return _FDFormula;
}
