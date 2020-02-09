#include <stdio.h>

int main()
{
    // declare an integer array A that holds 5 values
	int A[5];
    // assign the values 10, 20, 30, 40, 50 into A.  Print the array
	A[0]=10;
	A[1]=20;
	A[2]=30;
	A[3]=40;
	A[4]=50;
	printf("A[0]= %d\n", A[0]);
	printf("A[1]= %d\n", A[1]);
	printf("A[2]= %d\n", A[2]);
	printf("A[3]= %d\n", A[3]);
	printf("A[4]= %d\n", A[4]);
    // declare an array B that holds three doubles.
	double B[3];
    // assign the values of 3.14, 2.718 and 1.414 to B.  Print the array
	B[0]=3.14;
	B[1]=2.718;
	B[2]=1.414;
	printf("B[0]= %lf\n", B[0]);
	printf("B[1]= %lf\n", B[1]);
	printf("B[2]= %lf\n", B[2]);
    // allocate a character array C with the initial string “IBM”
	char C[4]={'I', 'B', 'M', '\0'};
    // print the array C (as a string)
	printf("C= %s\n", C);
    // print the last element in A and B and C (all on one line)
	printf("A[4]= %d , B[2]=%lf, C[2]=%c\n", A[4], B[2], C[2]);
    // print the first element of A, B, C (all on one line)
	printf("A[0]= %d, B[0]= %lf, C[0]=%c\n", A[0], B[0], C[0]);  
    // add one to the middle element of A (and print it)
	A[2]=A[2]+1;
	printf("A[2]= %d\n", A[2]);
    // multiply the first value in B by 1.732, print the new value
	B[0]=B[0]*1.732;
	printf("B[0]= %lf\n", B[0]);
    // subtract 1 from the first element of C, print the new value
	C[0]--;
	printf("C[0]= %c\n", C[0]);

    return 0;
}
