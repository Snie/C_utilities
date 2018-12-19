#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
	void * value;
	const char * key;
} node;


struct map {
	node ** words;
	size_t n, size;
};


typedef struct map map;

int iterator = -1;

void create_iterator(){
	if(iterator == -1){
		iterator = 0;
		const char ** key = (char **) malloc(sizeof(char **) * lst->n);
		void ** key = (char **) malloc(sizeof(char **) * lst->n);
		while(iterate_map)
	}

	else
		printf("iterator already exists\n");
}

int iterate_map(map * mp, const char ** key, void ** value){
	if(iterator == -1)
		printf("NO ITERATOR FOUND\n");
	else{
		if(iterator < mp->n){
			key[iterator] = (mp->words[iterator])->key;
			value[iterator] = (mp->words[iterator])->value;
			iterator++;
			return 1;
		}
		else{
			iterator = -1;
			printf("iteration finished\n");
			return 0;
		}
	}
	return 0;
}

map * create_map(){
	map * new_string_list = malloc(sizeof(map));
	new_string_list->n = 0;
	new_string_list->size = 1;
	new_string_list->words = malloc(sizeof(node *));
	return new_string_list;
}
/* Destroy string list */
void destroy_map(map * lst){
	for(size_t i = 0; i < lst->n; i++){
		free(lst->words[i]);
	}
	free(lst->words);
	free(lst);
	printf("%s\n","map deleted" );
}

/* Print the list */
int find_map(map * lst, const char * key){
	for(int i = 0 ; i < lst->n ; i++){
		if(strcmp((lst->words[i])->key, key) == 0){
			return i;
		}
	}
	return -1;
}

/* add to string list */
void add_map(map * lst, const char * key, void * value){
	int tm = find_map(lst, key);
	if((tm ) > -1 ){
		printf("duplicate\n");
		(lst->words[tm])->value = value;
	}
	else{
		/* If number of elements is too big for actual list, list doubles its size */
		if(lst->n+1 >= lst->size){
			lst->size = (lst->size)*2;
			lst->words = (node **) realloc(lst->words, sizeof(node **)*(lst->size));
			if(lst->words == NULL){
				fprintf(stderr, "MEMORY FULL\n");
	      		exit(EXIT_FAILURE);
			}
		}
		/* Allocate memory +1 because \n */
		node * tmp = malloc(sizeof(node*));
		if(tmp == NULL){
			fprintf(stderr, "MEMORY FULL\n");
	  		exit(EXIT_FAILURE);
		}
		tmp->value = value;
		tmp->key = key;
		(lst->words)[lst->n] = tmp;
		lst->n = (lst->n) + 1;
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	map * lst = create_map();
	add_map(lst, "ciao", "bene");
	add_map(lst, "ciao", "bene");
	int i = 1;
	add_map(lst, "bene", &i);
	printf("%zu\n",lst->n );
	destroy_map(lst);

	return 0;
}