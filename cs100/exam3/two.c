#include <stdio.h>
#include <stdlib.h>

int findMin(int a[], int size) {
	int i;
	int min=a[0];
	for (i=0;i<size;i++){
		if(min>a[i]){
			min=a[i];}	
	}
	return min;
}
int findMax(int a[], int size) {
	int i;
	int max=a[0];
	for (i=0;i<size;i++){
		if(max<a[i]){
			max=a[i];}
		}
	return max;
}

int main(int argc, char *argv[]) {
 if (argc==1) {
 	printf("Error: it requires a list of integers as arguments.\n");
 	return 1;
 	}
 
int size=argc-1;
 int *array=(int *)malloc(sizeof(int)*size);
 int a;

 	for (a=0; a<size; a++) {
 		array[a] = atoi(argv[a+1]);
 		}
 
 printf("Min=%d\n", findMin(array, size));
 printf("Max=%d\n", findMax(array, size));
 
return 0;
}
