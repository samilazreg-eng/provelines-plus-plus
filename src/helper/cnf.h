/*
 * BOOLEAN EXPRESSIONS in CNF
 * * * * * * * * * * * * * * * * * * * * * * * */

struct clause_ {						// Clauses have to be ordered by literal, from smallest to largest absolute value
	int lit;							// When several literals have the same absolute value the negative have to come
	struct clause_ * disjunction;		// first; these things will be optimised away
};

typedef struct clause_ tClause;
typedef struct clause_ * ptClause;

struct CNF_ {
	ptClause clause;
	struct CNF_ * conjunction;
};

typedef struct CNF_ tCNF;
typedef struct CNF_* ptCNF;


ptCNF dimacsFileToCNF(char * filePath);
void CNFToDimacsFile(ptCNF formula, char * filePath);

ptCNF createCNFLiteral(int lit);
ptCNF addCNFConjunction(ptCNF left, ptCNF right, byte preserveLeft, byte preserveRight);
ptCNF addCNFDisjunction(ptCNF left, ptCNF right, byte preserveLeft, byte preserveRight);
ptCNF copyCNF(ptCNF formula);
ptCNF negateCNF(ptCNF formula);
void destroyCNF(ptCNF formula);
void printCNF(ptCNF formula);
void printCNFSize(ptCNF formula);
