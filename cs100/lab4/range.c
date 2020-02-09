#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	int c=atoi(argv[3]);
	int d=atoi(argv[4]);
	int e=atoi(argv[5]);
	
	int max=a;
	if (a<b) max=b;
	if (b<c) max=c;
	if (c<d) max=d;
	if (d<e) max=e;
	
	int min=a;
	if (b<a) min=b;
	if (c<b) min=c;
	if (d<c) min=d;
	if (e<d) min=e;
	
	int range=0;
	range= max - min;
	printf("The range is %d.\n", range);
	return 0;
}
