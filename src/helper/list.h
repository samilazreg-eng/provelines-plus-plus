/*
 * Generic lists
 * * * * * * * * * * * * * * * * * * * * * * * */

struct list_ {
	void* value;
	struct list_* next;	// Points to next node; the last node in a list has this pointer set to NULL.
	struct list_* prev;	// Points to previous node; the first node in a list has this pointer pointing to the last node!
};
typedef struct list_   tList;
typedef struct list_* ptList;

struct labeledList_ {
	char* label;
	void* value;
	struct labeledList_* next;	// Points to next node; the last node in a list has this pointer set to NULL.
	struct labeledList_* prev;	// Points to previous node; the first node in a list has this pointer pointing to the last node!
};
typedef struct labeledList_   tLList;
typedef struct labeledList_* ptLList;

ptList listAdd(ptList list, void* value); // Returns the list obtained by adding 'value' to the end of 'list'.
ptList listAddHead(ptList list, void* value); // Returns the list obtained by adding 'value' to the head of 'list'.
ptList listRemove(ptList list, void* value); // Returns the list obtained by removing the first entry in 'list' that contains reference 'value'.
ptList listFind(ptList list, void* value); // If 'value' is in 'list', returns the node containing 'list'. Otherwise, returns NULL.
void listDestroy(ptList list); // Destroys 'list' (but not its elements).
void listPrint(ptList list); // Only if the list contains strings ONLY, prints the content of the list.
int listCount(ptList list); // Returns the number of elements in 'list'.
ptList listConcat(ptList a, ptList b); // Returns the concatenation list 'a' with list 'b'.
ptList listCopy(ptList list); // Returns a copy of the list. Only the reference of the elements are copied.
ptList listGet(ptList list, int index);
ptList listSwap(ptList list, int i, int j);

ptLList llistAdd(ptLList list, char* label, void* value); // Returns the labelled list obtained by adding 'value' to 'list' at 'label'.
ptLList llistRemoveLabel(ptLList list, char* label); // Returns the labelled list obtained by removing the first entry with label 'label'.
ptLList llistRemove(ptLList list, void* value); // Returns the labelled list obtained by removing the first entry in 'list' that contains reference 'value'.
ptLList llistFind(ptLList list, char* label); // Returns the first node in 'list' with label 'label'.
void llistDestroy(ptLList list); // Destroys the labelled list. Frees neither the labels nor the value.
void llistPrint(ptLList list); // Prints the labelled list. Labels are displayed together with the pointer of their respective value.
int llistCount(ptLList list); // Returns the number of elements in 'list'.
ptLList llistMerge(ptLList a, ptLList b); // Returns the list obtained by merging lists 'a' and 'b'. If the lists share a label, only that of 'a' is kept.

ptLList list2llist(ptList list); // Transforms a list that contains only strings into a labelled list such that the element (label,value) at position 'i' is such that label is the i-th element of 'list' and value is an integer pointer whose pointed value is i.
ptLList list2llistConcat(ptLList prevList, ptList newList); // Same as list2llist, except that the transformed labelled list is concatenated to 'prevList'.
