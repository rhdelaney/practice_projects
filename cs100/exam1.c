#include<stdio.h>
int incDec(int, int);

int main(int argc, char **argv) {
	int x = 10, y = 20, z = 0;
	printf("%d and %d and %d\n", x, y, z);
	z = incDec(x,y);
	printf("The values are : %d and %d and %d\n", x, y, z);
	return 0;
}
int incDec(int one, int two) {
	one = one - 1;
	two = two * 2;
	printf("\t%d and %d\n", one, two);
	return (one + two);
}
