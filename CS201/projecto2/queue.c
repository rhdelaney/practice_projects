#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "sll.h"

queue *newQueue(void (*d)(FILE *,void *)) {
	queue *theQueue = malloc(sizeof(queue));
	theQueue->items = newSLL(d);
	return theQueue;
}   //constructor
void enqueue(queue *items,void *value) {
	insertSLL(items->items,sizeQueue(items),value);
}      //stores a generic value
void *dequeue(queue *items) {
	void *p = removeSLL(items->items, 0);
	return p;
}                 //returns a generic value
void *peekQueue(queue *items) {
	void *p = getSLL(items->items,0);
	return p;
}               //returns a generic value
int sizeQueue(queue *items) {
	int count = sizeSLL(items->items);
	return count;
}
void displayQueue(FILE *fp,queue *items) {
	displaySLL(fp,items->items);
}
