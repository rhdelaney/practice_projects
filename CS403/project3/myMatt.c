#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print(FILE* inFile, int size, char **puzzle) {
	//char letter;
	
	// fscanf(inFile, " %c", &puzzle);
	printf("in print \n");
	//fscanf(inFile, " %c", &letter);
    for (int i = 0; i < size; ++i) {
        for(int j=0; j<size; j++){	
        	fscanf(inFile, " %c", &puzzle[i][j]);
        	//printf("%c\n",letter);
        	//*puzzle++=&letter;
      	}
    }/*
	for (int i = 0; i < size *size ; ++i) {
		//for (int j = 0; j < size; ++j)	{
			fscanf(inFile, " %c", puzzle[i]);
		//}
	}*/
	printf("The word puzzle is:\n");
	//printf("%s\n", puzzle);
	for (int i = 0; i < size; ++i) {
		printf("\t");
		for (int j = 0; j < size; ++j)	{
			printf("%c ", puzzle[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}
int main (int argc, char const *argv[]) {
	FILE* inFile = NULL;
	inFile = fopen(argv[2], "r");
	if (inFile == NULL) {
		printf("The file specified, %s, does not exist.\n", argv[2]);
		return -1;
	}
	int size = atoi(argv[1]);
	//char **puzzle = malloc(size * sizeof(char *)); // Allocate row pointers
	//int i;
	//for(i = 0; i < size; i++){
  	//	puzzle[i] = malloc(size * sizeof(char));
	//
	char **puzzle;
	print(inFile, size, puzzle);
	char str[size];
	printf("Enter a word to find in the puzzle: ");
	scanf("%s", str);
	char stop[4] = "zzz";
	while (strcmp(str, stop) != 0) {
		// instances((char **)puzzle, str, size);
		//dotmap();
		printf("Enter another workingd to find (or 'zzz' to exit): ");
		scanf("%s", str);
	}
	return 0;
}