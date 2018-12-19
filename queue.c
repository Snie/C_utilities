#include "queue.h"

queue_int * front = NULL;
queue_int * rear = NULL;
int sizemax = 10;

void enqueue(const int number){
  queue_int * new = malloc(sizeof(queue_int));
  new -> value = number;
  new -> next = NULL;
  if(front == NULL && rear == NULL){
		front = rear = new;
		return;
	}
	rear->next = new;
	rear = new;
  printf("queued: %d\n", number);
}

void dequeue() {
	struct queue_int * temp = front;
	if(front == NULL) {
		printf("Queue is empty - nothing to dequeue\n");
		return;
	}
	if(front == rear) {
		front = rear = NULL;
	}
	else {
    printf("dequeued: %d\n",  front->value);
		front = front->next;
	}
	free(temp);
}

void print_queue() {
	struct queue_int * temp = front;
  printf("queue -> ");
	while(temp != NULL) {
		printf("%d ",temp->value);
		temp = temp->next;
	}
	printf("\n");
}

int main(int argc, char const *argv[]) {
  // create_queue();
  for(int i = 0; i < 10; i++){
    enqueue(i);
  }
  dequeue();
  dequeue();
  dequeue();
  dequeue();

  print_queue();

  return 0;
}
