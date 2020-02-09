#include <stdio.h>

void day01(void);
void day02(void);
void day03(void);
void day04(void);
void day05(void);
void day06(void);
void day07(void);
void day08(void);
void day09(void);
void day10(void);
void day11(void);
void day12(void);

int main( ) {
	printf("\nOn the first day of Christmas, my true love gave to me\n");
	day01();
	printf("\nOn the second day of Christmas, my true love gave to me\n");
	day02();
	printf("\nOn the third day of Christmas, my true love gave to me\n");
	day03();
	printf("\nOn the fourth day of Christmas, my true love gave to me\n");
	day04();
	printf("\nOn the fifth day of Christmas, my true love gave to me\n");
	day05();
	printf("\nOn the sixth day of Christmas, my true love gave to me\n");
	day06();
	printf("\nOn the seventh day of Christmas, my true love gave to me\n");
	day07();
	printf("\nOn the eighth day of Christmas, my true love gave to me\n");
	day08();
	printf("\nOn the nineth day of Christmas, my true love gave to me\n");
	day09();
	printf("\nOn the tenth day of Christmas, my true love gave to me\n");
	day10();
	printf("\nOn the eleventh day of Christmas, my true love gave to me\n");
	day11();
	printf("\nOn the twelfth day of Christmas, my true love gave to me\n");
	day12();

	return 0;
}

// EACH OF THE FOLLOWING FUNCTIONS MUST
// 1. Have a single print statement that only prints one line
// 2. Have a single function call to one other "dayNN" function
//	Except for day01, which does not call any other functions 
//

void day01() {
	printf("\ta partridge in a pear tree\n");
	return;
} 

void day02() {
	// print a line of output here, this day was two turtle doves
	printf("\ttwo tutle doves\n");
	// call one other dayNN function here (what else did you get?)
	day01();
	return;
}

void day03() {
	// print a line of output here, this day was three french hens
	printf("\tthree french hens\n");
	// call one other dayNN function here
	day02();
	return;
}

void day04() {
	// print a line of output here, this day was four calling birds
	printf("\tfour calling birds\n");
	// call one other dayNN function here
	day03();
	return;
}

void day05() {
	// print a line of output here, this day was five golden rings
	printf("\tfive golden rings\n");
	// call one other dayNN function here
	day04();
	return;
}

void day06() {
	// print a line of output here, this day was six geese a-laying
	printf("\tsix geese a-laying\n");
	// call one other dayNN function here
	day05();
	return;
}

void day07() {
	// print a line of output here, this day was seven swans a-swimming
	printf("\tseven swans a-swimming\n");
	// call one other dayNN function here
	day06();
	return;
}

void day08() {
	// print a line of output here, this day was eight maids a-milking
	printf("\teight maids a-milking\n");
	// call one other dayNN function here
	day07();
	return;
}

void day09() {
	// print a line of output here, this day was nine ladies dancing
	printf("\tnine ladies dancing\n");
	// call one other dayNN function here
	day08();
	return;
}

void day10() {
	// print a line of output here, this day was ten lords a-leaping
	printf("\tten lords a-leaping\n");
	// call one other dayNN function here
	day09();
	return;
}

void day11() {
	// print a line of output here, this day was eleven pipers piping
	printf("\televen pipers piping\n");
	// call one other dayNN function here
	day10();
	return;
}

void day12() {
	// print a line of output here, this day was twelve drummers drumming
	printf("\ttwelve drummers drumming\n");
	// call one other dayNN function here
	day11();
	return;
}
