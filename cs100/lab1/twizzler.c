#include <stdio.h>

int main() {
	double distance;
	double twizdistance = 0;
	double package = 0;
	printf("Enter distance in miles that you want to travel: ");
	scanf("%lf", &distance);
	twizdistance = (distance * 63360) / 8;
	printf("Number of individual twizzlers needed to travel that distance: %lf\n", twizdistance);
	package = twizdistance / 30;
	printf("Packages of twizzlers needed: %lf\n", package);
	return 0;
}
