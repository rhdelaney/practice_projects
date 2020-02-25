#include <iostream>
using namespace std;

unsigned long long gcd (unsigned long long a, unsigned long long b)
{
  if (b == 0)
  {
    return a;
  }
  
  return gcd(b, a % b);  
}

int main ( ) {
  cout << "gcd(2,3) = " << gcd(2,3) << endl;
  cout << "gcd(10,15) = " << gcd(10,15) << endl;
  cout << "gcd(40,50) = " << gcd(40,50) << endl;
  cout << "gcd(55,89) = " << gcd(55,89) << endl;
  cout << "gcd(125,150) = " << gcd(125,150) << endl;
  cout << "gcd(500,700) = " << gcd(500,700) << endl;
  cout << "gcd(729,1024) = " << gcd(729,1024) << endl;
  cout << "gcd(8000,1024) = " << gcd(8000,1024) << endl;
  cout << "gcd(729,81000) = " << gcd(729,81000) << endl;
  cout << "gcd(2401,98000) = " << gcd(2401,98000) << endl;
  cout << "gcd(1024,1000000) = " << gcd(1024,1000000) << endl;
  cout << "gcd(323323,121030) = " << gcd(323323,121030) << endl;
  cout << "gcd(3656158440062976,1000000000000000000) = " << gcd(3656158440062976,1000000000000000000) << endl;
  // cout << "gcd(-2,-3) = " << gcd(10,5) << endl;
  return 0;
}
