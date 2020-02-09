#include <stdio.h>

int main( ) {
    int a, b;
    for (a = 0; a < 10; a++) {
        for (b = 0; b < 15; b++)
        if(a==0||a==9 || b==0 ||b==14)    
	printf("X");
	else
	printf(" ");
        printf("\n");
}
    printf("\n\n\n\n\n");
   	a = 0;
	while( a < 10) {
       	
	b=0;
	while ( b < 15){
	     printf("X");
	b++;
}
	printf("\n");
	a++;
	}
    return 0;
}


