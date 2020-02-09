#include <stdio.h>
	int main(){
	int gallons;
	int snowflakes=0;
	printf("How many gallons of water do you have? ");
	scanf("%d", &gallons);
	snowflakes= (gallons * 3780000)/3;
	printf("Number of snow flakes you can make: %d\n", snowflakes);
	return 0;
}
