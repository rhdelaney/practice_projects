#include <iostream>
#include <cstdlib>
using namespace std;

void hdiamond(int n);
//void diamond(int n, int x, int y, int z);
int main(int argc, char *argv[]){
	int n = atoi(argv[1]);
	//int y=n;
	//int x=n;
	//int i=0;
	//int z=n*2-1;
	hdiamond(n);
	//diamond(i,x,y,z);
	return 0;
}
void hdiamond(int n) {
	for (int j = 0;j <= 2 * n;j++) {
	  if (j == n) {
			j++;
		}
		else {
		  for (int i = 0;i <= 2 * n;i++) {
		    if (i <= n) {
			    if (j < n - i || j > n + i) {
				    cout << " ";
				  }
				  else {
				    if (j == n + i || j == n - i) {
					    cout << "X";
					  }
					  else {
					    cout << ".";
				  	}
				  }
			  }
			  else {
			  	if (j < i - n || j > 3 * n - i) {
					  cout << " ";
			  	}
				  else {
					  if (j == 3 * n - i || j == i - n) {
					    cout << "X";
					  }
					  else {
					    cout << ".";
					  }
				  }
	      }
      }
	  cout << "\n";
    }
  }
}
//void diamond(int i, int x, int y,int z){
//	if(i<x){
//		cout<<" ";
//		diamond(i++,x,y,z);}
//	else if(i>=x && i<=y){
//		cout<<"X";
//		diamond(i++,x--,y++,z);}
//	if(i==z){
//		diamond(i=0,x,y,z);}
//
//}
