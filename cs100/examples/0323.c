#include <stdio.h>
#include <stdlib.h>

//yeah this shit don't work and you'll end up in a loop m8

typedef struct node {
	char letter;
	struct node *next;
} Node;

int main( ) {
	Node n1, n2, n3, n4, n5, n6, n7;

	printf("Initializing\n");
	n1.letter = 'C'; n1.next = &n2;
	n2.letter = 'R'; n2.next = &n3;
	n3.letter = 'I'; n3.next = &n4;
	n4.letter = 'M'; n4.next = &n5;
	n5.letter = 'S'; n5.next = &n6;
	n6.letter = 'O'; n6.next = &n7;
	n7.letter = 'N'; n7.next = NULL; 

	printf("Printing CRIMSON\n");
	Node *ptr, *first;
	first = &n1;
	ptr = first;
	while ( ptr != NULL ) {
		printf("%c", ptr->letter);
		ptr = ptr->next;
	}
	printf("\n");


	printf("Printing MICRONS\n");
	first = &n4; // start with 'M'
	// link the nodes
	n4.next = &n3;
	n3.next = &n1;
	n1.next = &n2;
	n2.next = &n6;
	n6.next = &n7;
	n7.next = &n5;
	n5.next = &n4;

	ptr = first;
	while ( ptr != NULL ) {
		printf("%c", ptr->letter);
		ptr = ptr->next;
	}
	printf("\n");
	return 0;
}
