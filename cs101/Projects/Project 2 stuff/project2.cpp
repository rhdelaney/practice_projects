#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "random.h"
#include <ctime>
using namespace std;

//FIXING LIST:
//work on count increments!!!!!!!

//Raychel Delaney -rhdelaney cs-101 Borie - 

//steps and to do:
//1.make arrays for the 6 diff type-----DONE :Ds
//2.put each array through the 5 different sorts---->IN PROGRESS(CONSIDER MAKING VOID FUNCTIONS CALLING TO THE 5 SORT FUNCTIONS....)
//3.count # of times operations performed using global variables
//				->Comparisons
//				->Swaps
//				->Assignments
//4. add them and send that to output/stdout

void identical(int size);
void ascend(int size);
void descend(int size);
void rev(int size);
void negR(int size);
void ran(int size);

void printArr(float *arr,int size);
void resetArr(float *arr,float *temp,int size);

int insert(float *arr,int size);
int select(float *arr,int size);
int bubble(float *arr,int size);
int merge(float *arr,int size);
int MergeSort(float* arr,int size, int first, int last,int count);
int mergeS(float* arr,int size, int leftFirst, int leftLast, int rightFirst, int rightLast,int count);

//int quick(float *arr,int size); 
int quickSort(float *arr, int left, int right);

int main(int argc, char *argv[]){
	int given=atoi(argv[1]);

	cout<<"Sort"<<given<<",Insertion,Selection,Bubble,Merge,Quick\n";
	cout<<"Identical,"; identical(given); cout<<"\n";
	cout<<"Ascend,"; ascend(given); cout<<"\n";
	cout<<"Descend,"; descend(given); cout<<"\n";
	cout<<"RevDigit,"; rev(given); cout<<"\n"; 
	cout<<"NegRevDigit,"; negR(given); cout<<"\n";
	cout<<"Random,"; ran(given); cout<<"\n";
	return 0;
}
void identical(int size){
	float arr[size];
	for(int i=0;i<size;i++){
		arr[i]=0;}
	printArr(arr,size);
	return;
}
void ascend(int size){
	float arr[size];
	for(int i=0;i<size;i++){
		arr[i]= i;}
		printArr(arr,size);
		return;
	}
void descend(int size){
	float arr[size];
	for(int i=0;i<size;i++){
		if(i==0){
			arr[i]=0;
			}
		else{
		arr[i]=-1.0* i;}}
	printArr(arr,size);
	return;
}
void rev(int size){
	float arr[size];
	int i=0;
	for(int n=0;n<size;n++){
		i=n;
		int times=0;	
		float reverse=0;
		while(n!=0){
			int remainder=n%10;
			reverse=reverse*10+remainder;
			n/=21;
			times++;}	
		while(times!=0){
			reverse/=10;
			times--;}
		arr[i]=reverse;
		n=i;}
	printArr(arr,size);
	return;
}
void negR(int size){
	float arr[size];
	int i=0;
	for(int n=0;n<size;n++){
		if(n==0){
			arr[n]=0;}
		else{
		i=n;
		int times=0;	
		float reverse=0;
		while(n!=0){
			int remainder=n%10;
			reverse=reverse*10+remainder;
			n/=10;
			times++;}	
		while(times!=0){
			reverse/=10;
			times--;}
		arr[i]=-1.0*reverse;
		n=i;}}
	printArr(arr,size);
	return;
}
void ran(int size){
	float arr[size];
	srand((unsigned)time(0));
	for(int n=0;n<size;n++){
		arr[n]=(rand()%100)+1;}
		printArr(arr,size);	
	return;
}
void printArr(float *arr, int size){
	float temp[size];
	for(int i=0;i<size;i++){
		temp[i]=arr[i];}
	cout<<insert(arr,size)<<",";
	resetArr(arr,temp,size);
	cout<<select(arr,size)<<",";
	resetArr(arr,temp,size);
	cout<<bubble(arr,size)<<",";
	resetArr(arr,temp,size);
	cout<<merge(arr,size)<<",";
	resetArr(arr,temp,size);
	cout<<quickSort(arr,0, size-1);
	return;
}
void resetArr(float *arr,float *temp, int size){
	for(int i=0;i<size;i++){
		arr[i]=temp[i];}
	return; 
}
int insert(float *arr,int size){
	int count=0;
	int j;
	float temp;
	for (int i = 1; i < size; i++){
		j = i;
			while(j>0 && arr[j] < arr[j-1]){
					count+=2;
					temp = arr[j]; 
					arr[j] = arr[j-1];
					arr[j-1] = temp;
					j--;}
			if(j>0){
				count+=1;
					}
		}
	return count;}
