#include "stack_int.h"
stack_int * head;

void create_stack(){
  printf("stack initialized\n");
  head = malloc(sizeof(stack_int));
  head -> previous = NULL;
}

int push_stack(stack_int * stack, const int number){
  stack_int * new = malloc(sizeof(stack_int));
  new -> value = number;
  new -> previous = stack;
  head = new;
  printf("pushed: %d\n", new->value);
  return new->value;
}

void pop_stack(stack_int * stack){
  if(stack->previous == NULL) {
    printf("stack empty - nothing to pop\n");
    return;
  }
  else {
    free_head(head);
    head = stack->previous;
    printf("popped: %d\n", stack->value);
  }

}

void print_stack(stack_int * stack){
  if(stack->previous == NULL) printf("stack empty\n");
  printf("\n");
  while(stack->previous != NULL){
    printf("-> %d\n", stack->value);
    stack = stack->previous;
  }
  printf("\n");
}

void free_head(stack_int * element){
  if(element->previous == NULL){
    free(element->previous);

  }
  // printf("stack destroied -> %d\n", element->value);
  free(element);
  // printf("stack destroied.\n");
}

int main(int argc, char const *argv[]) {
  printf("Int Struct works.\n");
  create_stack();
  // push_stack(head, 1);
  // print_stack(head);
  // pop_stack(head);
  // print_stack(head);

  for(int i = 0; i < 11; i++){
    push_stack(head, i);
  }
  print_stack(head);
  for(int i = 0; i < 12; i++){
    pop_stack(head);
  }
  print_stack(head);

  for(int i = 10; i < 20; i++){
    push_stack(head, i);
  }

  print_stack(head);


  return 0;
}
