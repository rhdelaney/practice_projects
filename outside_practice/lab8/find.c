#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"

typedef struct node {
	char *name;
	struct node *next;
} Node;

Node *addList(Node *theList, char *theName) {
	Node *newNode = (Node *) malloc ( sizeof(Node) );
	newNode->name = theName;
	newNode->next = theList;
	return newNode;
}

void printList(Node *node) {
	Node *ptr = node;
	printf("The list is : \n");
	while (ptr != NULL) {
		printf("\t%s\n", ptr->name);
		ptr = ptr->next;
	}
	return;
}

int find(Node *head, char *name){
	if(head==NULL){
	return 0;}
	if(strcmp(name,head->name)==0){
		return 1;}
	else{
	head=head->next;
	return find(head,name);}		
}

int main( ) {
	Node *head = NULL;
	char *name;
	printf("Enter a name to add to the list (or 'quit' to exit) : ");
	name = readToken(stdin);
	while (strcmp(name, "quit") != 0) {
		head = addList(head, name);
		printf("Enter a name to add to the list (or 'quit' to exit) : ");
		name = readToken(stdin);
	}
	printList(head);


	// Uncomment the ten lines below for problem #3
	printf("\nEnter a name to find in the list (or 'quit' to exit) : ");
	name = readToken(stdin);
	while (strcmp(name, "quit") != 0) {
		if ( find(head, name) )
			printf("The name %s exists in the list\n", name);
		else
			printf("The name %s does not exist in the list\n", name);
		printf("Enter a name to find to the list (or 'quit' to exit) : ");
		name = readToken(stdin);
	}
	
	return 0;
}
