#include <stdio.h>

int main() {
	double hours;
	double year = 0;
	double percent = 0;
	double twentyOne = 0;
	printf("Enter the number of hours you sleep each night: ");
	scanf("%lf", &hours);
	year = hours * 365;
	printf("Hours of sleep  per year; %lf\n", year);
	percent = (year / 8760) * 100;
	printf("Percent of year asleep: %lf\n", percent);
	twentyOne = year * 21;
	printf("Total hours of sleep by your 21st: %lf\n", twentyOne);
	return 0;
}
