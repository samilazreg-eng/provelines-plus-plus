#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "stack.h"

/**
 * Destroys the stack and frees the memory allocated to it.
 */
void destroyStack(ptStack stackPtr) {
	ptStack temp;
	while(stackPtr) {
		temp = stackPtr->prev;
		free(stackPtr);
		stackPtr = temp;
	}
}

/**
 * Returns the value stored at the top of the stack.
 */
void* top(ptStack stackPtr) {
	if(!stackPtr) return NULL;
	return stackPtr->value;
}


/**
 * Adds an element at the top of the stateStack and returns the new stack.
 */
ptStack push(ptStack stackPtr, void* value) {
	ptStack newTop = (ptStack) malloc(sizeof(stack));
	if(!newTop) failure("Out of memory (creating stack node).\n");
	newTop->value = value;
	newTop->prev = stackPtr;
	return newTop;
}

/**
 * Removes and returns the top element of the stateStack.
 */
void* pop(ptStack* stackPtr) {
	if(empty(*stackPtr))
		return NULL;
	void* value = (*stackPtr)->value;
	ptStack prev = (*stackPtr)->prev;
	free(*stackPtr);
	*stackPtr = prev;
	return value;
}

/**
 * Returns 1 if the stateStack is empty.
 * Otherwise, returns 0.
 */
unsigned char empty(ptStack stackPtr) {
	return (stackPtr == NULL);
}

/**
 * Returns the number of elements on stack
 */
int stackCount(ptStack stackPtr) {
	ptStack stack_iter = stackPtr;
	int count = 0;
	while(stack_iter) {
		count++;
		stack_iter = stack_iter->prev;
	}
	return count;
}


/**
 * Returns 1 if the content of a given memory chunk up to a given length can be found on the stack.
 * In other words, the references of the pointer are not compared, but the content of the memory they point to is.
 * Otherwise, returns 0.
 */
unsigned char onStack(ptStack stackPtr, void* value, int length) {
	ptStack element = stackPtr;
	while(element) {
		if(memcmp(element->value, value, length) != 0)
			return 1;
		element = element->prev;
	}
	return 0;
}

/**
 * Reverses a stack.   Preserve true means keep the original stack.
 */
ptStack reverse(ptStack stack, unsigned char preserve) {
	if(!stack) return NULL;
	if(preserve) {
		ptStack new = NULL;
		while(stack) {
			new = push(new, stack->value);
			stack = stack->prev;
		}
		return new;
	} else {
		ptStack node, prev, nnode, nprev;
		node = stack;
		prev = stack->prev;
		stack->prev = NULL;
		while(node && prev)  {
			nnode = prev;
			nprev = prev->prev;
			prev->prev = node;
			node = nnode;
			prev = nprev;
		}
		return node;
	}
}
