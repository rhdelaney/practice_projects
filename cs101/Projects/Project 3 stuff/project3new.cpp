#include <iostream>
using namespace std;

#include "List.h"

void show (char ch, List &L) {
	cout << ch << '\t' << L.size( ) << '\t' << L.currentRank( ) << '\t' << L.currentValue( ) << endl;
	L.display( );

}

void traverseFwd (char ch, List &L) {
	cout << ch << '\t';
	L.gotoFirst( );
	int k=0;
	while (! L.isNull( ) && k<=10) {
		cout << '(' << L.currentRank( ) << ',' << L.currentValue( ) << ')' << ' ';
		L.advance( );
		k++;
	}
	cout << endl;
}

void traverseBwd (char ch, List &L) {
	cout << ch << '\t';
	L.gotoLast( );
	int k=0;
	while (! L.isNull( ) && k<=10) {
		cout << '(' << L.currentRank( ) << ',' << L.currentValue( ) << ')' << ' ';
		L.retreat( );
		k++;
	}
	cout << endl;
}

int main( ) {
	List A, B, C, D;
	A.insertFirst(0);
	A.gotoLast( );
	B.insertLast(0);
	B.gotoFirst( );
	for (int k=10; k<=90; k+=10) {
		if (k%20==0) {
			A.insertAfter(k);
			B.insertBefore(k);
		}
		else {
			A.insertBefore(k);
			B.insertAfter(k);
		}
		C.insertFirst(k);
		D.insertLast(k);
	}
	C.gotoRank(2);
	D.gotoRank(6);

	show('A', A);		// A 10 5 0 [ 10 30 50 70 90 (0) 80 60 40 20 ]
	show('B', B);		// B 10 4 0 [ 20 40 60 80 (0) 90 70 50 30 10 ]
	show('C', C);		// C 9 2 70 [ 90 80 (70) 60 50 40 30 20 10 ]
	show('D', D);		// D 9 6 70 [ 10 20 30 40 50 60 (70) 80 90 ]

	A.replace(100);
	A.retreat( );
	A.replace(999);
	B.replace(100);
	B.advance( );
	B.replace(999);
	C.replace(100);
	C.advance( );
	C.replace(999);
	D.replace(100);
	D.retreat( );
	D.replace(999);

	show('A', A);		// A 10 4 999 [ 10 30 50 70 (999) 100 80 60 40 20 ]
	show('B', B);		// B 10 5 999 [ 20 40 60 80 100 (999) 70 50 30 10 ]
	show('C', C);		// C 9 3 999 [ 90 80 100 (999) 50 40 30 20 10 ]
	show('D', D);		// D 9 5 999 [ 10 20 30 40 50 (999) 100 80 90 ]

	cout << A.removeFirst( ) << " "; 	// 10
	cout << A.removeFirst( ) << " "; 	// 30
	cout << A.remove( ) << endl;		// 999
	cout << B.removeLast( ) << " "; 	// 10
	cout << B.removeLast( ) << " "; 	// 30
	cout << B.remove( ) << endl;		// 999

	while (! C.isLast( )) 
		cout << C.removeAndAdvance( ) << " ";	// 999 50 40 30 20
	cout << endl;
	while (! D.isFirst( )) 
		cout << D.removeAndRetreat( ) << " ";	// 999 50 40 30 20
	cout << endl;

	traverseFwd('A', A);	// A (0,50) (1,70) (2,100) (3,80) (4,60) (5,40) (6,20)
	traverseFwd('B', B);	// B (0,20) (1,40) (2,60) (3,80) (4,100) (5,70) (6,50)
	traverseFwd('C', C);	// C (0,90) (1,80) (2,100) (3,10)
	traverseFwd('D', D);	// D (0,10) (1,100) (2,80) (3,90)

	traverseBwd('A', A);	// A (6,20) (5,40) (4,60) (3,80) (2,100) (1,70) (0,50)
	traverseBwd('B', B);	// B (6,50) (5,70) (4,100) (3,80) (2,60) (1,40) (0,20)
	traverseBwd('C', C);	// C (3,10) (2,100) (1,80) (0,90)
	traverseBwd('D', D);	// D (3,90) (2,80) (1,100) (0,10)
}
