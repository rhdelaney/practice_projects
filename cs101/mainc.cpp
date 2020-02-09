// Main.cpp
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Contacts.h"
using namespace std;

int main(){
string name;
string number;
cout<<"Person 1"<<endl;
cout<<"Enter name: "<<endl;
getline(cin,name);
cout<<"Enter phone number: "<<endl;
getline(cin,number);
ContactNode p1(name,number);
cout<<"You entered: "<<p1.GetName()<<", "<<p1.ContactNode()<<endl<<endl;

cout<<"Person 2"<<endl;
cout<<"Enter name: "<<endl;
getline(cin,name);
cout<<"Enter phone number: "<<endl;
getline(cin,number);
ContactNode p2(name,number);
cout<<"You entered: "<<p1.GetName()<<", "<<p1.GetPhoneNumber()<<endl<<endl;

cout<<"Person 3"<<endl;
cout<<"Enter name: "<<endl;
getline(cin,name);
cout<<"Enter phone number: "<<endl;
getline(cin,number);
ContactNode p3(name, number);
cout<<"You entered: "<<p3.GetName()<<", "<<p3.GetPhoneNumber()<<endl<<endl;

cout<<"CONTACT LIST"<<endl;
p1.PrintContactNode();
p2.PrintContactNode();
p3.PrintContactNode();
	return 0;
}