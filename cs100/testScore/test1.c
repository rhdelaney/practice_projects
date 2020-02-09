#include <stdio.h>

char letterGrade(int num){
	char grade;
	if(num>= 90) 
		grade = 'A';
	else if(num>=80)
		grade = 'B';
	else if(num>=70)
		grade = 'C';
	else if(num>=60)
		grade = 'D';
	else
		grade = 'F';
	return grade;
}
int main(){
	printf("Enter your numerical score: ");
	int num;
	scanf("%d", &num);
	char grade=letterGrade(num);
	printf("Your letter grade is : %c\n", grade);
	return 0;
}
