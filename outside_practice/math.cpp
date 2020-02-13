#include <iostream>
using namespace std;

void hdiamond(int n);

int main(int argc, char *argv[]) {
        int n = atoi(argv[1]);
        //int Y=0;
        hdiamond(n);
        //diamond(n,y);
        return 0;
}
void hdiamond(int n) {
  int x = n;
  int y = n;
  for (int j = 0; j < 2 * n - 1;j++) {
    for (int i = 0; i < 2 * n - 1;i++) {
	    if (i == x || i==y) {
		    cout<<"X";
      }
	    else if (i > x && i < y) {
		    cout << ".";
      }
	    else {
		    cout << " ";
      }
    }
    x--;
    y++;
    cout<<"\n";
  }
}
