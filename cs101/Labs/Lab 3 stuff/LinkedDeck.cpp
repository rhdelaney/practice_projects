#include "LinkedDeck.h"
#include <cstdlib>

LinkedDeck::LinkedDeck( ) {
	front = NULL;
	back = NULL;
}

bool LinkedDeck::isEmpty( ) {
	return front == NULL && back == NULL;
}

void LinkedDeck::insertFront (int x) {
	Node *temp = new Node;
	temp->data = x;
	temp->prev = NULL;
	temp->next = front;
	if (isEmpty( )) back = temp;
	else front->prev = temp;
	front = temp;
}

void LinkedDeck::insertBack (int x) {
	Node *temp = new Node;
	temp->data = x;
	temp->next = NULL;
	temp->prev = back;
	if (isEmpty( )) front = temp;
	else back->next = temp;
	back = temp;
}

int LinkedDeck::removeFront( ) {
	if (isEmpty( )) return 0;
	int x = front->data;
	Node *temp = front;
	front = front->next;
	if (front == NULL) back = NULL;
	else front->prev = NULL;
	delete temp;
	return x;
}

int LinkedDeck::removeBack( ) {
	if (isEmpty( )) return 0;
	int x = back->data;
	Node *temp = back;
	back = back->prev;
	if (back == NULL) front = NULL;
	else back->next = NULL;
	delete temp;
	return x;
}
