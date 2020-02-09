#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"

int main(int argc, char *argv[]){
	FILE *input=fopen(argv[1],"r");
	FILE *odds=fopen("odds", "w");
	FILE *evens=fopen("evens","w");
	
	int nums;
	nums=readInt(input);
	while(!feof(input)){
		nums=readInt(input);
		if(nums%2==0 && nums!=0){
		fprintf(evens,"%d ", nums);}
		else{
		fprintf(odds,"%d ",nums);}
	}
	fclose(input);
	fclose(odds);
	fclose(evens);
	return 0;

}
	
