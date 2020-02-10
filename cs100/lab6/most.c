#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

int main(int argc, char *argv[]) {
	FILE *input = fopen(argv[1],"r");
	int max = 0;
	int i, l = 0, m = 0, file;

	int count[100] = {0};

	file = readInt(input);
	while (!feof(input)){
		for (i = 0;i < 100;i++) {
		  if (file == i) {
		    ++count[i];
	    }
    }
		file = readInt(input);
  }
	for (i = 0;i < 100;i++) {
		l = count[i];
		if (l > max) {
		  max = l;
	  }
	}
	for (i = 0;i < 100;i++) {
		m = count[i];
		if (max == m) {
		  printf("%d\n", i);
		}
  }

	fclose(input);
	return 0;
}