int select(float *arr,int size){
	int count=0;
	int i, j,first;
	float temp;
	for (i = 0; i < size; i++){
		first = i;
		for (j=i+1; j<size; j++){	
			count+=1;
			if (arr[j] < arr[first]){
				first = j;}}
			if(first!=i){	
			temp = arr[first]; 	
			arr[first] = arr[i];
			arr[i] = temp;
			count+=1;}
		}
	return count;
}
int bubble(float *arr,int size){
	int count=0;
	int i,j;
	float tmp;
	for(j=1; j<size; j++) {
		bool flag=false;
		for (i = 0; i < size - j; i++){
			count+=1;
			if (arr[i] > arr[i + 1]) {
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag=true;
				count+=1;}
			}
		if (!flag){ break;}
	}
	return count;
}
int merge(float *arr,int size){
	int count=0;
	count=MergeSort(arr,size, 0, size-1,count);	
	return count;
}
int MergeSort(float* arr,int size, int first, int last,int count) {
    if (first < last)   {
        int middle = (first + last) / 2;
      	MergeSort(arr,size, first, middle, count);
       	MergeSort(arr,size, middle + 1, last, count);
        count+=mergeS(arr,size, first, middle, middle + 1, last, count);
   	count+=1;
	 }
	return count;
}
int mergeS(float* arr,int size, int leftFirst, int leftLast, int rightFirst, int rightLast,int count){
    float tempArray[size];
    int index = leftFirst;
    int saveFirst = leftFirst;;	
    	count++;
	while (leftFirst <= leftLast && rightFirst <= rightLast)    {
	 if (arr[leftFirst] < arr[rightFirst]) {
            tempArray[index] = arr[leftFirst];
            leftFirst++;
       		count+=2;
	 }
        else{
            tempArray[index] = arr[rightFirst];
            rightFirst++;
        	count+=2;}

        index++;
        count+=2;      // <<---count increment
    }
	if(!(leftFirst<=leftLast || rightFirst<=rightLast)){
		count+=2;}
    while (leftFirst <= leftLast)   {
        tempArray[index] = arr[leftFirst];
        leftFirst++;
        index++;
	count+=2;
    }
	if(!(leftFirst<= leftLast)){
		count+=1;
		}
    while (rightFirst <= rightLast) {
        tempArray[index] = arr[rightFirst];
        rightFirst++;
        index++;
	count+=2;
    	}
	if(!(rightFirst<=rightLast)){
		count+=1;}
    for (index = saveFirst; index <= rightLast; index++){
        arr[index] = tempArray[index];
	count+=1;}
	return count;
}
int quickSort(float *arr, int left, int right) {
	int i = left, j = right;
	float tmp;
	float pivot = arr[(left + right) / 2];
	int count=0;
	while (i <= j) {
		while (arr[i] < pivot){ i++;count+=1;}
		while (arr[j] > pivot){ j--; count+=1;}
			count+=2;
			if (i <= j) {
				tmp = arr[i];
		 		arr[i] = arr[j];
		 		arr[j] = tmp;
				i++;
				j--;
				count+=1;}
		}	
	count++;
	if (left < j){
		count+=quickSort(arr, left, j);}
	if (i < right){
		count+=quickSort(arr, i, right);}
	return count;
}
