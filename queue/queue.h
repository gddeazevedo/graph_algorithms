#ifndef __queue_h
#define __queue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct __q_node {
	int data;
	struct __q_node* next;
} QNode;

typedef struct __q {
	QNode* head;
	QNode* tail;
} Queue;

Queue* newQueue();
bool enqueue(Queue* q, int data);
bool is_empty(Queue* q);
int dequeue(Queue* q);
void print_queue(Queue* q);


#endif
