#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count(int num);

int main(){
	int num=0;
	count(num);
	return 0;
}
int count(int num){
	int i;	
	int digit=0;
	int max=0;
	printf("Enter a positive integer or 0 to exit: ");
	scanf("%d", &num);
	if(num==0){
	return 0;}
	else{
	for(i=1;i<=num;i*=10){
		max= num/i;
		digit++;}
	printf("There are %d digits in %d\n", digit, num);
	return count(num);}
}
	
//int count(int num){
//	int digit=0;
//	int num1=num;
//	int i;
//	if(num==0){ return 0;}
//	else{
//	for(i=1;i<num;i*=10){
//		digit= num/i;}
//	printf("There are %d digits in %d \n", digit, num1);
//	return 1;
//	}
//}
