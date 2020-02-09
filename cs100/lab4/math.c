#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	int a=atoi(argv[1]);
	int c=atoi(argv[3]);

	int operation=0;
	if (strcmp(argv[2],"+") == 0)
		 operation= a + c;
	else if (strcmp(argv[2],"-") == 0)
		 operation= a - c;
	else if (strcmp(argv[2],"/") == 0)
		 operation= a / c;
	else if (strcmp(argv[2], "*") == 0) 
		operation= a * c;
	else if (strcmp(argv[2], "%") ==0)
		operation= a % c;
	
	printf("Result: %d\n", operation);
	return 0;
}
