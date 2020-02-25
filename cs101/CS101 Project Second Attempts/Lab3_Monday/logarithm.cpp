#include <iostream>
using namespace std;

template <int BASE, long long NUM>
struct Log
{
  enum{value = 1 + Log<BASE, NUM/BASE>::value};
};
template<int BASE>
struct Log<BASE, 1>
{
  enum {value=0};
};


int main ( )
{
  cout << "Log<2,8>::value = " << Log<2,8>::value << endl;
  cout << "Log<-2,-8>::value = " << Log<-2,-8>::value << endl;
  cout << "Log<10,100>::value = " << Log<10,100>::value << endl;
  cout << "Log<10,1000>::value = " << Log<10,1000>::value << endl;
  cout << "Log<10,10000>::value = " << Log<10,10000>::value << endl;
  cout << "Log<10,100000>::value = " << Log<10,100000>::value << endl;
  cout << "Log<10,1000000>::value = " << Log<10,1000000>::value << endl;
  cout << "Log<10,1000000000>::value = " << Log<10,1000000000>::value << endl;
  cout << "Log<10,1000000000000>::value = " << Log<10,1000000000000>::value << endl;
  cout << "Log<10,1000000000000000>::value = " << Log<10,1000000000000000>::value << endl;
  cout << "Log<10,1000000000000000000>::value = " << Log<10,1000000000000000000>::value << endl;
  cout << "Log<2,1152921504606846976>::value = " << Log<2,1152921504606846976>::value << endl;
  // cout << "Log<10,5>::value = " << Log<10,5>::value << endl;
  return 0;
}

