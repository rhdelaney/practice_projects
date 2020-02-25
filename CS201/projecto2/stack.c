#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "dll.h"
#include "integer.h"

stack *newStack(void (*d)(FILE *,void *)) {
	stack *theStack = malloc(sizeof(stack) );
	theStack->items = newDLL(d);
	return theStack;
}   //constructor
void push(stack *items,void *value) {
	insertDLL(items->items, 0, value);
}        //stores a generic value
void *pop(stack *items) {
	void *p = removeDLL(items->items, 0);
	return p;
}                  //returns a generic value
void *peekStack(stack *items) {
	void *p = getDLL(items->items,0);
	return p;
}               //returns a generic value
int sizeStack(stack *items) {
	int count = sizeDLL(items->items);
	return count;
}
void displayStack(FILE *fp,stack *items) {
	displayDLL(fp,items->items);
}
