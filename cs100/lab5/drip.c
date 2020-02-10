#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"

int main(int argc, char *argv[]) {
	int x;
	int y;
	int z;
	int m;
	int length = 0;
	for (z = 0;z < argc;z++) {
	  length = strlen(argv[z]);
	  if (length > m) {
	    m = length;
    }
  }
	for (y = 0;y < m; y++) {
		for (x = 0;x < argc; x++) {
		  if (y > strlen(argv[x]) - 1) {
		    printf("  ");
			}
		  else {
		    printf(" %c",argv[x][y]);
	    }
    }
	  printf("\n");
  }
	return 0;
}
