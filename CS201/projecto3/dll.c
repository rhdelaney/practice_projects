#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
#include "integer.h"

dll *newDLL(void (*d)(FILE *,void *)) {
	dll *items = malloc(sizeof(dll));
	if (items == 0){
		fprintf(stderr,"out of memory");
		exit(-1);
	}
	items->head = 0;
	items->tail = 0;
	items->size = 0;
	items->display = d;
	return items;
}            //constructor
void insertDLL(dll *items,int index,void *value) {
	if(items->size == 0 && index == 0){
		dllnode *node = malloc(sizeof(dllnode));
		items->head = node;
		items->tail = node;
		items->size = 1;
		node->next = 0;
		node->prev = 0;
		node->value = value;
	}
	else if (index > items->size) {
		return;
	}
	else if (index == 0 && items->size >= 1) {
		dllnode *node = malloc(sizeof(dllnode));
		node->value = value;
		items->head->prev = node;
		node->next = items->head;
		node->prev = 0;
		items->head = node;
		items->size = items->size + 1;
	}
	else if (index == items->size) {
		dllnode *node = malloc(sizeof(dllnode));
		node->value = value;
		node->prev = items->tail;
		items->tail->next = node;
		items->tail = node;
		node->next = 0;
		items->size = items->size + 1;
	}
	else if (index > (items->size) / 2) {
		dllnode *node = malloc(sizeof(dllnode));
		dllnode *tempN = items->tail;
		for (int i = 0; i < (items->size) - index - 1; i++) {
			tempN = tempN->prev;
		}
		node->prev = tempN->prev;
		tempN->prev->next = node;
		tempN->prev = node;
		node->next = tempN;
		node->value = value;
		items->size = items->size + 1;
	}
	else if (index <= (items->size) / 2) {
		dllnode *node = malloc(sizeof(dllnode));
		node->value = value;
		dllnode *tempN = items->head;
		for (int i = 0; i < index; i++) {
			tempN = tempN->next;
		}
		node->next = tempN;
		node->prev = tempN->prev;
		tempN->prev->next = node;
		tempN->prev = node;
		items->size = items->size + 1;
	}
	else {
		return;
	}
} //stores a generic value
void *removeDLL(dll *items,int index) {
	if (items->size == 0){
		exit(-1);
	}
	else if (index > items->size) {
		exit(-1);
	}
	else if (index == 0 && items->size >= 1) {
		dllnode *node = items->head;
		items->head = items->head->next;
		//items->head->prev=0;
		items->size = items->size -1;
		return node->value;
	}
	else if (index == items->size - 1) {
		dllnode *node = items->tail;
		items->tail = items->tail->prev;
		items->tail->next = 0;
		items->size = items->size - 1;
		return node->value;
	}
	else if (index > (items->size - 1) / 2) {
		dllnode *tempN = items->tail;
		for (int i = 0; i < (items->size) - index - 1; i++) {
			tempN = tempN->prev;
		}
		dllnode *node = tempN;
		tempN->prev->next = tempN->next;
		tempN->next->prev = tempN->prev;
		items->size = items->size - 1;
		return node->value;
	}
	else if (index <= (items->size - 1 ) / 2) {
		dllnode *tempN = items->head;
		for (int i = 0;i < index; i++) {
			tempN = tempN->next;
		}
		dllnode *node = tempN;
		tempN->next->prev = tempN->prev;
		tempN->prev->next = tempN->next;
		items->size = items->size - 1;
		return node->value;
	}
	else {
		exit(-1);
	}
}            //returns a generic value
void unionDLL(dll *recipient,dll *donor) {
	if (donor->head == NULL && recipient->head == NULL) {
		exit(-1);
	}
	else if (donor->head == NULL) {
		return;
	}
	else if (recipient->head == NULL) {
		recipient->head = donor->head;
		recipient->size = sizeDLL(recipient) + sizeDLL(donor);
		recipient->tail = donor->tail;
		donor->size = 0;
		donor->head = NULL;
		donor->tail = NULL;
	}
	else {
		recipient->tail->next = donor->head;
		donor->head->prev = recipient->tail;
		recipient->size = sizeDLL(recipient) + sizeDLL(donor);
		recipient->tail = donor->tail;
		donor->size = 0;
		donor->head = NULL;
		donor->tail = NULL;
	}
}         //merge two lists into one
void *getDLL(dll *items,int index) {
	if (index > (items->size) / 2) {
		dllnode *tempN = items->tail;
		for (int i = 0; i < (items->size) - index - 1; i++) {
			tempN = tempN->prev;
		}
		return tempN->value;
	}
	else {
		dllnode *tempN = items->head;
		for (int i = 0; i < index; i++) {
			tempN = tempN->next;
		}
		return tempN->value;
	}
} //get the value at the index
int sizeDLL(dll *items) {
	return items->size;
}
void displayDLL(FILE *f,dll *items) {
	dllnode *tempN = items->head;
	fprintf(f,"[");
	if (items->head != NULL) {
		while (tempN != NULL) {
			items->display(f,tempN->value);
			if (tempN->next != NULL) {
				fprintf(f,",");
			}
			tempN = tempN->next;	
		}
	}
	fprintf(f,"]");
}
