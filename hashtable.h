#ifndef HASHTABLE
#define HASHTABLE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

typedef struct linked_list {
    char * string;
    struct linked_list * next;
} linked_list;

typedef struct hashtable {
    int size;             /* the size of the table */
    linked_list ** table; /* the table elements */
} hashtable;

/* Initializes the hashtable with a size -> numbers of hashed indexes*/
hashtable * create_hash_table(int size);

/* Generates the index hashed by multipling x 31 and shifting by << */
unsigned int hash(hashtable * hashtable, char * str);

/* Look up the word in hashtable, calculating the hash index and than iterating the linked_list*/
linked_list * lookup_string(hashtable * hashtable, char * str);

/* Add string to hashtable, putting it in the hashed index */
int add_string(hashtable * hashtable, char * str);

/* Free hashtable and its elements + linked_lists*/
void free_table(hashtable * hashtable);

/* Search string in hashtable, delete it and free memory */
int delete_string(hashtable * hashtable, char * str);
#endif
