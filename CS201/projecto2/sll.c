#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "integer.h"

sll *newSLL(void (*d)(FILE *,void *)) {
	sll *items = malloc(sizeof(sll));
	if (items == 0) {
		fprintf(stderr,"out of memory");
		exit(-1);
	}
	items->head = 0;
	items->tail = 0;
	items->size = 0;
	items->display = d;
	return items;
}	//d is the display function
void insertSLL(sll *items,int index,void *value) {
	if(items->size == 0 && index==0) {
		sllnode *node = malloc(sizeof(sllnode));
		items->head = node;
		items->tail = node;
		items->size = 1;
		node->next = 0;
		node->value = value;
	}
	else if (index > items->size) {
		return;
	}
	else if (index == 0 && items->size >= 1) {
		sllnode *node = malloc(sizeof(sllnode));
		node->value = value;
		node->next = items->head;
		items->head = node;
		items->size = items->size + 1;
	}
	else if (index == items->size) {
		sllnode *node = malloc(sizeof(sllnode));
		node->value = value;
		items->tail->next = node;
		items->tail = node;
		node->next = 0;
		items->size = items->size + 1;
	}
	else {
		sllnode *node = malloc(sizeof(sllnode));
		node->value = value;
		sllnode *tempN = items->head;
		for (int i = 0;i < index - 1; i++) {
			tempN = tempN->next;
		}
		node->next = tempN->next;
		tempN->next = node;
		items->size = items->size + 1;
	}
} //stores a generic value
void *removeSLL(sll *items,int index) {
	if (items->size == 0) {
		exit(-1);
	}
	else if (index > items->size) {
		exit(-1);
	}
	else if (index==0 && items->size >= 1) {
		sllnode *node = items->head;
		items->head = items->head->next;
		items->size = items->size - 1;
		return node->value;
	}
	else if (index == items->size - 1) {
		sllnode *tempN= items->head;
		for (int i = 0; i < sizeSLL(items) - 2; i++) {
			tempN = tempN->next;
		}
		sllnode *node = items->tail;
		tempN->next = 0;
		items->tail = tempN;
		items->size = items->size - 1;
		return node->value;
	}
	else {
		sllnode *tempN = items->head;
		for (int i = 0; i < index - 1; i++) {
			tempN = tempN->next;
		}
		sllnode *node = tempN->next;
		tempN->next = tempN->next->next;
		items->size = items->size - 1;
		return node->value;
	}
}            //returns a generic value
void unionSLL(sll *recipient,sll *donor) {
	if (donor->head == NULL) {
		return;
	}
	else if (recipient->head == NULL) {
		recipient->head = donor->head;
	}
	else {
		recipient->tail->next = donor->head;
	}
	recipient->size = sizeSLL(recipient) + sizeSLL(donor);
	recipient->tail = donor->tail;
	donor->size = 0;
	donor->head = NULL;
	donor->tail = NULL;
}        //merge two lists into one
void *getSLL(sll *items,int index) {
	sllnode *node = items->head;
	for (int i = 0; i < index; ++i) {
		node = node->next;
	}
	return node->value;
}               //get the value at the index
int sizeSLL(sll *items) {
	return items->size;
}
void displaySLL(FILE *f,sll *items) {
	sllnode *tempN = items->head;
	fprintf(f,"[");
	if (items->head != NULL) {
		while (tempN != NULL){
			items->display(f,tempN->value);
			if (tempN->next != NULL) {
				fprintf(f,",");
			}
			tempN = tempN->next;	
		}
	}
	fprintf(f,"]");
}
