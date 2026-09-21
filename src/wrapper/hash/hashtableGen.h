/*
 * GENERIC HASHTABLE
 * * * * * * * * * * * * * * * * * * * * * * * */

typedef unsigned int   tHtKey;
typedef unsigned int* ptHtKey;

typedef void * ptHashtable;

struct hashtable * createHashtable(); // Returns an empty hashtable.
void destroyEntries(struct hashtable * table, ptList keys); // Destroys the elements of 'table' registered at a key contained in 'keys'.
void destroyHashtable(struct hashtable * table); // Destroys the hashtable.
void htInsert(struct hashtable * table, tHtKey key, void * value); // Inserts 'value' in 'table' at 'key'.
ptList htSearch(struct hashtable * table, tHtKey key); // Returns the list of entries found at 'key' in 'table'.
ptList htFind(struct hashtable * table, tHtKey key, void * value); // Returns the list of entries that contains 'value' at 'key' in 'table'. Equality with 'value' is determined through pointer comparison.
void htRemove(struct hashtable * table, tHtKey key, void * value); // Removes 'value' at 'key' from 'table'. Equality with 'value' is determined through pointer comparison.
