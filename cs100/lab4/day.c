#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int month=atoi(argv[1]);	
	int day=atoi(argv[2]);
	
	int a=0;
	if( month == 1) a=0;
	else if (month == 2) a=31;
	else if (month == 3) a=60;
	else if (month == 4) a=91;
	else if (month == 5) a=121;
	else if (month == 6) a=152;
	else if (month == 7) a=182;
	else if (month == 8) a=213;
	else if (month == 9) a=244;
	else if (month == 10) a=274;
	else if (month == 11) a=305;
	else if (month == 12) a=335;
	
	int totalDays=0;
	totalDays= a + day;
	
	printf("This is the %d day of the year.\n", totalDays);
	return 0;
}
