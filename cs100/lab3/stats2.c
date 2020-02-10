#include <stdio.h>
#include <math.h>

void readData(int *);
double findMean(int *);
double findVariance(int *, double);
void printResults(double, double, double);

int main( ) {
	int array[5];
	readData(array);
	double mean, variance, stddev;
	mean = findMean(array);
	variance = findVariance(array, mean);
	stddev = sqrt(variance);
	printResults(mean, variance, stddev);
	return 0;
}
void readData(int *array){
	printf("Enter the first value: ");
	scanf("%d", &array[0]);
	printf("Enter the second value: ");
	scanf("%d", &array[1]);
	printf("Enter the third value: ");
	scanf("%d", &array[2]);
	printf("Enter the fourth value: ");
	scanf("%d", &array[3]);
	printf("Enter the fifth value: ");
	scanf("%d", &array[4]);
	return;
}
double findMean(int *array){
	double result;
	result = array[0] + array[1] + array[2] + array[3] + array[4];
	result= result/5.0;
	return result;
}
double findVariance(int *array, double mean){
	double result1;
	result1 = ((array[0] - mean) * (array[0] - mean)) + ((array[1] - mean) * (array[1] - mean)) + ((array[2] - mean) * (array[2] - mean)) + ((array[3] - mean) * (array[3] - mean)) + ((array[4] - mean) * (array[4] - mean));
	return result1;
}
void printResults(double mean, double variance, double stddev){
	printf("The mean of the array is: %lf\n", mean);
	printf("The variance of the array is: %lf\n", variance);
	printf("The standard deviation of the array is: %lf\n", stddev);
	return;
}
