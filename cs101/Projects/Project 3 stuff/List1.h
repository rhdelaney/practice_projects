#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
struct Node{
	int data;
	int rank;
	Node *next; //points at the next node
	Node *prev; //points at the previous node
};
class List {
	Node *head;
	Node *tail;
	Node *current;
	int n; //size;
private:

public:
	List( ); //makes a list->constructor
	int size( ); //->calls for current size of function
	int currentValue( ); //where you are at
	int currentRank( ); //what rank you are at
	void gotoFirst( ); //move to first/front node
	void gotoLast( ); //move to last node
	void retreat( ); //move backwards
	void advance( ); //move forwards 
	void gotoRank(int r); //move to that position
	bool isNull( ); //is it empty?
	bool isFirst( ); //is it the first?
	bool isLast( ); //is it last?
	void insertFirst(int x); //put x(value) it in the first slot (before)
	void insertLast(int x); //put x(value) it in the last slot (after)
	void insertBefore(int x); //put it in before the given slot
	void insertAfter(int x); //put it in after the given slot
	void replace(int x); //swap it in there
	int removeFirst( ); //get rid of the first value/slot 
	int removeLast( ); //get rid of the last value
	int remove( );	//get rid of the node you are currently at
	int removeAndRetreat( ); //get rid of current and move back
	int removeAndAdvance( ); //get rid of current and move up
	void display( ); //print out current status
};
