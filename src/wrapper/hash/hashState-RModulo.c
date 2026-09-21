#include <stdlib.h>
#include "error.h"
#include "main.h"
#include "list.h"
#include "stack.h"
#include "boolFct.h"
#include "symbols.h"
#include "automata.h"
#include "state.h"
#include "hashState.h"



/**
 * Returns a hash of the content of a memory chunk based on
 * repeated application of the modulo operator.
 * This operator is applied successively on groups composed of 4 bytes.
 */
unsigned int hashRepeatedModulo(void * value, int length, int modulo) {
	int i;
	unsigned int currentHash = 0;
	unsigned int newVal;
	unsigned int * components = (unsigned int*)value;
	for(i = 0; i < (length/sizeof(unsigned int)); i++) {
		newVal = *(components+i);
		currentHash = (currentHash + newVal) % modulo;
	}
	return currentHash;
}

/**
 * Returns the hash value of a state. If the state is NULL, returns -1.
 * WARNING: As it returns -1 in the NULL case, it supposes the hash function
 * CANNOT return a negative value. However, if it does, the -1 return has to be
 * modified in order to return a value that the hash function does not.
 */
unsigned int hashState(ptState state) {
	if (!state) return 0;
	return hashRepeatedModulo(state->payload, state->payloadSize, HASHTABLE_MODULO);
}
