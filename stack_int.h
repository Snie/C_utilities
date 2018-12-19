#ifndef STACK_INT
#define STACK_INT

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

typedef struct stack_int {
  int value;
  struct stack_int * previous;
} stack_int;

/* initializes the stack */
void create_stack();

/* destroies the stack, clearing all previously inserted entries if necessary */
void destroy_stack_int(stack_int * stack);

/* free element popped */
void free_head(stack_int * element);


int push_stack(stack_int * stack, const int number);

/* Pops element on the top of the stack */
void pop_stack(stack_int * stack);

/* Prints stack struct */
void print_stack(stack_int * stack);


#endif
