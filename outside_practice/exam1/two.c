#include <stdio.h>

int pencilPage(int);

int writingTime(int);

int main() {
	printf("How many pencils do you have? ");
	int pencil;
	scanf("%d", &pencil);
	int page = 0;
	page = pencilPage(pencil);
	int hour = 0;
	hour = writingTime(page);
	printf("You can write %d pages in %d hours\n", page, hour);
	return 0;
}

int pencilPage(int a) {
	a = a * 45000;
	int pages = 0;
	pages = a / 350;
	return pages;
}

int writingTime(int b) {
	int time = 0;
	time = (b * 20) / 60;
	return time;
}
