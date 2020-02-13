#include <iostream>
using namespace std;

int sub(int a, int b) {
	int r;
	r = a - b;
	return r;
}
void duplicate(int& a, int& b, int& c) {
	a *= 2;
	b *= 2;
	c *= 2;
}

long factorial(long a) {
	if (a > 1)
	  return (a * factorial (a - 1));
	else
	  return 1;
}
void odd(int x);
void even(int x);

int main() {
	int x = 5, y = 3, z;
	int a = 1, b = 3, c = 7;
	z = sub(10,4);
	cout << "The first result is " << z << ".\n";
	cout << "The second result is " << sub(7,2) << ".\n";
	cout << "The third result is " << sub(x,y) << ".\n";
	duplicate(a,b,c);
	cout << "The fourth result is " << a << " " << b << " " << c << ".\n";
	int i;
	do {
	  cout << "Please, enter number (0 to exit): ";
	  cin >> i;
	  odd(i);
	} while(i != 0);

	long number = 9;
	cout << number << "!= " << factorial(number) << "\n";
	return 0;
}
void odd(int x) {
	if ((x%2) != 0)
		cout << "It is odd.\n";
	else
		even(x);
}
void even(int x) {
	if ((x%2)==0)
		cout << "It is even.\n";
	else
		odd(x);
}
