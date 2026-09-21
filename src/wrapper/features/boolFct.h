typedef void * ptBoolFct;

#ifdef Z3
	#include <z3.h>
	Z3_context ctx;
#endif

void initBoolFct(); // Initialise the feature handler. Must be called once before executing any other function.

ptBoolFct dimacsFileToBool(char * filePath); // Translates the content of a dimacs file into a formula and returns this formula.

ptBoolFct createLiteral(int lit); // Returns a literal 'f' where 'f' is the feature associated with the id 'lit'.
ptBoolFct createVariable(char * name); // Returns a literal 'name'. If 'name' is mapped to no id, also creates a mapping for 'name'.
#ifdef ATTR
	ptBoolFct createConstraint(ptBoolFct attr, int value, int type); // Returns a constraint on variable 'attr' and constant 'value'. The type of constraint is given by expression type 'type'.
	ptBoolFct createConstraintVar(ptBoolFct var1, ptBoolFct var2, int type); // Returns a constraint on variables 'var1' and 'var2'. The type of constraint is given by expression type 'type'.
	ptBoolFct createAttribute(char * name); // Returns a variable representing attribute 'name'.
	ptBoolFct createConstant(int value); // Returns a constant equal to 'value'.
#endif
ptBoolFct addConjunction(ptBoolFct leftFct, ptBoolFct rightFct, byte preserveLeft, byte preserveRight); // Returns the conjunction of 'leftFct' and 'rightFct'. 'leftFct' (resp. 'rightFct') is destroyed iff preserveLeft (resp. preserveRight) is 0.
ptBoolFct addDisjunction(ptBoolFct leftFct, ptBoolFct rightFct, byte preserveLeft, byte preserveRight); // Returns the disjunction of 'leftFct' and 'rightFct'. 'leftFct' (resp. 'rightFct') is destroyed iff preserveLeft (resp. preserveRight) is 0.
ptBoolFct copyBool(ptBoolFct formula); // Returns a copy of 'formula'.
ptBoolFct negateBool(ptBoolFct formula); // Returns the negation of 'formula'. 'formula' is neither destroyed nor modified.
ptBoolFct getTrue(); // Returns a tautology.
ptBoolFct getFalse(); // Returns an unsatisfiable formula.
void destroyBool(ptBoolFct formula); // Destroys 'formula'.
void printBool(ptBoolFct formula); // Prints 'formula'.
