#include <stdio.h>
#include <string.h>
#include "scanner.h"

int compete(char *move1, char *move2){
	if (strcmp(move1, move2)==0) return 0;
	if (strcmp(move1, "rock")==0){
		if (strcmp(move2, "scissors")==0)
			return 1;
		else return -1;}
	if(strcmp(move1, "scissors")==0){
		if(strcmp(move2, "rock")==0)
			return -1;
		else return 1;}
	if (strcmp(move1, "paper")==0){
		if(strcmp(move2, "scissors")==0)
			return -1;
		else return 1;}

	return 0;
}

int main(){
	
	
	printf("Enter player one's move: ");
	char *m1=readToken(stdin);
	printf("Enter player two's move: ");
	char *m2=readToken(stdin);
	
	int result=compete(m1, m2);
	if (result==0)
		printf("It is a tie.\n");
	else if (result<0)
		printf("Player one loses.\n");
	else{
		printf("Player one wins.\n");}
	return 0;
}

