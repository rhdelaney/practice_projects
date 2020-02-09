#include <stdio.h>

int main(){

	printf("Enter a number: ");
	int a;
	scanf("%d", &a);
	printf("Enter a nubmer: ");
	int b;
	scanf("%d", &b);
	
	int i;
	
	if(a<b){
	for(i=a;i<=b; i++){	
	printf("%d\n",i);
	}
	}
	else {
	for(i=a;i>=b; i--){
	printf("%d\n",i);
	}
	}
	return 0;
}
