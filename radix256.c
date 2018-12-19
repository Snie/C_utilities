 #include "radix256.h"

radix_node * space_end;
/* initializer of the RADIX 256 trie */
radix_trie * dictionary_create(){
  printf("TRIE and ROOT initializes\n");
  radix_trie * root = malloc(sizeof(radix_trie));
  root -> n_child = 0;
  assert(root);
  return root;
}

/* check if node is leaf or not return 1 if YES, 0 otherwise */
int isLeaf(radix_node * trie) {
  if(trie->n_child == 0){
    return 1;
  }
  return 0;
}

/* destroy trie */
void dictionary_clear(radix_trie * trie){
  if(trie) {
    for(int i = 0; i < trie->n_child; i++) {
      node_clear(trie->children[i]);
    }
    free(trie);
  }
  printf("TRIE cleared\n");
}

void node_clear(radix_node * node){
  if(node) {
    for(int i = 0; i < node->n_child; i++) {
      node_clear(node->children[i]);
    }
    // if(isLeaf(node)){
    //       free(node->key);
    // }
    free(node);
    printf("NODE cleared\n");
  }
}

radix_node * create_node(char letter){
  radix_node * node = malloc(sizeof(radix_node));
  node -> n_child = 0;
  node -> key = letter;
  // strcpy((node->key), &letter);
  assert(node->key);
  // printf("node -> %c added.\n", letter);
  return node;
}

void add_rest(radix_node * node, const char * rest){
  if(strlen(rest) == 0){
    node->children[32] = space_end;
    return;
  }
  int begin = (int)rest[0];
  if(node->children[begin] == NULL){
    radix_node * node_child = create_node(rest[0]);
    node->children[(int)rest[0]] = node_child;
    // printf("added -> %c\n", rest[0]);
    add_rest(node_child, rest+1);
  }
  else {
    add_rest(node->children[begin], rest+1);
  }
}



int dictionary_add(radix_trie * trie, const char * word){
  printf("%p\n", space_end);
  int begin = (int)word[0];
  if(trie->children[begin] == NULL){
    printf("%c: free.\n", word[0]);
    radix_node * node_root = create_node(word[0]);
    // printf("added -> %c\n", word[0]);
    trie->children[begin] = node_root;
    add_rest(node_root, word+1);
  }
  else {
    add_rest(trie->children[begin], word+1);
  }
  return 0;
}

int search_rest(radix_node * node, const char * rest){
  if(strlen(rest) == 0 && node->children[32] != NULL){
    return 1;
  }
  int begin = (int)rest[0];
  if(node->children[begin] != NULL){
    printf("found: %c\n", node->children[begin] -> key);
    return search_rest(node->children[begin], rest+1);
  }
  else {
    return 0;
  }
}

int dictionary_search(radix_trie * trie, const char * word){
  int begin = (int)word[0];
  if(trie->children[begin] == NULL){
    printf("not found word: %s\n", word);
    return 0;
  }
  else {
    printf("found: %c\n", trie->children[begin] -> key);
    if(search_rest(trie->children[begin], word+1) == 1){
      printf("found word: %s\n", word);
    }
    else {
        printf("not found word: %s\n", word);
    }
  }
  return 0;
}

int main(int argc, char const *argv[]) {

  space_end = create_node(' ');

  printf("Radix 256 trie\n\n");
  radix_trie * root = dictionary_create();
  dictionary_add(root, "ciao");
  dictionary_add(root, "ciaa");
  dictionary_add(root, "cavalletta");
  dictionary_add(root, "umberto");
  dictionary_add(root, "umbe");

  dictionary_search(root, "umberto");

  dictionary_clear(root);
  return 0;
}
