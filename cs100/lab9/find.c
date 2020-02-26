#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

int main(int argc, char *argv[]){
	FILE *fp=fopen("Data2", "r");
	int row=0;
	int cols=0;
	//printf("Enter number of rows, then  number of columns: \n");
	//scanf("%d %d", &row, &cols);
	row=atoi(argv[1]);
	cols=atoi(argv[2]);
	
	int **m= allocate(sizeof(int *) * row);
	int i;
	int j;
	for(i=0;i<row;i++){
		m[i]= allocate(sizeof(int )*cols);
	}
	int num;
	printf("Enter a number to find: ");
	scanf("%d", &num);
	for(i=0;i<row;i++){
	for(j=0;j<cols;j++){
		m[i][j]=readInt(fp);	
		if(num==m[i][j]){
			printf("Found at row %d column %d\n", i, j);
			}
		}
	}
	fclose(fp);
	return 0;
}
