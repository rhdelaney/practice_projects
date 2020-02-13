#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
	cout << "Enter number of test cases: ";
	int testCases = 0;
	cin >> testCases;

	int start[testCases - 1];
	int stop[testCases - 1];
	int prime = 0;
	for (int i = 0;i < testCases;i++) {
	  cout << "Enter a range:";
	  cin >> start[i];
	  cin >> stop[i];
  }
  for (int k = 0;k < testCases;k++) {
    for (int i = start[k];i <= stop[k];i++) {
	    for (int j = 2;j < i;j++) {
		    if ((i % j) == 0) {
			  	prime += 1;
			  }
		  }
		  if (prime == 0) {
		    cout << i << endl;
		  }
		  else {
		    prime = 0;
		  }
	  }
    cout<<endl;
	}
}
