#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node *next;
} Node;

int main(){

Node *n1= (Node *) malloc( sizeof(Node) );
Node *n2= (Node *) malloc( sizeof(Node) );
Node *n3= (Node *) malloc( sizeof(Node) );
Node *n4= (Node *) malloc( sizeof(Node) );
Node *n5= (Node *) malloc( sizeof(Node) );

n1->letter = 'E'; n1->next =n2;
n2->letter = 'L'; n2->next =n3;
n3->letter = 'V'; n3->next =n4;
n4->letter = 'I'; n4->next =n5;
n5->letter = 'S'; n5->next = NULL;

Node *ptr, *first;
first=n1;
ptr=first;
while(ptr!=NULL){
	printf("%c", ptr->letter);
	ptr=ptr->next;}
printf("\n");

n2->next=n4;
n4->next=n3;
n3->next=n1;
n1->next=n5;

first=n2;
ptr=first;
while(ptr!=NULL){
	printf("%c", ptr->letter);
	ptr=ptr->next;}
printf("\n");

return 0;
}
