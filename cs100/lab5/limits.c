#include <stdio.h>
#include "scanner.h"

int main(){
	FILE *fp;
	fp = fopen("NUMS","r");
	int max = readInt (fp);
	int min = readInt (fp);
	int x;

	while (!feof(fp)) {
	  if (max < x) {
			max = x;
		}
	  if (min > x && !x == 0) {
			min = x;
		}
	  x = readInt(fp);
	}
	printf("This is the max: %d\n",max);
	printf("This is the min: %d\n",min);
	fclose(fp);
	return 0;
}
