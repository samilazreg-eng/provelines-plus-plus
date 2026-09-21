#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "hashtable.h"
#include "hashtable_itr.h"
#include "list.h"
#include "hashtableGen.h"

struct value_ {
    ptList list;
};
typedef struct value_   tValue;
typedef struct value_* ptValue;

DEFINE_HASHTABLE_INSERT(insert_gen, tHtKey, struct value_);
DEFINE_HASHTABLE_SEARCH(search_gen, tHtKey, struct value_);
DEFINE_HASHTABLE_REMOVE(remove_gen, tHtKey, struct value_);
DEFINE_HASHTABLE_ITERATOR_SEARCH(search_itr_gen, tHtKey);

static unsigned int hashfromkey(void* k) {
    return *((ptHtKey) k);
}

static int equalkeys(void* k1, void* k2) {
    return *((ptHtKey) k1) == *((ptHtKey) k2);
}


struct hashtable * createHashtable() {
	return create_hashtable(2^16, hashfromkey, equalkeys);
}

void destroyEntries(struct hashtable * table, ptList keys) {
	ptList tmp = keys;
	while(tmp) {
		ptHtKey keyP = (ptHtKey) tmp->value;
		ptValue valP = remove_gen(table, keyP);
		if(valP) {
			listDestroy(valP->list);
			free(valP);
		}
		tmp = tmp->next;
	}
}

void destroyHashtable(struct hashtable * table) {
	hashtable_destroy(table, 0);
}

void htInsert(struct hashtable* table, tHtKey key, void * value) {
	if(!value) return;
	ptHtKey keyP = (ptHtKey) malloc(sizeof(tHtKey));
	if(!keyP) failure("Out of memory (creating hashtable key).\n");
	*keyP = key;
	ptValue valP;
	valP = remove_gen(table, keyP);
	if(!valP) {
		valP = (ptValue) malloc(sizeof(tValue));
		if(!valP) failure("Out of memory (creating hashtable value).\n");
		valP->list = NULL;
	}
	valP->list = listAdd(valP->list, value);
	if(!insert_gen(table, keyP, valP)) failure("Out of memory (inserting state in hashtable)\n");
}

ptList htSearch(struct hashtable* table, tHtKey key) {
	ptHtKey keyP = (ptHtKey) malloc(sizeof(tHtKey));
	if(!keyP) failure("Out of memory (creating hashtable key).\n");
	*keyP = key;
	ptValue valP;
	valP = search_gen(table, keyP);
	free(keyP);
	if(valP && valP->list)
		return valP->list;
	else
		return NULL;
}

ptList htFind(struct hashtable* table, tHtKey key, void * value) {
	ptList tmp = htSearch(table, key);
	while(tmp) {
		if(tmp->value == value)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

void htRemove(struct hashtable* table, tHtKey key, void * value) {
	ptHtKey keyP = (ptHtKey) malloc(sizeof(tHtKey));
	if(!keyP) failure("Out of memory (creating hashtable key).\n");
	*keyP = key;
	ptValue valP;
	valP = search_gen(table, keyP);
	if(valP && valP->list) {
		valP->list = listRemove(valP->list, value);
		if(!valP->list) {
			remove_gen(table, keyP);
			free(valP);
		}
	}
	free(keyP);
}
