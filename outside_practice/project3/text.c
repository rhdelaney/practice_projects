#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "scanner.h"
//Raychel Delaney
//This program is used to make two separate logs of text messages into one, single file.

void func1(FILE *fp1, FILE *merge);         //getting the text loop for p1
void func2(FILE *fp2,FILE *merge);	    //getting the text loop for p2
char *readableTime(int sec);                //changes POISX time to Normal Date
void buffer1(FILE *merge);                   //prints space for 2nd line
void buffer2(FILE *merge);                   //prints space for 1st line time
int main(){	
	FILE *fp1;
	FILE *fp2;
	FILE *merge;
	int p1num, p2num;
	char *time1;
	char *time2;
	
	fp1=fopen("person1", "r");
	fp2=fopen("person2","r");
	merge=fopen("transcript","w");
	p1num=readInt(fp1);
	p2num=readInt(fp2);

	while(!feof(fp1)  && !feof(fp2)){
		if(p1num<p2num) {
			func1(fp1, merge);	
			time1=readableTime(p1num);	
			buffer2(merge);
			fprintf(merge,"%s\n",time1);
			p1num=readInt(fp1);
		}
		if(p2num<p1num){
			func2(fp2, merge);
			time2=readableTime( p2num);
			buffer1(merge);
			fprintf(merge,"%s\n",time2);
			p2num=readInt(fp2);
		}
}
	if(feof(fp2)){
		while(!feof(fp1)){
			func1(fp1, merge);	
			time1=readableTime(p1num);	
			buffer2(merge);
			fprintf(merge,"%s\n",time1);
			p1num=readInt(fp1);
	}
}
	if(feof(fp1)){
		while(!feof(fp2)){
			func2(fp2, merge);
			time2=readableTime( p2num);
			buffer1(merge);
			fprintf(merge,"%s\n",time2);
			p2num=readInt(fp2);
	}
}
	fclose(fp1);
	fclose(fp2);	
	fclose(merge);
	return 0;
}

void func1(FILE *fp1, FILE *merge){
	char *p1;
	int i,len;
	int wordCount=readInt(fp1);
for(i=0;i<wordCount;i++){
	p1=readToken(fp1);
	len+=strlen(p1);
	if(len<31){
	fprintf(merge,"%s ",p1 );
	len+=1;
	}
	else{
	fprintf(merge,"\n%s ",p1);
	len=strlen(p1)+1;
	}
}
fprintf(merge,"\n");
}

void func2(FILE *fp2, FILE *merge){
	int x;
	for(x=0;x<35;x++){
	fprintf(merge," ");}
	char *p2;
	int i,len;
	int wordCount=readInt(fp2);
for(i=0;i<wordCount;i++){
	p2=readToken(fp2);
	len+=strlen(p2);
	if(len<31){
	fprintf(merge,"%s ",p2 );
	len+=1;}
	else{
	fprintf(merge,"\n");	
	for(x=0;x<35;x++){
	fprintf(merge," ");}
	fprintf(merge,"%s ", p2);
	len=strlen(p2)+1;
}
	}
fprintf(merge,"\n");
}

char *readableTime(int sec){
	time_t epoch_time= (time_t) sec;
	return asctime(localtime(&epoch_time));
}
void buffer1(FILE *merge){
	int x;
	for(x=0;x<40;x++){
	fprintf(merge," ");}
}
void buffer2(FILE *merge){
	int x;
	for(x=0;x<5;x++){
	fprintf(merge," ");}
}
