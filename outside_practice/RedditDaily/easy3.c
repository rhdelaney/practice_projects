#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

//more work needed to get done
//we can work on it later give yourself a break
//DO IT LATER

char *read(FILE *fp){
	int a=0;
	char *message;
	while(!feof(fp)){
		message[a]=readToken(fp);	
			a++;}
	return message;
}
void encrypt(FILE *fp, char *m){
	int n;
	printf("How many letters would you like to rotate by?");
	scanf("%d", n);
	for(a=0;a<
	}
void decrypt(FILE *fp, char *m);


int main(){
	char job[10];
	printf("Would you like to encrypt or decrypt?\n");
	scanf("%s", job);
	FILE *fp=fopen(argv[1],"r");
	char *m=read(FILE *fp);
	if(strcmp(job, "encrypt")==0){
		encrypt(fp, m);
	if(strcmp(job, "decrypt")==0){
		decrypt(fp, m);
		}
	fclose(fp);
	return 0;
}
