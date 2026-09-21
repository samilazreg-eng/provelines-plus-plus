/*
 * STACK
 * * * * * * * * * * * * * * * * * * * * * * * */

struct stack_ {
	void * value;
	struct stack_ * prev;
};

typedef struct stack_ stack;
typedef struct stack_ * ptStack;


void destroyStack(ptStack stackPtr); // Destroys the stack (but not the contained value).
void * top(ptStack stackPtr); // Returns the top value of the stack.
ptStack push(ptStack stackPtr, void * value); // Add 'value' on top of the stack.
void * pop(ptStack * stackPtr); // Returns and removes the top value of the stack.
unsigned char empty(ptStack stackPtr); // Returns 1 if 'stackPtr' is empty, 0 otherwise.
int stackCount(ptStack stackPtr); // Returns the size of the stack.
unsigned char onStack(ptStack stackPtr, void * value, int length); // Returns 1 if the content of a given memory chunk up to a given length can be found on the stack; 0 otherwise.
ptStack reverse(ptStack stackPtr, unsigned char preserve); // Returns the stack obtained by reversing 'stackPtr'. If 'preserve' = 1, 'stackPtr' is left untouched; otherwise, 'stackPtr' is emptied.
