#ifdef Z3
	#include <z3.h>
	Z3_solver slv;
#endif

/**
 * Initializes the solver with a formula.
 */
void initSolverWithFD(ptBoolFct formula);
void reinitSolverWithFD();

/**
 * Modifies the FD formula by adding a constraint to it.
 * The resulting FD formula will be equal to: 'old.FD' && 'formula'.
 * WARNING: The formula of the constraint is NOT preserved.
 *
 * Returns:
 * 	- 1 iff the resulting FD is satisfiable (i.e. iff ('old.FD' && 'formula') is satisfiable)
 * 	- 0 otherwise.
 */
byte addConstraintToFD(ptBoolFct formula);


/**
 * Checks whether or not a formula is satisfiable.
 */
byte isSatisfiable(ptBoolFct boolfct); // The formula itself
byte isSatisfiableWrtFD(ptBoolFct boolfct); // The conjunction of the formula and the (possibly modified) FD
byte isSatisfiableWrtBaseFD(ptBoolFct boolfct); // The conjunction of the formula and the initial FD


/**
 * Returns:
 * 	- 1 iff a -> b,
 *  - 0 otherwise.
 */
byte implies(ptBoolFct fct_a, ptBoolFct fct_b); // !(sat(!(a -> b)))
byte impliesWrtFD(ptBoolFct fct_a, ptBoolFct fct_b); // !(sat(FD && !(a -> b)))
byte impliesWrtBaseFD(ptBoolFct fct_a, ptBoolFct fct_b); // !(sat((baseFD && !(a -> b)))


/**
 * Returns:
 * 	- 1 iff a <-> b,
 *  - 0 otherwise.
 */
byte equals(ptBoolFct fct_a, ptBoolFct fct_b); // !(sat(!(a <-> b)))
byte equalsWrtFD(ptBoolFct fct_a, ptBoolFct fct_b); // !(sat(FD && !(a <-> b)))
byte equalsWrtBaseFD(ptBoolFct fct_a, ptBoolFct fct_b); // !(sat((baseFD && !(a <-> b)))


/**
 * Checks whether a formula is a tautology (negates it, which is costly).
 */
byte isTautology(ptBoolFct boolfct); // !(sat(!a))
byte isTautologyWrtFD(ptBoolFct boolfct); // !(sat(FD && !a))
byte isTautologyWrtBaseFD(ptBoolFct boolfct); // !(sat(baseFD && !a))

/*#ifdef Z3
	void save();
	void load();
	void addAssert(ptBoolFct assert);
	ptBoolFct getAsserts();
	void resetAsserts();
#endif
*/
