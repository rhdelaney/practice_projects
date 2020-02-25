#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"

typedef struct pixel {
	int red; // red value
	int green; // green value
	int blue; // blue value
} Pixel;
typedef struct ppm { 
	int rows; // number of rows 
	int cols; // number of columns 
	int colors; // number of colors
	Pixel **pixels; // actual pixel data
} ppmPic;


ppmPic *readPic(ppmPic *oldPic,Pixel *px1, FILE *fp1);
void writePic(ppmPic *newPic, Pixel *px2, FILE *fp2,char *header);

ppmPic *growPic(ppmPic *oldPic, ppmPic *newPic,Pixel *px1, Pixel *px2);
ppmPic *shrinkPic(ppmPic *newPic, ppmPic *oldPic, Pixel *px1, Pixel *px2);
//void copyPic(ppmPic *oldPic,Pixel *px1, ppmPic *newPic, Pixel *px2);
