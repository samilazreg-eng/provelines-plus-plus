#include <memory.h>
#include <setjmp.h>
#include "error.h"
#include "main.h"
#include "boolFct.h"
#include "SAT.h"

static Z3_ast FD = NULL;
static Z3_ast BaseFD;
static Z3_ast asserts = NULL;


void initSolverWithFD(ptBoolFct formula) {
	if(!ctx) initBoolFct();
	slv = Z3_mk_solver(ctx);
//	addAssert(getTrue());

	if(FD) destroyBool(FD);
	if(BaseFD) destroyBool(BaseFD);
	FD = getTrue();//formula;
	/* Uncomment for the CFDP-FULL case study
	ptBoolFct Channel = createVariable("Channel.is_in");
	ptBoolFct Message = createVariable("Message.is_in");
	FD = addConjunction(Channel,FD,0,0);
	FD = addConjunction(Message,FD,0,0);

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
	FD = addConjunction(addDisjunction(negateBool(RECV_ASYNCH_NAK1),negateBool(RECV_PROMPT_NAK1),0,0),FD,0,0); */


	//ptBoolFct P0 = createVariable("Processes[0]");
	//ptBoolFct P1 = createVariable("Processes[1]");
	//ptBoolFct P2 = createVariable("Processes[2]");
	//FD = addConjunction(addDisjunction(negateBool(P2),P1,0,0),addDisjunction(negateBool(P1),P0,0,0),0,0);
	BaseFD = copyBool(FD);
	Z3_solver_inc_ref(ctx, slv);
}


byte addConstraintToFD(ptBoolFct formula) {
#ifdef DEBUG
	printf("Begin addConstraintToFD\n");
#endif
	if(!ctx) initBoolFct();
	if(!FD) FD = formula;
	else FD = addConjunction(FD, formula, 0, 0);
	return isSatisfiableWrtFD(getTrue());
}


byte isSatisfiable(ptBoolFct formula) {
#ifdef DEBUG
	printf("Begin isSat\n");
#endif
#ifdef TIME
	satCalls++;
	clock_t c = clock();
#endif
	if(!ctx) initBoolFct();
	if(!slv) initSolverWithFD(NULL);
	Z3_solver_push(ctx, slv);
	if(formula)
		Z3_solver_assert(ctx, slv, formula);
	Z3_lbool res = Z3_solver_check(ctx, slv);
	Z3_solver_pop(ctx, slv, 1);
#ifdef TIME
	satTime += (clock() - c);
#endif
	return (res == Z3_L_TRUE);
}

byte isSatisfiableWrtFD(ptBoolFct formula) {
#ifdef DEBUG
	printf("Begin isSatFD\n");
#endif
#ifdef TIME
	satCalls++;
	clock_t c = clock();
#endif
	if(!ctx) initBoolFct();
	if(!slv) initSolverWithFD(NULL);
	Z3_solver_push(ctx, slv);
	Z3_solver_assert(ctx, slv, BaseFD);
	if(FD)
		Z3_solver_assert(ctx, slv, FD);
	if(formula)
		Z3_solver_assert(ctx, slv, formula);
	Z3_lbool res = Z3_solver_check(ctx, slv);
	Z3_solver_pop(ctx, slv, 1);
#ifdef TIME
	satTime += (clock() - c);
#endif
	return (res == Z3_L_TRUE);
}

byte isSatisfiableWrtBaseFD(ptBoolFct formula) {
#ifdef DEBUG
	printf("Begin isSatBaseFD\n");
#endif
#ifdef TIME
	satCalls++;
	clock_t c = clock();
#endif
	if(!ctx) initBoolFct();
	if(!slv) initSolverWithFD(NULL);
	Z3_solver_push(ctx, slv);
	Z3_solver_assert(ctx, slv, BaseFD);
	if(formula)
		Z3_solver_assert(ctx, slv, formula);
	Z3_lbool res = Z3_solver_check(ctx, slv);
	Z3_solver_pop(ctx, slv, 1);
#ifdef TIME
	satTime += (clock() - c);
#endif
	return (res == Z3_L_TRUE);
}


