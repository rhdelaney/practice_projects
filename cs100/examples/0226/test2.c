#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *av[] ) {
    int n=atoi(av[1]);	
    int a, b;
	
	for (a=0; a<n; a=a+1){
	for (b=0; b<n; b=b+1){
	if(a+b>=n-1)
		printf("X");
	else
	printf(" ");
	}
	
	for (b=0; b<n; b=b+1){
	if (a>b)	
	printf("X");
	else
	printf(" ");
	}
	printf("\n");
	}
	
	for (b=0; b>n; b=b+1){
	if (a+b>=n-1)	
	printf("X");
	else
	printf(" ");
	}
	printf("\n");
}
	return 0;
}


