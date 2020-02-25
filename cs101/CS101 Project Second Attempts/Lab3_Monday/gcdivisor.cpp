#include <iostream>
using namespace std;

template <unsigned long long A, unsigned long long B>
struct  GCD
{
  enum {value= GCD<B, A%B>::value};
};
template <unsigned long long A>
struct GCD <A, 0>
{
	enum {value = A};
};

int main ( ) {
  cout << "GCD<2,3>::value = " << GCD<2,3>::value << endl;
  cout << "GCD<10,15>::value = " << GCD<10,15>::value << endl;
  cout << "GCD<40,50>::value = " << GCD<40,50>::value << endl;
  cout << "GCD<55,89>::value = " << GCD<55,89>::value << endl;
  cout << "GCD<125,150>::value = " << GCD<125,150>::value << endl;
  cout << "GCD<500,700>::value = " << GCD<500,700>::value << endl;
  cout << "GCD<729,1024>::value = " << GCD<729,1024>::value << endl;
  cout << "GCD<8000,1024>::value = " << GCD<8000,1024>::value << endl;
  cout << "GCD<729,81000>::value = " << GCD<729,81000>::value << endl;
  cout << "GCD<2401,98000>::value = " << GCD<2401,98000>::value << endl;
  cout << "GCD<1024,1000000>::value = " << GCD<1024,1000000>::value << endl;
  cout << "GCD<323323,121030>::value = " << GCD<323323,121030>::value << endl;
  cout << "GCD<3656158440062976,1000000000000000000>::value = " << GCD<3656158440062976,1000000000000000000>::value << endl;
  // cout << "GCD<-2,-3>::value = " << GCD<10,5>::value << endl;
  return 0;
}