byte implies(ptBoolFct fct_a, ptBoolFct fct_b) {
#ifdef DEBUG
	printf("Begin implies: %s => %s\n",fct_a ? Z3_ast_to_string(ctx, fct_a) : "NULL", fct_b ? Z3_ast_to_string(ctx, fct_b) : "NULL");
#endif
#ifdef TIME
	junCalls += 2;
	clock_t c = clock();
#endif
	Z3_ast notImplies = Z3_mk_not(ctx, Z3_mk_implies(ctx, fct_a, fct_b));
#ifdef TIME
	junTime += (clock() - c);
#endif
	return !isSatisfiable(notImplies);
}

byte impliesWrtFD(ptBoolFct fct_a, ptBoolFct fct_b) {
#ifdef DEBUG
	printf("Begin impliesFD\n");
#endif
#ifdef TIME
	junCalls += 2;
	clock_t c = clock();
#endif
	Z3_ast notImplies = Z3_mk_not(ctx, Z3_mk_implies(ctx, fct_a, fct_b));
#ifdef TIME
	junTime += (clock() - c);
#endif
	return !isSatisfiableWrtFD(notImplies);
}

byte impliesWrtBaseFD(ptBoolFct fct_a, ptBoolFct fct_b) {
#ifdef DEBUG
	printf("Begin impliesBaseFD\n");
#endif
#ifdef TIME
	junCalls += 2;
	clock_t c = clock();
#endif
	Z3_ast notImplies = Z3_mk_not(ctx, Z3_mk_implies(ctx, fct_a, fct_b));
#ifdef TIME
	junTime += (clock() - c);
#endif
	return !isSatisfiableWrtBaseFD(notImplies);
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


byte isTautology(ptBoolFct formula) {
#ifdef DEBUG
	printf("Begin Tautology\n");
#endif
	ptBoolFct neg = negateBool(formula);
	return !isSatisfiable(neg);
}

byte isTautologyWrtFD(ptBoolFct formula) {
#ifdef DEBUG
	printf("Begin TautologyFD\n");
#endif
	ptBoolFct neg = negateBool(formula);
	return !isSatisfiableWrtFD(neg);
}

byte isTautologyWrtBaseFD(ptBoolFct formula) {
#ifdef DEBUG
	printf("Begin TautologyBase\n");
#endif
	ptBoolFct neg = negateBool(formula);
	return !isSatisfiableWrtBaseFD(neg);
}

/*void save() {
#ifdef DEBUG
	printf("Begin save\n");
#endif
	Z3_solver_push(ctx, slv);
}

void load() {
#ifdef DEBUG
	printf("Begin load\n");
#endif
	Z3_solver_pop(ctx, slv, 1);
	resetAsserts();
}

void addAssert(ptBoolFct assert) {
#ifdef DEBUG
	printf("Begin addAssert\n");
#endif
	if(assert) {
		Z3_solver_assert(ctx, slv, assert);
		if(asserts)
			asserts = addConjunction(asserts, assert, 0, 1);
	}
}

ptBoolFct getAsserts() {
#ifdef DEBUG
	printf("Begin getAsserts\n");
#endif
	if(!ctx) initBoolFct();
	if(asserts){printf("hihi\n");
		return asserts;}
	Z3_ast_vector v = Z3_solver_get_assertions(ctx,slv);
	int i;
	Z3_ast asserts;
	if(Z3_ast_vector_size(ctx,v) == 0)
		asserts = getTrue();
	else {
		asserts = Z3_ast_vector_get(ctx,v,0);
		for(i = 1; i < Z3_ast_vector_size(ctx,v); i++) {
			asserts = addConjunction(asserts, Z3_ast_vector_get(ctx,v,i), 0, 1);
		}
	}
	return asserts;
}

void resetAsserts() {
#ifdef DEBUG
	printf("Begin resetAsserts\n");
#endif
	destroyBool(asserts);
	asserts = NULL;
}*/
