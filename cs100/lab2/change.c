#include <stdio.h>

int main() {
	int pocket;
	int quarters = 0;
	int dimes = 0;
	int nickles = 0;
	int pennies = 0;
	int leftover = 0;
	printf("What is the total amount of change in your pocket? ");
	scanf("%d", &pocket);
	quarters = pocket / 25;
	leftover = pocket % 25;
	dimes = leftover / 10;
	leftover = leftover % 10;
	nickles = leftover / 5;
	leftover = leftover % 5;
	pennies = leftover;
	printf("You have: %d quarters.\n %d dimes.\n %d nickles.\n %d pennies.\n", quarters, dimes, nickles, pennies);
	return 0;
}
