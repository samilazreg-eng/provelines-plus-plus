#include <memory.h>
#include <setjmp.h>
#include "test_capi.c"
#include "error.h"
#include "main.h"
#include "symbols.h"
#include "boolFct.h"
#include "tvl.h"

void initBoolFct() {
	ctx = Z3_mk_context(Z3_mk_config());
	//ctx = Z3_mk_context_rc(Z3_mk_config());
}

ptBoolFct dimacsFileToBool(char * filePath) {
	if(!ctx) initBoolFct();
	return getTrue();
}

ptBoolFct createLiteral(int lit) {
	/*if(lit > 0)
		return createVariable(getFeatureIDName(lit));
	else
		return negateBool(createVariable(getFeatureIDName(lit)));*/
	return NULL;
}


ptBoolFct createConstraint(ptBoolFct var, int value, int type) {
	Z3_ast val = mk_int(ctx, value);
	Z3_ast args[2];
	args[0] = var;
	args[1] = val;
	switch(type) {
		case(E_EXPR_GT): return Z3_mk_gt(ctx, var, val);
		case(E_EXPR_GE): return Z3_mk_ge(ctx, var, val);
		case(E_EXPR_LT): return Z3_mk_lt(ctx, var, val);
		case(E_EXPR_LE): return Z3_mk_le(ctx, var, val);
		case(E_EXPR_EQ): return Z3_mk_eq(ctx, var, val);
		case(E_EXPR_NE): return Z3_mk_not(ctx, Z3_mk_eq(ctx, var, val));
		case(E_EXPR_PLUS): return Z3_mk_add(ctx, 2, args);
		case(E_EXPR_MINUS): return Z3_mk_sub(ctx, 2, args);
		case(E_EXPR_TIMES): return Z3_mk_mul(ctx, 2, args);
		case(E_EXPR_DIV): return Z3_mk_div(ctx, var, val);
		case(E_EXPR_MOD): return Z3_mk_mod(ctx, var, val);
		case(E_EXPR_UMIN): return Z3_mk_unary_minus(ctx, var);
		default : failure("Only (in)equality constraints on complex features are allowed.\n");
	}
}

ptBoolFct createConstraintVar(ptBoolFct var1, ptBoolFct var2, int type) {
	Z3_ast args[2];
	args[0] = var1;
	args[1] = var2;
	switch(type) {
		case(E_EXPR_GT): return Z3_mk_gt(ctx, var1, var2);
		case(E_EXPR_GE): return Z3_mk_ge(ctx, var1, var2);
		case(E_EXPR_LT): return Z3_mk_lt(ctx, var1, var2);
		case(E_EXPR_LE): return Z3_mk_le(ctx, var1, var2);
		case(E_EXPR_EQ): return Z3_mk_eq(ctx, var1, var2);
		case(E_EXPR_NE): return Z3_mk_not(ctx, Z3_mk_eq(ctx, var1, var2));
		case(E_EXPR_PLUS): return Z3_mk_add(ctx, 2, args);
		case(E_EXPR_MINUS): return Z3_mk_sub(ctx, 2, args);
		case(E_EXPR_TIMES): return Z3_mk_mul(ctx, 2, args);
		case(E_EXPR_DIV): return Z3_mk_div(ctx, var1, var2);
		case(E_EXPR_MOD): return Z3_mk_mod(ctx, var1, var2);
		default : failure("Only (in)equality constraints on complex features are allowed.\n");
	}
}

ptBoolFct createVariable(char * name) {
	if(!name) return NULL;
	if(!ctx) initBoolFct();
	createMapping(name);
	Z3_ast res =  mk_bool_var(ctx, name);
//	Z3_inc_ref(ctx, res);
	return res;
}

ptBoolFct createAttribute(char * name) {
	if(!name) return NULL;
	return mk_int_var(ctx, name);
}

ptBoolFct createConstant(int value) {
	return mk_int(ctx, value);
}

