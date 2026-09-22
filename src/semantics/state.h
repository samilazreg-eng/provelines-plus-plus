#ifdef CLOCK
#include "clockZone.h"
#endif

/*
 * ENCODING OF STATES
 * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * A state consists of a set of active processes and of the values of the
 * variables of these processes.  It is thus represented by two elements:
 *
 *  - A list of active processes, and for each a pointer to its symbol table.
 *
 *  - A block of memory containing the variables of these processes.  This is
 *    more efficient than a linked list of values and basically corresponds to
 *    a run-time struct.
 *
 *    The block is divided into sub-blocks, one for each process.  The
 *    list of processes contains the offsets of the sub-block of each process.
 *    One sub-block holds all variable values in the order in which they
 *    were declared in the symbol table of the process.  For each variable, a
 *    predefined chunk of memory is allocated (all variable types are finite
 *    and cannot grow).
 *
 *
 * To test equivalence of two states, it is sufficient to test equivalence of
 * payloadSize, and if equivalent, the whole blocks.
 */

struct context_ {
	char * name;
	ptExpNode expression;
	int index;
};
typedef struct context_ tContext;
typedef struct context_* ptContext;

// A state mask gives for every process the pid, a pointer to its symtab node
// and its offset in the payload
struct stateMask_ {
	ptSymTabNode process;
	int pid;					// List of processes and their offset in the state
	unsigned int offset; 		// Offset of the process in the chunk of memory.
								// The address of the process current node can be found in the payload at offset 'offset - sizeof(void *)'.
	ptContext context;			// FM context of the process.
	struct stateMask_* next;
};

typedef struct stateMask_   tStateMask;
typedef struct stateMask_* ptStateMask;


// A channel ref gives for every channel the offset.
struct channelRef_ {
	unsigned int channelOffset;
	ptSymTabNode symTab;
	struct channelRef_ * next;
};

typedef struct channelRef_    tChannelRef;
typedef struct channelRef_ * ptChannelRef;


// State
struct state_ {
	ptStateMask mask; 	// Points to the global (first) stateMask.
	ptStateMask last; 	// Points to the last stateMask.
	ptStateMask never; 	// If f is an LTL formula to be checked, never is the stateMask conversion of ~f.
								//	Furthermore, never->node returns the current node in this FSM. Note that pid and offset have no importance here.
								//	Also, never->next is supposed to be NULL.

	ptChannelRef chanRefs;		// References of the channel declared in a process or as a global variable.

	int nbProcesses; 			// Number of running processes.
	int lastStepPid; 			// pid of the process that fired transition that got us into this state. (NOT part of the actual state of the system, just a helper)
	void* payload; 				// Chunk of memory containing the data.
	unsigned int payloadSize;	// Number of bytes currently allocated to payload.
	unsigned int payloadHash;	// Hash of the state, used to avoid memcmp() when comparing states on the stack.  This hash is NOT maintained by
								// by the functions that change states, it is only updated in checking.c.

	ptBoolFct features;			// Boolean formula representing the products in which the state can be reached.
#ifdef CLOCK
	ptClockZone zone;			// Reachable clock valuations (not stored in the payload).
	ptClockZone invariant;		// Location invariant; not part of discrete-state identity.
#endif
    int time;                   // The global time at which the state has been reached
    int cost;
    int qualityLoss;
};

typedef struct state_   tState;
typedef struct state_* ptState;


/*
 * API
 * * * * * * * * * * * * * * * * * * * * * * * */

// Access and modification of variables
ptFsmNode getNodePointer(ptState state, ptStateMask mask); // Returns the current FSM node of process 'mask' in 'state'.
void storeNodePointer(ptState state, ptStateMask mask, ptFsmNode pointer); // Set the current FSM node of process 'mask' in 'state' as 'pointer'.

/*
 * Returns the offset of the variable referenced by 'expression' in 'process' and 'state'.
 * Parameters:
 *    - 'state' is necessary to evaluate the index of an array expression.
 *    - process is the environment in which the variable is ANALYZED, NOT in the one the variable is DEFINED.
 *    - On first call, preOffset must have the same value as the offset of its environment (i.e. global or process).
 */
