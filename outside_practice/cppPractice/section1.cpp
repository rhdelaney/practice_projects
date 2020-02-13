#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
	string mystr;
	cout<< "What's your name? ";
	getline (cin, mystr);
	cout << "Hello " << mystr << ".\n";
	cout << "What is your favorite team?";
	getline (cin, mystr);
	cout << "I like " << mystr << " too!\n";

	float price=0;
	int quantity=0;

	cout << "Enter price: ";
	getline (cin,mystr);
	stringstream(mystr) >> price;
	cout << "Enter quantity: ";
	getline(cin,mystr);
	stringstream(mystr) >> quantity;
	cout << "Total Price: " << price * quantity << endl;

	return 0;
}