ptBoolFct addConjunction(ptBoolFct leftFct, ptBoolFct rightFct, byte preserveLeft, byte preserveRight) {
#ifdef DEBUG
	printf("Begin addConjunction: %s & %s\n", leftFct ? Z3_ast_to_string(ctx, leftFct) : "NULL", rightFct ? Z3_ast_to_string(ctx, rightFct) : "NULL");
#endif

	if(!ctx) initBoolFct();
	if(!leftFct && !preserveRight) return rightFct;
	else if (!leftFct && preserveRight) return copyBool(rightFct);

	if(!rightFct && !preserveLeft) return leftFct;
	else if(!rightFct && preserveLeft) return copyBool(leftFct);
#ifdef TIME
	clock_t c = clock();
	junCalls++;
#endif
	Z3_ast args[2];
	args[0] = leftFct;
	args[1] = rightFct;
	Z3_ast res = Z3_mk_and(ctx, 2, args);
//	Z3_inc_ref(ctx, res);
	if(!preserveLeft) destroyBool(leftFct);
	if(!preserveRight) destroyBool(rightFct);
	res = Z3_simplify(ctx, res);
#ifdef TIME
	junTime += (clock() - c);
#endif
	return res;
}

ptBoolFct addDisjunction(ptBoolFct leftFct, ptBoolFct rightFct, byte preserveLeft, byte preserveRight) {
#ifdef DEBUG
	printf("Begin addDisjunction\n");
#endif
	if(!ctx) initBoolFct();
	if(!leftFct && !preserveRight) return rightFct;
	else if (!leftFct && preserveRight) return copyBool(rightFct);

	if(!rightFct && !preserveLeft) return leftFct;
	else if(!rightFct && preserveLeft) return copyBool(leftFct);
#ifdef TIME
	clock_t c = clock();
	junCalls++;
#endif
	Z3_ast args[2];
	args[0] = leftFct;
	args[1] = rightFct;
	Z3_ast res = Z3_mk_or(ctx, 2, args);
//	Z3_inc_ref(ctx, res);
	if(!preserveLeft) destroyBool(leftFct);
	if(!preserveRight) destroyBool(rightFct);
	res = Z3_simplify(ctx, res);
#ifdef TIME
	junTime += (clock() - c);
#endif
	return res;
}

ptBoolFct copyBool(ptBoolFct formula) {
#ifdef DEBUGI
	printf("Begin copyBool\n");
#endif
	if(!formula)
		return NULL;
//	Z3_inc_ref(ctx, formula);
//	if(!formula) return NULL;
//	ptBoolFct t = getTrue();
//	ptBoolFct copy = addConjunction(formula, t, 1, 0);
	return formula;
}

ptBoolFct negateBool(ptBoolFct formula) {
#ifdef DEBUG
	printf("Begin negateBool: %s\n", formula ? Z3_ast_to_string(ctx, formula) : "NULL");
#endif
	if(!ctx) initBoolFct();
	if(!formula) return NULL;
#ifdef TIME
	clock_t c = clock();
	junCalls++;
#endif
	Z3_ast res = Z3_mk_not(ctx, formula);
//	Z3_inc_ref(ctx, res);
	res = Z3_simplify(ctx, res);
#ifdef TIME
	junTime += (clock() - c);
#endif
	return res;
}

ptBoolFct getTrue() {
#ifdef DEBUG
	printf("Begin getTrue\n");
#endif
	if(!ctx) initBoolFct();
	Z3_ast res = Z3_mk_true(ctx);
//	Z3_inc_ref(ctx, res);
	return res;
}

ptBoolFct getFalse() {
#ifdef DEBUG
	printf("Begin getTrue\n");
#endif
	if(!ctx) initBoolFct();
	Z3_ast res = Z3_mk_false(ctx);
//	Z3_inc_ref(ctx, res);
	return res;
}

void destroyBool(ptBoolFct formula) {
	if(!ctx) initBoolFct();
	//Z3_dec_ref(ctx, formula);
}

void printBool(ptBoolFct formula) {
	//display_ast(ctx, stdout, formula);
	if(formula)
		printf("%s\n",Z3_ast_to_string(ctx, formula));
	else
		printf("NULL\n");
}
