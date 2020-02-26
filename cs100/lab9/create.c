#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

int main(int argc, char *argv[]){
	FILE *fp=fopen("Data1", "r");
	int x=0;
	int y=0;
	int k=0;
	//printf("Give a number of rows and a number of columns: ");
	//scanf("%d %d", &x, &y);
	x=atoi(argv[1]);
	y=atoi(argv[2]);
	int tnum=0;
	tnum=x*y;
	int sum=0;
	int num=0;
	for(k=0;k<tnum;k++){
		num=readInt(fp);
		sum+=num;
	}			
	printf("Array size= %d rows and %d columns, the sum of all elements in array is %d \n", x, y, sum);
	return 0;
}
