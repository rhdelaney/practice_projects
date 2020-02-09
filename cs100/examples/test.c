#include <stdio.h>

double findMax(double a, double b, double c) 
{
	double max=a;
	if (b>max) max=b;
	if (c>max) max=c;
	return max;
}
int main(){
	printf("Enter a real number: ");
	double a;
	scanf("%lf", &a);
	printf("Enter another real nuber: ");
	double b;
	scanf("%lf", &b);
	printf("Enter another real number: ");
	double c;
	scanf("%lf", &c);
	double max;
	max=findMax( a,b,c); 
	printf("The max is %lf", max );
	return 0;
}
