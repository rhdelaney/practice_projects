#include <iostream>
using namespace std;

#include "List.h"

// This program should compile, but it should not run properly.
// Its only purpose is to detect compile-time errors such as spelling and type errors.

int main( ) {
	int i;
	bool b;
	List L;
	i = L.size( );
	i = L.currentValue( );
	i = L.currentRank( );
	L.gotoFirst( );
	L.gotoLast( );
	L.retreat( );
	L.advance( );
	L.gotoRank(i);
	b = L.isNull( );
	b = L.isFirst( );
	b = L.isLast( );
	L.insertFirst(i);
	L.insertLast(i);
	L.insertBefore(i);
	L.insertAfter(i);
	L.replace(i);
	i = L.removeFirst( );
	i = L.removeLast( );
	i = L.remove( );
	i = L.removeAndRetreat( );
	i = L.removeAndAdvance( );
	L.display( );
}
