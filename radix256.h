#ifndef RADIX_HEADER
#define RADIX_HEADER

#define MAX_LINE_LEN 1000
#define MAX_WORD 100

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

typedef struct radix_node {
  char key;
  size_t n_child;
  struct radix_node * children[256];
} radix_node;

typedef struct radix_trie {
  size_t n_child;
  struct radix_node * children[256];
} radix_trie;



/* initializes the dictionary */
radix_trie * dictionary_create();

/* initializes the dictionary, clearing all previously inserted entries if necessary */
void dictionary_clear(radix_trie * radix);

void node_clear(radix_node * node);

/* adds a word. Returns 1 when successful or 0 in case of failure. */
int dictionary_add(radix_trie * trie, const char * word);

/* returns 1 if the given word is in the dictionary, or 0 otherwise. */
int dictionary_search(radix_trie * trie, const char * word);

void print_dictionary(radix_node * trie);


#endif
