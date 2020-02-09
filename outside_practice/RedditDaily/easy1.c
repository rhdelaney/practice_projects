#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char name[30];
	int age=0;
	char username[30];
	printf("What is your name? \n");
	scanf("%s", name);
	printf("What is your age? \n");
	scanf("%d", &age);
	printf("What is your username \n");
	scanf("%s", username);
	
	printf("your name is %s you are %d years old, and your username is %s\n", name, age, username);
	return 0;
}
