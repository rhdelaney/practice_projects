#include <iostream>
using namespace std;


long long log (long long base, long long num)
{
  if (base==num)
  {
    return 1;
  }

  return 1+log(base, num/base);
}

int main ( ) {
  cout << "log(2,8) = " << log(2,8) << endl;
  cout << "log(-2,-8) = " << log(-2,-8) << endl;
  cout << "log(10,100) = " << log(10,100) << endl;
  cout << "log(10,1000) = " << log(10,1000) << endl;
  cout << "log(10,10000) = " << log(10,10000) << endl;
  cout << "log(10,100000) = " << log(10,100000) << endl;
  cout << "log(10,1000000) = " << log(10,1000000) << endl;
  cout << "log(10,1000000000) = " << log(10,1000000000) << endl;
  cout << "log(10,1000000000000) = " << log(10,1000000000000) << endl;
  cout << "log(10,1000000000000000) = " << log(10,1000000000000000) << endl;
  cout << "log(10,1000000000000000000) = " << log(10,1000000000000000000) << endl;
  cout << "log(2,1152921504606846976) = " << log(2,1152921504606846976) << endl;
  // cout << "log(10,5) = " << log(10,5) << endl;
  return 0;
}

