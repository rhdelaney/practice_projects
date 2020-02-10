#include <stdio.h>
#include <string.h>
#include "scanner.h"
#include <stdlib.h>

//Attempting to use a data struct now

int top(int x, int y, int a, matrix);

int middle(int x, int y, int a, matrix);

int bottom(int x, int y, int a, matrix);


int main(int argc, char *argv[]) {
	int size = atoi(argv[1]);
	FILE *fp = fopen(argv[2],"r");

	char **matrix;
	matrix = malloc(sizeof(char *) *size);
	int a = 0;
	for (a = 0;a < size;a++) {
		matrix[a] = malloc(sizeof(char) *size);
	}
	printf("The word puzzle is:\n");
	int x;
	int y;
	for (x = 0;x < size;x++) {
		for (y = 0;y < size;y++) {
		  matrix[x][y] = readChar(fp);
		  printf("%c",matrix[x][y]);
	  }
		printf("\n");
  }
	printf("Enter a word to find in the puzzle : ");
	char word[size];
	scanf("%s", word);
	int times = 0;
	int len = strlen(word);
	int a;
	int nodet;
	int nodem;
	int nodeb;
	for (a = 0;a < len;a++) {
	  for (x = 0;x < size;x++)  {
		  for (y = 0;y < size;y++) {
			  if (word[a] == matrix[x][y]) {
			    nodet = int top(int x, int y, int a, matrix);
			    nodem = int middle(int x, int y, int a, matrix);
			    nodeb = int bottom(int x, int y, int a, matrix);
		    }
	    }
    }
  }
	printf("\nThe word %s was found %d times \n", word,times );

return 0;
}

int top(int x, int y, int a, matrix){
	for (y = y-1; y <= y + 1;y++) {
		if (word[a] == matrix[x-1][y]) {
			return;
		}
	}
}
int middle(int x, int y, int a, matrix){
}
int bottom(int x, int y, int a, matrix){
}
