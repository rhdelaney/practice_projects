#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"

int main(){
	FILE *fp=fopen("data", "r");
	
	int pnum=0;
	int cnum=0;
	
	cnum=readInt(fp);
	while(!feof(fp)){
	if(cnum>=pnum){
	pnum=cnum;
	cnum=readInt(fp);
	}
	else{
	printf("no\n");
	fclose(fp);
	return 0;
	}	
}
printf("yes\n");

fclose(fp);

return 0;
}
