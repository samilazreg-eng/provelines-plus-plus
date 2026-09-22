#!/usr/bin/env bash

set -e

cd ./parser/
if which flex &> /dev/null && which bison &> /dev/null; then
    rm lex.yy.c
	rm y.tab.h
	rm y.tab.c
	flex promela.l && bison -y -d promela.y 
else
    echo "Warning, flex or bison not found; using old files."
fi;
cd ..

cd ./lib/minisat/
export MROOT=..
cd core
if ! make libs; then
	echo "Warning: MiniSat did not build; continuing with the default CUDD backend." >&2
fi
cd ..
cd ..
cd ..

cd ./lib/ltl2ba/
make
cd ..
cd ..

cd ./lib/cudd/
make
cd ./util/
mv libutil.a libcuddutil.a
cd ..
cd ..
cd ..


#############################
# Major build-time choices: #
#############################

###############################################################
# Hashtable: 
#  - either a dynamic hashtable implementation by Clark
#  - or static Judy arrays (has memory leaks, not usable yet)
# Choose one *pair* of lines.
# Default: Clark.
HASHTABLE=wrapper/hash/hashtableState-Clark.c
JUDY=
#HASHTABLE=wrapper/hash/hashtableState-Judy.c
#JUDY=-lJudy

###############################################################
# Hashfunction: 
#  - either an implementatio by Jenkins
#  - or a basic modulo calculatation
# Default: Jenkins.
HASHFCT=wrapper/hash/hashState-Jenkins.c
#HASHFCT=wrapper/hash/hashState-RModulo.c

###############################################################
# Boolean function storage and analysis: 
#  - either storage as CNF structures analysed by Minisat
#  - or storage as and analysis with BDDs (Cudd) 
# Default: none.
#BOOL="wrapper/features/boolFct-cnf.c wrapper/features/SAT-Minisat.c -L./lib/minisat/core -l_standard"
BOOL="wrapper/features/boolFct-cudd.c wrapper/features/SAT-cudd.c -L./lib/cudd/cudd -L./lib/cudd/mtr -L./lib/cudd/st -L./lib/cudd/st -L./lib/cudd/epd -L./lib/cudd/util -lcudd -lmtr -lst -lepd -lcuddutil"
#BOOL="wrapper/features/boolFct-z3.c wrapper/features/SAT-z3.c -L./lib/z3 -lz3"

###############################################################
# Uncomment the following if you enabled real-time.
REALTIME=""
#REALTIME="wrapper/time/clockZone-dbm.c wrapper/time/federation.c -L./lib/UPPAAL-dbm/modules/lib -ldbm -lbase -ldebug -lhash -lio"


gcc -std=gnu99 -fgnu89-inline -Wno-error=implicit-function-declaration -o provelines main.c \
	parser/lex.yy.c \
	parser/y.tab.c \
	automata/symbols.c \
	automata/automata.c \
    logic/costFormula.c \
	semantics/state.c \
	semantics/execution.c \
	algorithms/checking.c \
	helper/error.c \
	helper/list.c \
	helper/stack.c \
	lib/clark.hashtable/hashtable.c \
	lib/clark.hashtable/hashtable_utility.c \
	lib/clark.hashtable/hashtable_itr.c \
	lib/RNGS/rngs.c \
	$BOOL \
	$HASHFCT \
	$HASHTABLE \
	$REALTIME \
	wrapper/features/tvl-javalib.c \
	wrapper/logic/ltl-ltl2ba.c \
	wrapper/hash/hashtableGen-Clark.c \
	\
	-I. -I./algorithms -I./automata -I./logic -I./helper -I./parser -I./semantics \
	-I./lib/clark.hashtable/  -I./lib/jenkins/ -I./lib/UPPAAL-dbm/modules/include -I./lib/z3/include/ -I./lib/cudd/include/ \
	-I./wrapper/features -I./wrapper/hash -I./wrapper/logic -I./wrapper/time \
	-lstdc++ -lm \
	$JUDY \
	$@
