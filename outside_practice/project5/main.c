#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ppm.h"
#include "scanner.h"

int main(int argc, char *argv[]){
        FILE *fp1=fopen(argv[2],"r");
	FILE *fp2=fopen(argv[3],"w");
       
	char *header=readToken(fp1);
	 
	ppmPic *oldPic=NULL;
	ppmPic *newPic=NULL;
	Pixel *px1=NULL;
	Pixel *px2=NULL;
	oldPic=readPic(oldPic,px1,fp1);
	
	if(strcmp(argv[1],"grow")==0){
		newPic=growPic(newPic,oldPic,px2,px1);
		writePic(newPic,px2,fp2,header);	
		}			
	if(strcmp(argv[1],"shrink")==0){
		newPic=shrinkPic(newPic,oldPic,px2, px1);	
		writePic(newPic,px2,fp2,header);	
		}
	if(strcmp(argv[1],"copy")==0){
		writePic(oldPic, px1, fp2, header);	
		}

	fclose(fp1);
	fclose(fp2);
        return 0;
}
