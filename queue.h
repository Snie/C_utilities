#ifndef QUEUE_INT
#define QUEUE_INT

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

typedef struct queue_int {
  int value;
  struct queue_int * next;
} queue_int;

/* initializes the queue */
void create_queue();

/* enqueue */
void enqueue(const int number);

/* dequeue element fron queue*/
void dequeue();

/* Prints queue */
void print_queue();


#endif
