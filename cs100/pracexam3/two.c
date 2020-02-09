#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void unique(char *name){
	int i;
	int j;
	int k;
	char *a[100];
	for(i=0;i<strlen(name);i++){
		if(name[i]>64 && name[i]<91){
				name[i]+=32;
			}
		}
	for(j=0;j<strlen(name);j++){
		for(k=0;k<strlen(name);k++){
				if(strcmp(a[k],name[j])==0){
					j++;
					}
				}
				printf("%c",name[j]);
				a[j]=&name[j];
	}	

}
int main(int argc, char *argv[]){
	//convert to lowercase
	//asqii values -> 64<capitals<91
	//-> add 32 to change to lower case

	int a;
	for(a=1;a<argc; a++){
		unique(argv[a]);}
	return 0;
}
