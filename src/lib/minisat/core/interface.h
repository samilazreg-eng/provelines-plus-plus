#ifdef __cplusplus

#include "core/Solver.h"

extern "C" {
#endif

/* Main Solver */
void minisat_mainSolverCreate();
void minisat_mainSolverDestroy();
void minisat_mainSolverAddClause(ptClause clause);
void minisat_mainSolverAddTempClause(ptClause clause, int assump);
void minisat_mainSolverRemoveTempClauses(int assump);
int  minisat_mainSolverCheckSATAssump(int assump);
int  minisat_mainSolverCheckSAT();
int  minisat_mainSolverGetNextVarId();

/* Temporary Solver */
void minisat_tempSolverCreate();
void minisat_tempSolverDestroy();
void minisat_tempSolverAddClause(ptClause clause);
int  minisat_tempSolverCheckSAT();



#ifdef __cplusplus
}
#endif
