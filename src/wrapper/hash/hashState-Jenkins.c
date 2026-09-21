#include <stdlib.h>
#include "error.h"
#include "main.h"
#include "list.h"
#include "stack.h"
#include "boolFct.h"
#include "symbols.h"
#include "automata.h"
#ifdef CLOCK
	#include "clockZone.h"
#endif
#include "state.h"

#define VALGRIND
#include "lookup3.c"
#include "hashState.h"

unsigned int hashState(ptState state) {
	// The value 12345 is just one arbitrary value requested by Jenkins' function.
	// See the description of hashlittle() for more information.
	return hashlittle(state->payload, state->payloadSize, 12345);
}
