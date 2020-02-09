#include <stdio.h>
#include <stdlib.h>

int findMin(int a, int b, int c, int d, int e){
	double min=a;
	if (a>b) min=b;
	if (b>c) min=c;
	if (c>d) min=d;
	if (d>e) min=e;
	return min;
}
int findMax(int a, int b, int c, int d, int e){
	double max=a;
	if (b>a) max=b;
	if (c>b) max=c;
	if (d>c) max=d;
	if (e>a) max=e;
	return max;	

}
int main(int argc, char *argv[])
{
	if(argc!=6){
	printf("Usage: %s num1 num2 num3 num4 num5\n", argv[0]);
	return 1;
	}
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	int c=atoi(argv[3]);
	int d=atoi(argv[4]);
	int e=atoi(argv[5]);
	int min=findMin(a,b,c,d,e);
	printf("Min=%d\n", min);
	int max=findMax(a,b,c,d,e);
	printf("Max=%d\n", max);
	return 0;	
}
