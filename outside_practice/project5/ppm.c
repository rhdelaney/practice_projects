#include "ppm.h"

//5 functions
// 1. read an image
// 2. write an image
// 3. copy an image
// 4. shrink it
//5. grow it

//Raychel Delaney's attempt to make the ppm file grow, shrink, and copy.
//Btw Happy Passover CS family

ppmPic *readPic(ppmPic *oldPic,Pixel *px1,FILE *fp1){
	//we read and then we return a pointer cool huh?
	oldPic=malloc(sizeof(ppmPic));
	oldPic->cols= readInt(fp1);
	oldPic->rows= readInt(fp1);
	oldPic->colors= readInt(fp1);
	oldPic->pixels=malloc(sizeof(Pixel *) *oldPic->rows);
	
	int i,j;
	for(i=0;i< oldPic->rows;i++){
	oldPic->pixels[i]=malloc(sizeof(Pixel) *oldPic->cols);}
	
	for(i=0;i< oldPic->rows;i++){
		for(j=0;j< oldPic->cols;j++){	
		oldPic->pixels[i][j].red=readInt(fp1);
		oldPic->pixels[i][j].green=readInt(fp1);
		oldPic->pixels[i][j].blue=readInt(fp1);
		}}
	return oldPic;
}

void writePic(ppmPic *newPic,Pixel *px2, FILE *fp2,char *header){
	//we just print the ish out
	fprintf(fp2,"%s\n", header);
	fprintf(fp2,"%d ", newPic->cols);
	fprintf(fp2,"%d\n", newPic->rows);
	fprintf(fp2,"%d\n", newPic->colors);
	int i, j;
	for(i=0;i<newPic->rows;i++){
		for(j=0;j<newPic->cols;j++){
			fprintf(fp2,"%d ", newPic->pixels[i][j].red);
			fprintf(fp2,"%d ", newPic->pixels[i][j].green);
			fprintf(fp2,"%d ", newPic->pixels[i][j].blue);
			}
			fprintf(fp2,"\n");			
}
}
ppmPic *growPic(ppmPic *newPic,ppmPic *oldPic,Pixel *px1,Pixel *px2){
	//making it grow grow GROW
	newPic=malloc(sizeof(ppmPic));
        int valCols=(oldPic->cols)*2;
        int valRows=(oldPic->rows)*2;
        newPic->cols=valCols;
	newPic->rows=valRows;  
	newPic->colors=oldPic->colors;
	

        newPic->pixels=malloc(sizeof(Pixel *) *newPic->rows);
        int i, j,k=0,l=0;
        for(i=0;i<newPic->rows;i++){
              newPic->pixels[i]=malloc(sizeof(Pixel)*newPic->cols);}

                for(i=0;i< newPic->rows;i+=2){
                for(j=0;j< newPic->cols;j+=2){
           
			newPic->pixels[i][j].red=oldPic->pixels[k][l].red;
			newPic->pixels[i+1][j].red=oldPic->pixels[k][l].red;
			newPic->pixels[i][j+1].red=oldPic->pixels[k][l].red;
			newPic->pixels[i+1][j+1].red=oldPic->pixels[k][l].red;
			newPic->pixels[i][j].green=oldPic->pixels[k][l].green;
			newPic->pixels[i+1][j].green=oldPic->pixels[k][l].green;
			newPic->pixels[i][j+1].green=oldPic->pixels[k][l].green;
			newPic->pixels[i+1][j+1].green=oldPic->pixels[k][l].green;
			newPic->pixels[i][j].blue=oldPic->pixels[k][l].blue;
			newPic->pixels[i+1][j].blue=oldPic->pixels[k][l].blue;
			newPic->pixels[i][j+1].blue=oldPic->pixels[k][l].blue;
			newPic->pixels[i+1][j+1].blue=oldPic->pixels[k][l].blue;
		l++;
	}
	k++;
	l=0;
}

		return newPic;
		}	

ppmPic *shrinkPic(ppmPic *newPic,ppmPic *oldPic,Pixel *px2,Pixel *px1){
	//shrinking dat pic by cutting it in half
	newPic=malloc(sizeof(ppmPic));
	int valCols=oldPic->cols;
	int valRows=oldPic->rows;
		if((valCols)%2==0){
			newPic->cols=(valCols)/2;}
		if((valCols)%2!=0){
			newPic->cols=(valCols-1)/2;
			oldPic->cols=valCols-1;}
		if((valRows)%2==0){
			newPic->rows=(valRows)/2;}
		if((valRows)%2!=0){
			newPic->rows=(valRows-1)/2;
			oldPic->rows=valRows-1;}
		newPic->colors=oldPic->colors;

	newPic->pixels=malloc(sizeof(Pixel *) *newPic->rows);
        int i, j,k=0,l=0;
        for(i=0;i<newPic->rows;i++){
              newPic->pixels[i]=malloc(sizeof(Pixel)*newPic->cols);}
		
	
		for(i=0;i< oldPic->rows;i+=2){
                for(j=0;j< oldPic->cols;j+=2){
             		newPic->pixels[k][l].red =(oldPic->pixels[i][j].red + oldPic->pixels[i+1][j].red + oldPic->pixels[i][j+1].red +oldPic->pixels[i+1][j+1].red )/4;

             		newPic->pixels[k][l].green =(oldPic->pixels[i][j].green + oldPic->pixels[i+1][j].green + oldPic->pixels[i][j+1].green +oldPic->pixels[i+1][j+1].green )/4;
 			
             		newPic->pixels[k][l].blue =(oldPic->pixels[i][j].blue + oldPic->pixels[i+1][j].blue + oldPic->pixels[i][j+1].blue +oldPic->pixels[i+1][j+1].blue )/4;		
               		l++;
		 }
	k++;
	l=0;
}

return newPic;
}
