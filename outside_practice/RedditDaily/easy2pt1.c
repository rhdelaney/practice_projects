#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int squareA(){
	int area=0;
	int s;
	printf("What is the size of one side of the square?\n");
	scanf("%d", &s);
	area=s*s;
	return area;}
int rectangleA(){
	int area=0;
	int l, w;
	printf("What is the size of the length?\n");
	scanf("%d", &l);
	printf("What is the size of the width?\n");
	scanf("%d", &w);
	area=l*w;
	return area;}
int parallelogramA(){
	int area=0;
	int b;
	int h;
	printf("What is the base?\n");
	scanf("%d", &b);
	printf("What is the height?\n");
	scanf("%d", &h);
	area=b*h;
	return area;
}
int triangleA(){
	int area=0;
	int b;
	int h;
	printf("What is the base?\n");
	scanf("%d", &b);
	printf("What is the height?\n");
	scanf("%d", &h);
	area= (1/2)*b*h;
return area;
	}
int circleA(){
	int area=0;
	int r;
	double pi=3.14;
	printf("What is the length of the radius?\n");
	scanf("%d", &r);
	area=pi*r*r;
	return area;
}
int trapezoidA(){
	int area=0;
	int b1;
	int b2;
	int h;
	printf("What is the length of the first base?\n");
	scanf("%d", &b1);
	printf("What is the length of the second base?\n");
	scanf("%d", &b2);
	printf("what is the height?\n");
	scanf("%d", &h);
	area=( (1/2)*(b1+b2) )*h;
	return area;}

int main(){
	//make a reverse calculator for when you have only some parts?
	char object[13];
	printf("AREA CALCULATOR\n");
	printf("What object's area would you like to compute?\n");
	printf("Square?\nRectangle?\nParalleogram?\nTriangle?\nCircle?\nTrapezoid?\n");
	scanf("%s", object);
	int b;
	int a=0;
	char ch;
	for(b=0;b<strlen(object);b++){
		ch=object[b];
		if(isupper(ch)==0){
			ch=ch-32;
			object[b]=ch;}
		}
	if(strcmp(object,"SQUARE")==0){
		a=squareA();}

	if(strcmp(object,"RECTANGLE")==0){
		a=rectangleA();}

	if(strcmp(object,"PARALLELOGRAM")==0){
		a=parallelogramA();}

	if(strcmp(object,"TRIANGLE")==0){
		a=triangleA();}

	if(strcmp(object,"CIRCLE")==0){
		a=circleA();}
	if(strcmp(object,"TRAPEZOID")==0){
		a=trapezoidA();}
	printf("The area of the %s is %d \n", object, a);
return 0;
}
