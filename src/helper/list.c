#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "list.h"

/*
 * GENERIC LISTS - NO LABELS
 * * * * * * * * * * * * * * * * * * * * * * * */

/**
 * Adds a list value; returns the pointer to the new list (list could have been empty).
 */
ptList listAdd(ptList alist, void* value) {
	// printf("listAdd(%s, %s)\n", alist == NULL ? "null" : "ptr", value == NULL ? "null" : "ptr");
	ptList node = (ptList) malloc(sizeof(tList));
	if(!node) failure("Out of memory (creating list).\n");
	node->value = value;
	node->prev  = node;
	node->next  = NULL;

	if(alist == NULL) return node;
	else {
		node->prev = alist->prev;
		node->prev->next = node;
		alist->prev = node;
	}
	return alist;
}

/**
 * Adds a list value to the front of the list; returns the pointer to the new list (list could have been empty).
 */
ptList listAddHead(ptList alist, void* value) {
	ptList node = (ptList) malloc(sizeof(tList));
	if(!node) failure("Out of memory (creating list).\n");
	node->value = value;
	node->prev  = node;
	node->next  = NULL;

	if(alist == NULL) return node;
	else {
		node->prev = alist->prev;
		node->next = alist;
		alist->prev = node;
	}
	return node;
}

/**
 * Removes a list value; returns the pointer to the new list.
 */
ptList listRemove(ptList alist, void* value) {
	// printf("listRemove(%s, %s)\n", alist == NULL ? "null" : "ptr", value == NULL ? "null" : "ptr");
	ptList temp, iter = alist;
	while(iter && iter->value != value) iter = iter->next;
	while(iter && iter->value == value) {
		temp = iter->next;
		if(iter == alist) {
			// remove head element
			iter = iter->next;
			if(iter) iter->prev = alist->prev;
			free(alist);
			alist = iter;
		} else if(iter == alist->prev) {
			// remove tail element
			alist->prev = iter->prev;
			iter->prev->next = NULL;
			free(iter);
		} else {
			// remove middle element
			iter->prev->next = iter->next;
			iter->next->prev = iter->prev;
			free(iter);
		}
		iter = temp;
	}
	return alist;
}

/**
 * Find the item with the given value and returns it.  If no item with the value exists in the list, it returns NULL.
 */
ptList listFind(ptList alist, void* value) {
	ptList node = alist;
	while(node != NULL) {
		if(node->value == value) return node;
		node = node->next;
	}
	return NULL;
}

/**
 * Frees the memory occupied by a list.
 */
void listDestroy(ptList alist) {
	// printf("listDestroy(%s)\n", alist == NULL ? "null" : "ptr");
	ptList node = alist;
	ptList willy;
	while(node != NULL) {
		willy = node;
		node  = node->next;
		free(willy);
	}
}

/**
 * Concatenates two lists.
 * The arguments can be NULL (if both are NULL, the function returns NULL).
 * Returns a pointer to the new list.
 */
ptList listConcat(ptList a, ptList b) {
	// printf("listConcat(%s, %s)\n", a == NULL ? "null" : "ptr", b == NULL ? "null" : "ptr");
	if(a == NULL) {
		return b;
	} else if(b == NULL) {
		return a;
	} else {
		ptList tail = b->prev;
		b->prev = a->prev;
		b->prev->next = b;
		a->prev = tail;
		return a;
	}
}

/**
 * Debugging function; checks all list invariants.
 */
void listCheck(ptList alist) {
	if(!alist) printf("Check: empty.\n");
	else {
		if(!alist->next && !alist->prev) printf("Check: ok, single element.\n");
		else {
			ptList prev = NULL;
			ptList cur = alist;
			int count = 0;
			while(cur) {
				if(prev && cur->prev != prev) printf("Check: error, back pointer is bad at item %d.\n", count);
				prev = cur;
				cur = cur->next;
				count++;
			}

			if(alist->prev != prev) printf("Check: error, head does not point to tail.\n");
			printf("Check: done, %d elements.\n", count);
		}
	}
}

int listCount(ptList alist) {
	int i = 0;
	while(alist != NULL) {
		i++;
		alist = alist->next;
	}
	return i;
}

