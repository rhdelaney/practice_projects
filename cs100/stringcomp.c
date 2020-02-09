#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char *w1;
	printf("Enter a word: ");
	scanf("%s", w1);
	char *w2;
	printf("Enter a word: ");
	scanf("%s", w2);
	
	if(strcmp(&w1[0],&w2[0])){
	printf("%s", w1);}
	if(strcmp(&w2[0],&w1[0])){
	printf("%s", w2);}
	return 0;
}
