#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

int main(int argc, char *argv[]){
	FILE *fp=fopen(argv[1], "r");
	FILE *fp1=fopen(argv[2], "r");
	FILE *fout=fopen("allData", "w");	
	
	int done;
	int dtwo;	
	done=readInt(fp);
	dtwo=readInt(fp1);
	while(!feof(fp) && !feof(fp1)){
		if(done<dtwo){
			fprintf(fout,"%d ",done);
			done=readInt(fp);}
		else if(dtwo<done){
			fprintf(fout,"%d ",dtwo);
			dtwo=readInt(fp1);}
		else if (dtwo==done){
			fprintf(fout,"%d ",done);
			dtwo=readInt(fp1);
			done=readInt(fp);}}
if(feof(fp)){
	while(!feof(fp1)){
	fprintf(fout,"%d ",dtwo);
	dtwo=readInt(fp1);}}
if(feof(fp1)){
	while(!feof(fp)){
	fprintf(fout,"%d ",done);
	done=readInt(fp);}}
	
	
	fclose(fp);
	fclose(fp1);
	fclose(fout);
	return 0;
}
