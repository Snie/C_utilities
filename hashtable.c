#include "hashtable.h"

hashtable * create_hash_table(int size){
    hashtable * new_table;
    if (size < 1) return NULL; /* invalid size for table */
    /* Attempt to allocate memory for the table structure */
    if ((new_table = malloc(sizeof(hashtable))) == NULL) {
        return NULL;
    }
    /* Attempt to allocate memory for the table itself */
    if ((new_table->table = malloc(sizeof(linked_list *) * size)) == NULL) {
        return NULL;
    }
    /* Initialize the elements of the table */
    for(int i = 0; i < size; i++) new_table->table[i] = NULL;
    /* Set the table's size */
    new_table->size = size;

    printf("hashtable initialized -> size: %d\n", new_table->size);
    return new_table;
}

unsigned int hash(hashtable * hashtable, char * str){
    unsigned int hashval;
    /* hash out at 0 */
    hashval = 0;

    /* for each character -> multiply the old hash by 31 and add the current
     * character
     * -> shifting and subtraction more
     * efficient than multiplication.
     */
    for(; * str != '\0'; str++) {
      hashval = * str + (hashval << 5) - hashval;

    }
    /* hash value mod the hashtable size fits into the necessary range
     */
    // printf("hash -> %d\n", hashval % hashtable->size);
    return hashval % hashtable->size;
}

linked_list * lookup_string(hashtable * hashtable, char * str) {
    linked_list * list;
    unsigned int hashval = hash(hashtable, str);

    /* Check at the position hashval in the list if word present
     * If more than one is stored in the index iterate it O(n) where
     * n are the elements in index
     */
    for(list = hashtable->table[hashval]; list != NULL; list = list->next) {
        if (strcmp(str, list->string) == 0) {
          printf("->found: %s\n", str);
          return list;
        }
    }
    return NULL;
}

int add_string(hashtable * hashtable, char * str) {
    linked_list * new_list;
    linked_list * current_list;
    unsigned int hashval = hash(hashtable, str);

    /* allocate memory for list */
    if ((new_list = malloc(sizeof(linked_list))) == NULL) return 1;

    /* item already in the hashtable? */
    current_list = lookup_string(hashtable, str);
    /* yes -> DO NOT INSERT */
    if (current_list != NULL){
      printf("word already exists: %s\n", str);
      return 2;
    }
    /* otherwise put into list */
    new_list->string = strdup(str);
    new_list->next = hashtable->table[hashval];
    hashtable->table[hashval] = new_list;
    printf("word added: %s\n", str);
    return 0;
}

void free_table(hashtable * hashtable) {
    int i;
    linked_list * list, * temp;

    if (hashtable == NULL) return;

    /* free elements strings and themself */
    for(int i = 0; i < hashtable->size; i++) {
        list = hashtable->table[i];
        while(list!=NULL) {
            temp = list;
            list = list->next;
            // printf("freed: %s\n", temp->string);
            free(temp->string);
            free(temp);
        }
    }

    /* free the table */
    printf("FREED HASHTABLE\n");
    free(hashtable->table);
    free(hashtable);

}

int delete_string(hashtable * hashtable, char *str) {
	int i;
	linked_list *list, *prev;
	unsigned int hashval = hash(hashtable,str);

	/* Find string in table
   * track the position to be sure to keep index right
	 */
	for(prev=NULL, list=hashtable->table[hashval];
		list != NULL && strcmp(str, list->string);
		prev = list,
		list = list->next);

	/* not found, return 1 as an error */
	if (list==NULL) return 1; /* string does not exist in table */

	/* otherwise, it exists. remove it from the table */
	if (prev==NULL) hashtable->table[hashval] = list->next;
	else prev->next = list->next;

	/* free the memory */
  printf("deleted and freed: %s\n", list->string);
	free(list->string);
	free(list);

	return 0;
}


int main(int argc, char const *argv[]) {
  /* code */
  hashtable * h = create_hash_table(10000);
  add_string(h, "ciao");
  add_string(h, "come");
  add_string(h, "stai");
  // lookup_string(h, "come");
  // delete_string(h, "come");
  // lookup_string(h, "come");
  add_string(h, "bello");
  add_string(h, "sono");
  // add_string(h, "umberto");
  // add_string(h, "cazzo");
  lookup_string(h, "ciao");
  free_table(h);

  return 0;
}