void listPrint(ptList alist) {
	int i = 0;
	printf("Printing list\n");
	while(alist != NULL) {
		printf("  %03d -> %s\n", i++, (char*) alist->value);
		alist = alist->next;
	}
}

ptList listCopy(ptList list) {
	ptList new = NULL;
	ptList tmp = list;
	while(tmp) {
		new = listAdd(new, tmp->value);
		tmp = tmp->next;
	}
	return new;
}


ptList listGet(ptList list, int index) {
    ptList tmp = list;
    
    for (int i = 0; i < index && tmp; i++) {
        tmp = tmp->next;
    }
    
    return tmp;
}

ptList listSwap(ptList list, int i, int j) {
    if (i == j) return list;
    if (j < i) return listSwap(list, j, i);
    
    ptList e1 = listGet(list, i);
    ptList e2 = listGet(list, j);
    
    ptList e1Next = e1->next; // last
    ptList e1Prev = e1->prev; // last
    ptList e2Next = e2->next;
    ptList e2Prev = e2->prev;
    
    e1->next = e2Next;
    
    if (e2Next != NULL || i != 0) { // e1 is not first or e2 is not last
        e2->prev = e1Prev;
        
        if (e2Next != NULL) { // else e2 is not last element
            e2Next->prev = e1;
        }
        
        if (i != 0) { // else e1 is not first element
            e1Prev->next = e2;
        }
        
        if (j == i + 1) { // e2 follows e1 -> risk of cycle
            e1->prev = e2;
            e2->next = e1;
        } else {
            e2->next = e1Next;
            e1Next->prev = e2;
            e1->prev = e2Prev;
            e2Prev->next = e1;
        }
    } else { // e2 is last and e1 is first
        if (j == i + 1) { // list = {e1,e2}
            e1->prev = e2;
            e2->next = e1;
        } else {
            e2->next = e1Next;
            e1Next->prev = e2;
            e1->prev = e2Prev;
            e2Prev->next = e1;
        }
        e2->prev = e1;
    }

    
    if (i == 0) return e2;
    else return list;
}

/*
 * GENERIC LISTS - LABELED
 * * * * * * * * * * * * * * * * * * * * * * * */

/**
 * Finds an item with the given label and returns it.  If no item with the label exists in the list, it returns NULL.
 */
ptLList llistFind(ptLList alist, char* label) {
	ptLList node = alist;
	int i;
	while(node != NULL) {
		i = strcmp(node->label, label);
		if(i == 0) return node;
		if(i >  0) return NULL;
		node = node->next;
	}
	return NULL;
}

/**
 * Adds a list value; returns the pointer to the new list (list could have been empty).
 *
 * If an item with the same label exists in the list, the new item will be added in front of it.
 */
ptLList llistAdd(ptLList alist, char* label, void* value) {
	ptLList node = (ptLList) malloc(sizeof(tLList));
	if(!node) failure("Out of memory (creating llist).\n");
	node->value = value;
	node->label = label;
	node->prev  = node;
	node->next  = NULL;

	if(alist == NULL) return node;
	else {
		ptLList iter = alist;
		while(iter != NULL && strcmp(iter->label, label) < 0) iter = iter->next;

		if(!iter) {
			// insert at tail
			node->prev = alist->prev;
			node->prev->next = node;
			alist->prev = node;
		} else if(iter == alist) {
			// insert at head
			node->next = iter;
			node->prev = iter->prev;
			iter->prev = node;
			alist = node;
		} else {
			// insert in the middle, before iter
			node->next = iter;
			node->prev = iter->prev;
			node->prev->next = node;
			iter->prev = node;
		}
	}
	return alist;
}


/**
 * Removes all list items with this label; returns the pointer to the new list.
 */
ptLList llistRemoveLabel(ptLList alist, char* label) {
	ptLList temp, iter = alist;
	while(iter && strcmp(iter->label, label) < 0) {
		iter = iter->next;
	}

	while(iter && strcmp(iter->label, label) == 0) {
		temp = iter->next;
		if(iter == alist) {
			// remove head element
			iter = iter->next;
			if(iter) iter->prev = alist->prev;
			free(alist);
			alist = iter;
		} else if(iter == alist->prev) {
			// remove tail element
			alist->prev = iter->prev;
			iter->prev->next = NULL;
			free(iter);
		} else {
			// remove middle element
			iter->prev->next = iter->next;
			iter->next->prev = iter->prev;
			free(iter);
		}
		iter = temp;
	}
	return alist;
}

