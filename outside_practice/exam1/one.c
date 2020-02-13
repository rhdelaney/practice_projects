#include <stdio.h>
int main() {
	printf("What hour and minutes did you wake up today at? ");
	int hour;
	int minute;
	scanf("%d %d", &hour, &minute);
	hour = (14 - hour);
	minute = (hour * 60) - minute;
	printf("You were awake %d minutes before the exam.\n", minute);
	return 0;
}
