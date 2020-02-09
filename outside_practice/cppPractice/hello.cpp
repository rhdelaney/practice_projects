#include <iostream>
using namespace std;

const double pi=3.14159;
const char newline='\n';

int main(){

cout << "Hello World! ";
cout << "My name is Raychel and this is my first C++ program";
cout << newline;

int result;
int a=5;
int b (3);
int c (2);
a=a+b;
result=a-c;
cout<<result;
cout<<newline;

string mystring;
mystring="This is a string";
cout<< mystring <<endl;
mystring="This is a different string information";
cout<< mystring <<endl;

double r=5.0;
double circle;
circle=2*pi*r;
cout<<circle;
cout<<newline;

int d,e,f;
d=2;
e=7;
f= (d>e) ? d : e;
cout<<f<<newline;

int i;
cout<<"Please enter an integer value: ";
cin>> i;
cout << "The value you entered is "<< i;
cout<< " and its doubled is "<< i*2 <<".\n";


return 0;
}