/**
 * Removes a list value; returns the pointer to the new list.
 */
ptLList llistRemove(ptLList alist, void* value) {
	ptLList temp, iter = alist;
	while(iter && iter->value != value) iter = iter->next;
	while(iter && iter->value == value) {
		temp = iter->next;
		if(iter == alist) {
			// remove head element
			iter = iter->next;
			if(iter) iter->prev = alist->prev;
			free(alist);
			alist = iter;
		} else if(iter == alist->prev) {
			// remove tail element
			alist->prev = iter->prev;
			iter->prev->next = NULL;
			free(iter);
		} else {
			// remove middle element
			iter->prev->next = iter->next;
			iter->next->prev = iter->prev;
			free(iter);
		}
		iter = temp;
	}
	return alist;
}

/**
 * Frees the memory occupied by a list.
 */
void llistDestroy(ptLList alist) {
	ptLList node = alist;
	ptLList willy;
	while(node != NULL) {
		willy = node;
		node  = node->next;
		free(willy);
	}
}

/**
 * Merges two labelled lists.
 * The arguments can be NULL (if both are NULL, the function returns NULL).
 * Returns a pointer to the new list.
 */
ptLList llistMerge(ptLList a, ptLList b) {
	if(a == NULL) {
		return b;
	} else if(b == NULL) {
		return a;
	} else {
		// Step through both lists and interleave by moving elements from b into a.
		ptLList anode = a;
		ptLList bnode = b;
		ptLList temp;
		while(bnode) {
			if(anode && strcmp(anode->label, bnode->label) < 0) {
				anode = anode->next;
			} else {
				temp = bnode->next;
				if(!anode) {
					// insert at tail
					bnode->prev = a->prev;
					bnode->prev->next = bnode;
					a->prev = bnode;
				} else if(anode == a) {
					// insert at head
					bnode->next = anode;
					bnode->prev = anode->prev;
					anode->prev = bnode;
					a = bnode;
				} else {
					// insert in the middle, in front of anode
					bnode->next = anode;
					bnode->prev = anode->prev;
					anode->prev = bnode;
					bnode->prev->next = bnode;
				}
				bnode = temp;
			}
		}
		return a;
	}
}

/**
 * Debugging function; checks all list invariants.
 */
void llistCheck(ptLList alist) {
	if(!alist) printf("Check: empty.\n");
	else {
		if(!alist->next && !alist->prev) printf("Check: ok, single element.\n");
		else {
			ptLList prev = NULL;
			ptLList cur = alist;
			int count = 0;
			while(cur) {
				if(prev && cur->prev != prev) printf("Check: error, back pointer is bad at item %d.\n", count);
				prev = cur;
				cur = cur->next;
				count++;
			}

			if(alist->prev != prev) printf("Check: error, head does not point to tail.\n");
			printf("Check: done, %d elements.\n", count);
		}
	}
}

int llistCount(ptLList alist) {
	int i = 0;
	while(alist != NULL) {
		i++;
		alist = alist->next;
	}
	return i;
}

void llistPrint(ptLList alist) {
	int i = 0;
	printf("Printing list\n");
	while(alist != NULL) {
		printf("  %03d %10s -> %d\n", i++, alist->label, *((int*) alist->value));
		alist = alist->next;
	}
}

/* Transforms a list into a labelled list where each label is an element of the former list and the associated value is the index of this element in this list */
ptLList list2llist(ptList list) {
	ptList temp = list;
	ptLList llist = NULL;
	int i = 0;
	while(temp) {
		i++;
		int * cId = (int *) malloc(sizeof(int));
		*cId = i;
		llist = llistAdd(llist, (char *)temp->value, cId);
		temp = temp->next;
	}
	return llist;
}


ptLList list2llistConcat(ptLList prevList, ptList newList) {
	int i = llistCount(prevList);
	ptList temp = newList;
	while(temp) {
		i++;
		int * cId = (int *) malloc(sizeof(int));
		*cId = i;
		prevList = llistAdd(prevList, (char *)temp->value, cId);
		temp = temp->next;
	}
	return prevList;
}
