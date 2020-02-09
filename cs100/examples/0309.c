#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

typedef struct box {
	int length;
	int width;
	int height;
} Box;

int main(int argc, char *argv[]) {

	Box b;
	printf("Enter the length of the box : ");
	b.length = readInt(stdin);
	printf("Enter the width of the box : ");
	b.width = readInt(stdin);
	printf("Enter the height of the box : ");
	b.height = readInt(stdin);

	printf("The box volume box is %d\n", b.length * b.width * b.height);


	Box *pBox;

	pBox = (Box *) malloc ( sizeof(Box) );

	printf("Enter the length of the box : ");
	pBox->length = readInt(stdin);
	printf("Enter the width of the box : ");
	pBox->width = readInt(stdin);
	printf("Enter the height of the box : ");
	pBox->height = readInt(stdin);

	printf("The box volume is %d\n",
		pBox->length * pBox->width * pBox->height);

	return 0;
}
