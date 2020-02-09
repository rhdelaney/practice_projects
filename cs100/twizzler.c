#include <stdio.h>
#include <math.h>

int main() {
	int dist;
	printf("Enter the number of miles to cover : ");
	scanf("%d", &dist);

	int answer;
	answer = dist * 5280. * 12.;	// convert miles to inches
	answer = ceil(answer / 8.0);	// each twizzler is 8 inches
	answer = ceil(answer / 30.0);		// a pack has 30 twizzlers

	printf("It takes %d packages of twizzlers to go %d miles\n", answer, dist);

	return 0;
}
