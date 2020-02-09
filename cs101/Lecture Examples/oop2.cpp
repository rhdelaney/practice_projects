#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	void setInfo(string Name, string Addr, string Phone);
	virtual void printInfo( );
private:
	string name;
	string address;
	string phone;
};

void Person::setInfo(string Name, string Addr, string Phone) {
	name = Name;
	address = Addr;
	phone = Phone;
}

void Person::printInfo( ) {
	cout << "Name: " << name << endl;
	cout << "Addr: " << address << endl;
	cout << "Phone: " << phone << endl;
}

class Student : public Person {
public:
	virtual void printInfo( );
	int studentID;
};

void Student::printInfo( ) {
	Person::printInfo( );
	cout << "Student ID: " << studentID << endl;
};

class Instructor : public Person {
public:
	virtual void printInfo( );
	int employeeID;
};

void Instructor::printInfo( ) {
	Person::printInfo( );
	cout << "Employee ID: " << employeeID << endl;
};

void printPersonInfo(Person &aPerson) {
	aPerson.printInfo();
};

int main( ) {
	Student aStudent;
	Instructor anInstructor;
	aStudent.setInfo("Joe Student", "1 E Main St", "555-1212");
	aStudent.studentID = 33445;
	anInstructor.setInfo("John Doe", "120 Maple Ave", "555-1313");
	anInstructor.employeeID = 12345;
	printPersonInfo(aStudent);
	printPersonInfo(anInstructor);
}
