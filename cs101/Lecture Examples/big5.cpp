#include <iostream>
#include <cstring>
using namespace std;

class MyString {
	char* data;
public:
	MyString( ) {					// default constructor
		cout << "Default constructor" << endl;
		data = new char[6];
		strcpy (data, "Hello");
	}
	MyString (const char *str) {			// another constructor
		cout << "Another constructor: " << str << endl;
		data = new char[strlen (str) + 1];
		strcpy (data, str);
	}
	~MyString( ) {					// destructor
		cout << "Destructor: ";
		if (data==nullptr) cout << "nullptr" << endl; else cout << data << endl;
		delete[ ] data;
	}
	MyString (const MyString& other) {		// copy constructor
		cout << "Copy constructor: " << other << endl;
		data = new char[strlen (other.data) + 1];
		strcpy (data, other.data);
	}
	MyString& operator= (const MyString& other) {	// copy assignment operator
		cout << "Copy assignment operator: " << other << endl;
		MyString temp(other);			// use copy constructor
		*this = move(temp);			// force move semantics, use move assignment operator
		return *this;
	}
	MyString (MyString&& other) { 			// move constructor, as of C++ 11
		cout << "Move constructor: " << other << endl;
		data = other.data;
		other.data = nullptr;
	}
	MyString& operator= (MyString&& other) {	// move assignment operator, as of C++ 11
		cout << "Move assignment operator: " << other << endl;
		delete[ ] data;
		data = other.data;
		other.data = nullptr;
		return *this;
	}
private:
	friend ostream& operator<< (ostream& os, const MyString& str) {
		os << str.data;
		return os;
	}
	friend MyString& operator+ (const MyString& s, const MyString& t) {
		int len = strlen(s.data) + strlen(t.data) + 1;
		char *str = new char[len];
		strcpy (str, s.data);
		strcat (str, t.data);
		MyString *temp = new MyString(str);
		return *temp;
	}
};

int main( ) {
	MyString s;
	cout << "s = " << s << endl << endl;

	MyString t (",World!");
	cout << "t = " << t << endl << endl;

	MyString u (s);
	cout << "u = " << u << endl << endl;

	u = t;
	cout << "u = " << u << endl << endl;

	MyString v (move(s + t));
	cout << "v = " << v << endl << endl;

	u = move(s + t);
	cout << "u = " << u << endl << endl;
	return 0;
}
