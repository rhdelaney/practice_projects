#include "ArrayDeck.h"

ArrayDeck::ArrayDeck (int cap) {
	array = new int[cap];
	capacity = cap;
	front = 0;
	back = capacity - 1;
	n = 0;
}

bool ArrayDeck::isEmpty( ) {
	return n == 0;
}

bool ArrayDeck::isFull( ) {
	return n == capacity;
}

void ArrayDeck::insertFront (int x) {
	if (isFull( )) return;
	n++;
	front = (front - 1 + capacity) % capacity;
	array[front] = x;
}

void ArrayDeck::insertBack (int x) {
	if (isFull( )) return;
	n++;
	back = (back + 1) % capacity;
	array[back] = x;
}

int ArrayDeck::removeFront( ) {
	if (isEmpty( )) return 0;
	int x = array[front];
	n--;
	front = (front + 1) % capacity;
	return x;
}

int ArrayDeck::removeBack( ) {
	if (isEmpty( )) return 0;
	int x = array[back];
	n--;
	back = (back - 1 + capacity) % capacity;
	return x;
}
