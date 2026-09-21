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

/**
 * Initializes the solver with a formula.
 */
void initSolverWithFD(ptBoolFct formula) {

/*	Uncomment for the CFDP-FULL case study
 * ptBoolFct FD = getTrue();//formula;
	ptBoolFct Channel = createVariable("Channel.is_in");
	ptBoolFct Message = createVariable("Message.is_in");
	FD = addConjunction(Channel,FD,0,0);
	FD = addConjunction(Message,FD,0,0);

	ptBoolFct SIZE10 = createVariable("Message.size1");
	ptBoolFct SIZE20 = createVariable("Message.size2");
	ptBoolFct SIZE30 = createVariable("Message.size3");
	ptBoolFct SIZE40 = createVariable("Message.size4");
	ptBoolFct SIZE50 = createVariable("Message.size5");
	FD = addConjunction(addDisjunction(negateBool(SIZE50),SIZE40,0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(SIZE40),SIZE30,0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(SIZE30),SIZE20,0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(SIZE20),SIZE10,0,0),FD,0,0);
	FD = addConjunction(SIZE10,FD,0,0);


	ptBoolFct Entity0 = createVariable("Entity[0].is_in");
	ptBoolFct SND_MIN0 = createVariable("Entity[0].SND_MIN.is_in");
	ptBoolFct SND_MIN_ACK0 = createVariable("Entity[0].SND_MIN.SND_MIN_ACK.is_in");
	ptBoolFct SND_PROMPT_NAK0 = createVariable("Entity[0].SND_MIN.SND_MIN_ACK.SND_PROMPT_NAK");
	ptBoolFct RECV_MIN0 = createVariable("Entity[0].RCV_MIN.is_in");
	ptBoolFct RECV_MIN_ACK0 = createVariable("Entity[0].RCV_MIN.RCV_MIN_ACK.is_in");
	ptBoolFct RECV_IMMEDIATE_NAK0 = createVariable("Entity[0].RCV_MIN.RCV_MIN_ACK.RCV_IMMEDIATE_NAK");
	ptBoolFct RECV_DEFERRED_NAK0 = createVariable("Entity[0].RCV_MIN.RCV_MIN_ACK.RCV_DEFERRED_NAK");
	ptBoolFct RECV_PROMPT_NAK0 = createVariable("Entity[0].RCV_MIN.RCV_MIN_ACK.RCV_PROMPT_NAK");
	ptBoolFct RECV_ASYNCH_NAK0 = createVariable("Entity[0].RCV_MIN.RCV_MIN_ACK.RCV_ASYNCH_NAK");
	ptBoolFct TOUT10 = createVariable("Entity[0].SND_MIN.tout1");
	ptBoolFct TOUT20 = createVariable("Entity[0].SND_MIN.tout2");
	ptBoolFct TOUT30 = createVariable("Entity[0].SND_MIN.tout3");
	ptBoolFct TOUT40 = createVariable("Entity[0].SND_MIN.tout4");
	ptBoolFct TOUT40 = createVariable("Entity[0].SND_MIN.tout5");


	// Add attributes variable and define exclusive constraints
	FD = addConjunction(Entity0,FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(SND_PROMPT_NAK0),SND_MIN_ACK0,0,1),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(SND_MIN_ACK0),SND_MIN0,0,1),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_MIN_ACK0),RECV_MIN0,0,1),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_IMMEDIATE_NAK0),RECV_MIN_ACK0,0,1),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_DEFERRED_NAK0),RECV_MIN_ACK0,0,1),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_PROMPT_NAK0),RECV_MIN_ACK0,0,1),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_ASYNCH_NAK0),RECV_MIN_ACK0,0,1),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_IMMEDIATE_NAK0),negateBool(RECV_DEFERRED_NAK0),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_IMMEDIATE_NAK0),negateBool(RECV_PROMPT_NAK0),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_IMMEDIATE_NAK0),negateBool(RECV_ASYNCH_NAK0),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_DEFERRED_NAK0),negateBool(RECV_IMMEDIATE_NAK0),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_DEFERRED_NAK0),negateBool(RECV_PROMPT_NAK0),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_DEFERRED_NAK0),negateBool(RECV_ASYNCH_NAK0),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_PROMPT_NAK0),negateBool(RECV_IMMEDIATE_NAK0),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_PROMPT_NAK0),negateBool(RECV_DEFERRED_NAK0),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_PROMPT_NAK0),negateBool(RECV_ASYNCH_NAK0),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_ASYNCH_NAK0),negateBool(RECV_IMMEDIATE_NAK0),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_ASYNCH_NAK0),negateBool(RECV_DEFERRED_NAK0),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_ASYNCH_NAK0),negateBool(RECV_PROMPT_NAK0),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(TOUT50),TOUT40,0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(TOUT40),TOUT30,0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(TOUT30),TOUT20,0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(TOUT20),TOUT10,0,0),FD,0,0);

	ptBoolFct Entity1 = createVariable("Entity[1].is_in");
	ptBoolFct SND_MIN1 = createVariable("Entity[1].SND_MIN.is_in");
	ptBoolFct SND_MIN_ACK1 = createVariable("Entity[1].SND_MIN.SND_MIN_ACK.is_in");
	ptBoolFct SND_PROMPT_NAK1 = createVariable("Entity[1].SND_MIN.SND_MIN_ACK.SND_PROMPT_NAK");
	ptBoolFct RECV_MIN1 = createVariable("Entity[1].RCV_MIN.is_in");
	ptBoolFct RECV_MIN_ACK1 = createVariable("Entity[1].RCV_MIN.RCV_MIN_ACK.is_in");
	ptBoolFct RECV_IMMEDIATE_NAK1 = createVariable("Entity[1].RCV_MIN.RCV_MIN_ACK.RCV_IMMEDIATE_NAK");
	ptBoolFct RECV_DEFERRED_NAK1 = createVariable("Entity[1].RCV_MIN.RCV_MIN_ACK.RCV_DEFERRED_NAK");
	ptBoolFct RECV_PROMPT_NAK1 = createVariable("Entity[1].RCV_MIN.RCV_MIN_ACK.RCV_PROMPT_NAK");
	ptBoolFct RECV_ASYNCH_NAK1 = createVariable("Entity[1].RCV_MIN.RCV_MIN_ACK.RCV_ASYNCH_NAK");
	ptBoolFct TOUT11 = createVariable("Entity[1].SND_MIN.tout1");
	ptBoolFct TOUT21 = createVariable("Entity[1].SND_MIN.tout2");
	ptBoolFct TOUT31 = createVariable("Entity[1].SND_MIN.tout3");
	ptBoolFct TOUT41 = createVariable("Entity[1].SND_MIN.tout4");
	ptBoolFct TOUT41 = createVariable("Entity[1].SND_MIN.tout5");

	FD = addConjunction(Entity1,FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(SND_PROMPT_NAK1),SND_MIN_ACK1,0,1),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(SND_MIN_ACK1),SND_MIN1,0,1),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_MIN_ACK1),RECV_MIN1,0,1),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_IMMEDIATE_NAK1),RECV_MIN_ACK1,0,1),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_DEFERRED_NAK1),RECV_MIN_ACK1,0,1),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_PROMPT_NAK1),RECV_MIN_ACK1,0,1),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_ASYNCH_NAK1),RECV_MIN_ACK1,0,1),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_IMMEDIATE_NAK1),negateBool(RECV_DEFERRED_NAK1),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_IMMEDIATE_NAK1),negateBool(RECV_PROMPT_NAK1),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_IMMEDIATE_NAK1),negateBool(RECV_ASYNCH_NAK1),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_DEFERRED_NAK1),negateBool(RECV_IMMEDIATE_NAK1),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_DEFERRED_NAK1),negateBool(RECV_PROMPT_NAK1),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_DEFERRED_NAK1),negateBool(RECV_ASYNCH_NAK1),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_PROMPT_NAK1),negateBool(RECV_IMMEDIATE_NAK1),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_PROMPT_NAK1),negateBool(RECV_DEFERRED_NAK1),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_PROMPT_NAK1),negateBool(RECV_ASYNCH_NAK1),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_ASYNCH_NAK1),negateBool(RECV_IMMEDIATE_NAK1),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_ASYNCH_NAK1),negateBool(RECV_DEFERRED_NAK1),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(RECV_ASYNCH_NAK1),negateBool(RECV_PROMPT_NAK1),0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(TOUT51),TOUT41,0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(TOUT41),TOUT31,0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(TOUT31),TOUT21,0,0),FD,0,0);
	FD = addConjunction(addDisjunction(negateBool(TOUT21),TOUT11,0,0),FD,0,0);*/

	_FDFormula = formula;
	_BaseFDFormula = copyBool(_FDFormula);
}

void reinitSolverWithFD() {
    destroyBool(_FDFormula);
    _FDFormula = _BaseFDFormula;
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
extern DdManager* _manager;
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
	if(fct == Cudd_ReadLogicZero(_manager) || fct == Cudd_ReadZero(_manager)) res = 0;
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
	if(fct && (fct == Cudd_Not(Cudd_ReadLogicZero(_manager)) || fct == Cudd_Not(Cudd_ReadZero(_manager)))) return 1;
	/*ptBoolFct negation = negateBool(fct);
	byte sat = isSatisfiable(negation);
	destroyBool(negation);*/
#ifdef TIME
	satTime += (clock() - c);
#endif
#ifdef PROFILE_SAT
	PROFILER_END(pr_isTautology);
#endif
	return 0;
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
