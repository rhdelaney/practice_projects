#include <stdio.h>

int main()
{
    // a.  Declare an array of four integers and put the values 1, 8, 3, 1 in it
	int A[5];
	 A[0]= 1;
	 A[1]= 8;
	 A[2]= 3;
	 A[3]= 1;
    // b.  Print the value in the first location, second location, the last location
	printf("A[0]= %d\n", A[0]);
	printf("A[1]= %d\n", A[1]);
	printf("A[3]= %d\n", A[3]);
    // c.  Declare a pointer to an integer P that points to the start of the array
	int *p;
	*p = A[0];
    // d.  Print the value that P references
    	printf("P references %d\n", *p);
    // e.  Increment the variable P by 1, print the value at this location
	*p+=1;
	printf("P= %d\n", *p);
    // f.  Increment the variable P by 2, print the value at this location
	*p+=2;
	printf("P= %d\n", *p);
    // g.  Point P to the 8 in the array.  Print the 8 and then increment it by 1
	*p=A[2];
	printf("P= %d\n", *p);
	*p+=1;
	printf("P= %d\n", *p);
	
    return 0;
}
