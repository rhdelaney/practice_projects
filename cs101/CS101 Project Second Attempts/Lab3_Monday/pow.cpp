#include <iostream>
using namespace std;

long long int pow(long long int a, long long int b)
{
  if(b==0)
  {
    return 1;
  }

  if(b>=1)
  {
    return a * pow(a,b-1);
  }

  if(b<0)
  {
    return a * pow(a,b+1);
  }

  return 0;
}
int main ( ) {
  cout << "pow(2,3) = " << pow(2,3) << endl;
  cout << "pow(-2,3) = " << pow(-2,3) << endl;
  cout << "pow(10,2) = " << pow(10,2) << endl;
  cout << "pow(10,3) = " << pow(10,3) << endl;
  cout << "pow(10,4) = " << pow(10,4) << endl;
  cout << "pow(10,5) = " << pow(10,5) << endl;
  cout << "pow(10,6) = " << pow(10,6) << endl;
  cout << "pow(10,9) = " << pow(10,9) << endl;
  cout << "pow(10,12) = " << pow(10,12) << endl;
  cout << "pow(10,15) = " << pow(10,15) << endl;
  cout << "pow(10,18) = " << pow(10,18) << endl;
  cout << "pow(2,60) = " << pow(2,60) << endl;
// cout << "pow(10,-1) = " << pow(10,-1) << endl;
// cout << "pow(10,20) = " << pow(10,20) << endl;
  return 0;
}

