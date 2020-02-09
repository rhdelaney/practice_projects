#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int x;
	int y;
	for(x=1;x<argc;x++){ 
		for(y=strlen(argv[x]);y>-1;y--){	
	printf("%c",argv[x][y]);
	}
	printf("\n");
	}
	return 0;
}
