#include <stdio.h>
#include "scanner.h"


// Generate a typedef Student for a struct student, each record contains
//	first name (first), a char *
//	last name (last), a char *
//	three exam scores (exams), an array of three integers
//	five project scores (projects), an array of five integers
//	their average (average), a double
//	their grade (grade), a single character
typedef struct student {
char *first;
char *last;
int exams[3];
int projects[5];
double average;
char grade;
} Student;

double findNumScore(Student *pStudent){
	double total=0.0;
	int i;
	for (i=0; i<3; i++) total=total+.2*pStudent->exams[i]; 
	for (i=0; i<5; i++) total=total+.08*pStudent->projects[i];
	pStudent->average=total;
	return total; 
}

char findLetterGrade(double total){
	if (total>=90) return 'A';
	if (total>=80) return 'B';
	if (total>=70) return 'C';
	if (total>=60) return 'D';
	else return 'F';
}
void printStudnetInfo(Student *pStudent){
	printf("%s %s earned %lf which is a %c\n", pStudent->first, pStudent->last, pStudent->average, pStudent->grade);
}
int main( ) {
	// declare a variable s1 of type Student
	Student s1;
	// prompt the user for the first and last names of the student,
	//read them using readToken
	printf("Enter your first and last names: ");
	s1.first=readToken(stdin);	
	// prompt the user for the student's three exam scores,
	//		 read them using readInt
	printf("Enter your three exam scores: ");
	s1.exams[0]=readInt(stdin);
	s1.exams[1]=readInt(stdin);
	s1.exams[2]=readInt(stdin);
	// prompt the user for the student's five project scores,
	//		 read them using readInt
	printf("Enter your five exam scores: ");
	s1.projects[0]=readInt(stdin);
	s1.projects[1]=readInt(stdin);
	s1.projects[2]=readInt(stdin);
	s1.projects[3]=readInt(stdin);
	s1.projects[4]=readInt(stdin);
	// calculate the student's grade,
	//		 each exam is worth 20% and each project is worth 8%
	// print the student's name and average and letter grade
	double num=findNumScore(&s1);
	char grade=findLetterGrade(&s1);
	
    return 0;
}

