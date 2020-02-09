#include <stdio.h>
#include <stdlib.h>
typedef struct node
{ int val; struct node *next; } Node;
Node *addTerm(int value, Node *list) {
 Node *newTerm = malloc( sizeof(Node) );
 newTerm->val = value;
 newTerm->next = NULL;
 if (list == NULL) return newTerm;
 Node *ptr = list;
 while (ptr->next != NULL) ptr = ptr->next;
 ptr->next = newTerm;
 return list;
}
void printList(Node *list) {
 printf("< ");
 while (list != NULL) {
 printf("%d ", list->val);
 list = list->next;
 }
 printf(">\n");
 return;
}
int main(int argc, char *arv[]) {
 Node *myList = NULL;
 printList(myList);
 myList = addTerm(10, myList);
 printList(myList);
 myList = addTerm( 2, myList);
 myList = addTerm( 5, myList);
 myList = addTerm(20, myList);
 printList(myList);
 myList = addTerm(15, myList);
 myList = addTerm(12, myList);
 myList = addTerm( 1, myList);
 printList(myList);
 return 0;
}
