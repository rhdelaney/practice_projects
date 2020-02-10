#include <stdio.h>
#include <math.h>

int main() {
		int a[5];
		double total = 0;
		double mean = 0;
		double variance = 0;
		double sd = 0;
		printf("Enter an integer: ");
		scanf("%d", &a[0]);
		total = total +  a[0];
		printf("Enter an integer: ");
		scanf("%d", &a[1]);
		total = total +  a[1];
		printf("Enter an integer: ");
		scanf("%d", &a[2]);
		total = total +  a[2];
		printf("Enter an integer: ");
		scanf("%d", &a[3]);
		total = total +  a[3];
		printf("Enter an integer: ");
		scanf("%d", &a[4]);
		total = total +  a[4];
		mean = total / 5;
		printf("Mean= %lf ", mean);
		variance = (((a[0] - mean) * (a[0] - mean)) + ((a[1] - mean) * (a[1] - mean)) + ((a[2] - mean) * (a[2] - mean)) + ((a[3] - mean) * (a[3] - mean)) + ((a[4] - mean) * (a[4] - mean))) / 5;
		printf("Variance= %lf", variance);
		sd = sqrt(variance);
		printf("Standard Deviation= %lf", sd);
		return 0;
}
