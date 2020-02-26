#include <stdio.h>
#include <stdlib.h>

typedef struct node {
 int num;
 struct node *next;
} Node;

int areInAscendingOrder(Node *head);
void printList(Node *head);
Node *addRear(Node *head, int n);
// code for areInAscendingOrder goes here

int areInAscendingOrder(Node *head){
	int prev=0;
	Node *ptr=head;
	int ptr2=0;
	if(ptr==NULL){
		return 1;}
	else{
		while(ptr!=NULL){
			ptr2=ptr->num;
			if(prev>ptr2){
				return 0;
				}
			prev=ptr->num;
			ptr=ptr->next;
			}
		}
	return 1;
}

void printList(Node *head)
{
 Node *ptr;
 for (ptr=head; ptr!=NULL; ptr=ptr->next) {
 printf("%d", ptr->num);
 if (ptr->next!=NULL) printf("->");
 }
 printf("\n");
}

Node *findRear(Node *head)
{
 Node *ptr;
 for (ptr=head; ptr!=NULL; ptr=ptr->next) {
 if (ptr->next==NULL) return ptr;
 }
 return NULL;
}

Node *addRear(Node *head, int n)
{
 Node *pNode=(Node*)malloc(sizeof(Node));
 pNode->num=n;
 pNode->next=NULL;
 Node *pRear=findRear(head);
 if (pRear==NULL) return pNode;
 pRear->next=pNode;
 return head;
}

int main()
{
 Node *head=NULL;
 printf("Enter a positive integer to add or 0 to stop: ");
 int n;
 scanf("%d", &n);
	 while (n>0) {
		 head=addRear(head, n);
		 // printList(head);
		 printf("Enter a positive integer to add or 0 to stop: ");
		 scanf("%d", &n);
 		}
 printList(head);
 	if (areInAscendingOrder(head)) {
		 printf("The numbers entered are in ascending order.\n");
 		}
	 else {
 		printf("The numbers entered are not in ascending order.\n");
		 }
 return 0;
}