unsigned int getVarOffset(ptSymTabNode globalSymTab, ptMTypeNode mtypes, ptState state, ptStateMask process, unsigned int preOffset, struct expNode_* expression);

/*
 * Reads 'nb' bytes in a memory chunk of the state, at offset 'offset', puts them in an array of byte and returns it.
 */
byte* readValues(void* chunk, unsigned int offset, int nb);

/*
 * Stores 'nb' bytes in a memory chunk, at offset 'offset'.
 * Those bytes are read from the byte array 'values'.
 * The array is not freed afterward.
 *
 * Does not change the payloadHash.
 */
void storeValues(void* chunk, unsigned int offset, int nb, byte* values);


int stateGetValue(void* chunk, unsigned int offset, int type); // Returns the value stored in 'chunk' at offset 'offset'. The number of read bytes depends on 'type'.
void stateSetValue(void* chunk, unsigned int offset, int type, int value); // Set the value stored in 'chunk' at offset 'offset' to 'value'. The number of read bytes depends on 'type'.
ptStateMask maskLookup(ptState state, int pid); // Returns the stateMask with pid 'pid'.

/*
 * Gets the symbol table of a channel by giving its offset in the memory chunk.
 * The structure contained in state->chanRefs is used to get the table.
 * If no channel exists at the given offset, returns NULL.
 */
ptSymTabNode getChannelSymTab(ptState state, unsigned int chanOffset);

// Access and modification of large state chunks
ptState stateCreateInitial(struct symTabNode_* globalSymTab, struct mTypeNode_* mtypes); // Creates the initial state by setting all variables' value in the payload. Does not set the payloadHash.

/*
 * Creates a new process and returns its pid.
 * Reserves some memory for the proctype variables in the memory chunk and initializes the value of these variables.
 * Does not change the payloadHash.
 */
int  stateAddProctype(ptState state, struct symTabNode_* proctype, char * cname, ptExpNode cexp, int index);

/*
 * Defines the never claim of the execution.
 * Set its initial FSM node in the payload.
 * Does not change the payloadHash.
 */
void stateAddNever(ptState state, struct symTabNode_ * neverSymTab);

/*
 * If the pid of the last process is 'pid' then:
 *  - the stateMask of the process is removed
 *  - the number of processes in the states updated
 *  - the chunk of memory of the process is removed from the state's payload.
 * Does not change the payloadHash.
 */
void stateKillProctype(ptState state, int pid);

void stateClean(ptState state); // Applies stateKillProctype while this latter function succeeds.

/**
 * Frees the memory used by a given state. It does NOT free any symbol tables, FSM or mtypes list.
 * However, it DOES free:
 *  - the memory chunk,
 *  - all state masks of active processes,
 *  - the state mask of the never claim (if any),
 *  - all channel references,
 *
 * If the keepPayloadAndFeatures parameter is false, it also frees:
 *  - boolean formula and
 *  - the state structure itself.
 *
 * This parameter is only true when destroying a stack element where the payload and boolean function
 * are still used in the visited states hashtable.
 */
void stateDestroy(ptState state, byte keepPayloadAndFeatures);

// State printing
void printState(ptMTypeNode mtypes, ptState state, ptState diffState);
void printPayload(ptState state);

ptState stateDuplicate(ptState state); // Returns a copy of 'state. The payload is duplicated but not the feature expression, whose only reference is copied.

// State comparison. Returns:
#define STATES_DIFF 0				// if s1 and s2 are totally different states, meaning s1 is fresh.
#define STATES_SAME_S1_VISITED 1	// if s1 and s2 are identical but s2 is reachable by more products; hence, s1 adds nothing new
#define STATES_SAME_S1_FRESH 2		// if s1 and s2 are identical but s1 has products that were not explored with s2; hence, s1 is fresh
byte stateCompare(ptState s1, void* s2Payload, ptBoolFct s2Features, int s2Time, int s2Cost, int s2QualityLoss);
