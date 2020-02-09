#include <stdio.h>
	int main(){
	int num;
	int total=0;
	double average=0;
	printf("Enter the first number: ");
	scanf("%d", &num);
	total= total+ num;
	printf("Enter the second number: ");
	scanf("%d", &num);
	total= total + num;
	printf("Enter the third number: ");
	scanf("%d", &num);
	total= total + num;
	printf("Enter the fourth number: ");
	scanf("%d", &num);
	total= total + num;
	printf("Enter the fifth number: ");
	scanf("%d", &num);
	total=total + num;
	average= (double)total /5;
	printf("The sum is %d\n", total);
	printf("The average is %lf\n", average);
	return 0;
}
