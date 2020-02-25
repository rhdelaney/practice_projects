#include <iostream>
using namespace std;

template < long long int A , long long int B>
struct  Pow {
  enum { value= A * Pow<A, B-1>::value};

};
template<long long A>
struct Pow<A, 0> {
 enum {value= 1};
};


int main ( )
{
  cout << "Pow<2,3>::value = " << Pow<2,3>::value << endl;
  cout << "Pow<-2,3>::value = " << Pow<-2,3>::value << endl;
  cout << "Pow<10,2>::value = " << Pow<10,2>::value << endl;
  cout << "Pow<10,3>::value = " << Pow<10,3>::value << endl;
  cout << "Pow<10,4>::value = " << Pow<10,4>::value << endl;
  cout << "Pow<10,5>::value = " << Pow<10,5>::value << endl;
  cout << "Pow<10,6>::value = " << Pow<10,6>::value << endl;
  cout << "Pow<10,9>::value = " << Pow<10,9>::value << endl;
  cout << "Pow<10,12>::value = " << Pow<10,12>::value << endl;
  cout << "Pow<10,15>::value = " << Pow<10,15>::value << endl;
  cout << "Pow<10,18>::value = " << Pow<10,18>::value << endl;
  cout << "Pow<2,60>::value = " << Pow<2,60>::value << endl;
  //cout << "Pow<10,-1>::value = " << Pow<10,-1>::value << endl;
// cout << "Pow<10,20>::value = " << Pow<10,20>::value << endl;
  return 0;
}

