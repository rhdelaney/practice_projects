#include <stdio.h>
#include <math.h>
//Raychel Delaney
//If there were only pennies, how many pennies would they have?
//How much would the pennies weigh?
//How much space do they take up?
//fix the volume, needs to be multiplied by pi.
int getMoney(char *);
int main(){
	int total=0;
	double weight=2.5*(2.2046/1000);
	double volume=(((.140625)*(.05984251968504))*(3.14159))/(12*12*12);
	int twenties=getMoney("twenties");
	int tens=getMoney("tens");
	int fives=getMoney("fives");
	int ones=getMoney("ones");
	int quarters=getMoney("quarters");
	int dimes=getMoney("dimes");
	int nickels=getMoney("nickels");
	int pennies=getMoney("pennies");
	
	twenties=twenties*2000;
	tens=tens*1000;
	fives=fives*500;
	ones=ones*100;
	quarters=quarters*25;
	dimes=dimes*10;
	nickels=nickels*5;
	total=pennies+nickels+dimes+quarters+ones+fives+tens+twenties;
	printf("You would have %d pennies!\n", total);
	weight= (double)total *weight;
	printf("That many pennies weights %lf pounds!\n", weight);
	volume=(double)total *volume;
	printf("The volume of the pennies is %lf cubic feet.\n", volume);
}

int getMoney(char *money){
	int mon;
	printf("How many %s do you have?", money);
	scanf("%d", &mon);
	return mon;
}
