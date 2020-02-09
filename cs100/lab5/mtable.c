#include <stdio.h>

int main(){
	int x;
	for(x=1;x<=10;x++){
	if (x==1){
	printf("\t %d", x);}

	else if (x==10){
	printf("   %d", x);}
	else{
	printf("    %d", x);}
}
	printf("\n");
	int y;
	for(y=0;y<=50;y++){
	if(y==0){
	printf("    +");
}
	else{
	printf("-");
	}
}
	printf("\n");
	int z;
	int w;
	for(z=1;z<=10;z++){
	if (z>=10){
		printf(" %d |",z);}
	else{
		printf("  %d |",z);}
	for(w=1;w<=10;w++){
	if(w*z>=100){
	printf("  %d", w*z);}		
	else if(w*z>=10){	
	printf("   %d", w*z);}	
	else{
	printf("    %d", w*z);}
	}
	printf("\n");
}
	printf("\n");	
 	return 0;
}
