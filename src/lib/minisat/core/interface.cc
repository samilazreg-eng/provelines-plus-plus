extern "C" {
	#include "../../../main.h"
	#include "../../../helper/cnf.h"
}
#include "core/interface.h"


using namespace Minisat;

Solver * c_solver;
Solver * temp_solver;


/*
 * MAIN SOLVER USED TO CHECK SATISFIABILITY WITH REGARD TO THE FEATURE DIAGRAM
 */
void minisat_mainSolverCreate() {
    c_solver = new Solver();
}

void minisat_mainSolverDestroy() {
    if(c_solver) delete c_solver;
}

void minisat_mainSolverAddClause(ptClause clause) {
    ptClause currentClause = clause;
    vec<Lit> lits;
    int var;
    while(currentClause) {
		var = abs(currentClause->lit)-1;
		while (var >= (*c_solver).nVars()) (*c_solver).newVar();
		if (currentClause->lit > 0) lits.push( mkLit(var));
		else			 lits.push(~mkLit(var));
		currentClause = currentClause->disjunction;
    }
    (*c_solver).addClause(lits);
}

void minisat_mainSolverAddTempClause(ptClause clause, int assump) {
    ptClause currentClause = clause;
    vec<Lit> lits;
    int var;
    while(currentClause) {
		var = abs(currentClause->lit)-1;
		while (var >= (*c_solver).nVars()) (*c_solver).newVar();
		if (currentClause->lit > 0) lits.push( mkLit(var));
		else lits.push(~mkLit(var));
		currentClause = currentClause->disjunction;
    }
    var = abs(assump)-1;
    while (var >= (*c_solver).nVars()) (*c_solver).newVar();
    lits.push(~mkLit(var));
    (*c_solver).addClause(lits);
}

void minisat_mainSolverRemoveTempClauses(int assump) {
	vec<Lit> lits;
	lits.push(~mkLit(abs(assump)-1));
    (*c_solver).addClause(lits);
}

int minisat_mainSolverCheckSATAssump(int assump) {
	vec<Lit> assumps;
	int var = abs(assump)-1;
	if(assump > 0) assumps.push(mkLit(var));
	else assumps.push(~mkLit(var));
	lbool ret = (*c_solver).solveLimited(assumps);
	if(ret == l_True) return 1;
	else if(ret == l_False) return 0;
	else return -1;
}

int minisat_mainSolverCheckSAT() {
	vec<Lit> dummy;
	lbool ret = (*c_solver).solveLimited(dummy);
	if(ret == l_True) return 1;
	else if(ret == l_False) return 0;
	else return -1;
}

int minisat_mainSolverGetNextVarId() {
	return (*c_solver).nVars() +1;
}


/*
 * TEMPORARY SOLVER (USED TO CHECK IMPLICATION)
 */


void minisat_tempSolverCreate() {
    temp_solver = new Solver();
}

void minisat_tempSolverDestroy() {
    if(temp_solver) delete temp_solver;
}

void minisat_tempSolverAddClause(ptClause clause) {
	ptClause currentClause = clause;
    vec<Lit> lits;
    int var;
    while(currentClause) {
		var = abs(currentClause->lit)-1;
		while (var >= (*temp_solver).nVars()) (*temp_solver).newVar();
		if (currentClause->lit > 0) lits.push( mkLit(var));
		else			 lits.push(~mkLit(var));
		currentClause = currentClause->disjunction;
    }
    (*temp_solver).addClause(lits);
}

int minisat_tempSolverCheckSAT() {
    vec<Lit> dummy;
    lbool ret = (*temp_solver).solveLimited(dummy);
    if(ret == l_True) return 1;
    else if(ret == l_False) return 0;
    else return -1;
}
