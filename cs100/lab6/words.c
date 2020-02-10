#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

int main(int argc, char *argv[]) {
	char *words;
	int count = 0;
	double total = 0;
	double average = 0;
	int len = 0;

	FILE *input = fopen(argv[1], "r");

	words = readToken(input);

	while (!feof(input)) {
	  len = strlen(words);
	  total += len;
	  count++;
	  words = readToken(input);
	}

	average = total / count;

	printf("Number of words:%d\n", count);
	printf("Average length of words: %g\n", average);
	fclose(input);
	return 0;
}
