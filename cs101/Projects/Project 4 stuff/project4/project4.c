#include <stdio.h>
#include <string.h>
#include "scanner.h"
#include <stdlib.h>

typedef struct fsearch{
int x;
int y;
int sl;
char **matrix;
char l;
} Fsearch;

void wordPuzzle(FILE *fp, int size, Fsearch *f);
int top(Fsearch *f);
int middle(Fsearch *f);
int bottom(Fsearch *f);

int main(int argc, char *argv[]){
	int size=atoi(argv[1]);
	FILE *fp=fopen(argv[2],"r");
	
	struct fsearch *f;

	wordPuzzle(fp,size,f);
	
	printf("Enter a word to find in the puzzle : ");
	char word[size];
	scanf("%s", word);
	int times=0;
	int len=strlen(word);
	int x,y,sl=0;
	int nodet,nodem,nodeb;
	for(x=0;x<size;x++){
		for(y=0;y<size;y++){
			if(strcmp(&word[sl],&f->matrix[x][y])==0){			
			f->l=word[sl++];
			f->x=x;
			f->y=y;
			nodet= top(f);
			nodem= middle(f);
			nodeb= bottom(f);
		}	
	}
}	
	printf("\nThe word %s was found %d times \n", word,times );

return 0;
}

void wordPuzzle(FILE *fp, int size,Fsearch *f){
	
	char **matrix;
	matrix=malloc(sizeof(char *) *size);
	int a=0;
	for(a=0;a<size;a++){
		matrix[a]=malloc(sizeof(char) *size);
		}
	printf("The word puzzle is:\n");
	int x;
	int y;
	for(x=0;x<size;x++){
		for(y=0;y<size;y++){
		matrix[x][y]=readChar(fp);
		printf("%c",matrix[x][y] );
	}
		printf("\n");
}
	f->matrix=matrix;
}


int top(Fsearch *f){	
	int x=f->x;
	int y=f->y;
	char l=f->l;
	for(y=y-1; y<=y+1;y++){
		if(strcmp(&f->l,&f->matrix[x-1][y])==0){
				 	
		}
	}
	return 0;
}
int middle(Fsearch *f){	

return 0;
}
int bottom(Fsearch *f){

return 0;
}	
