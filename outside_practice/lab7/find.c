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

int count(Node *);
int find(Node *head, char *name){
	while(head!=NULL){
		if(strcmp(name,head->name)==0){
			return 1;}
		head=head->next;
	}
	return 0;
}
char *last(Node *);

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

	// Uncomment the line below for problem #2
	//printf("\nThere are %d items in your list\n", count(head) );

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

	// Uncomment the four lines below for problem #4
	//if ( last(head) )
	//	printf("\nThe last name in the list is %s\n", last(head) );
	//else
	//	printf("No items in the list\n");
	
	return 0;
}
