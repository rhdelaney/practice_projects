#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibo(int num);
int count=0;

int main(int argc, char *argv[]){
	int num=0;
	int value=0;
	int c;
	sscanf(argv[1],"%d",&num); 
	for(c=0; c<num;c++){
		value+=fibo(c);}
	count+=c-1;
	printf("fib(%d)=%d and has %d recursive calls.\n", num, value, count);
	return 0;
}
int fibo(int i){
	count++;
	if(i<=2){
		return 1;}
	else{
		return (fibo(i-1) + fibo(i-2));}
}
