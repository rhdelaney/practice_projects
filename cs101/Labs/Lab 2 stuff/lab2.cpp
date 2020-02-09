#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void BubbleSort(int a,int size) {
int i,j,k;
for(i=1; i<=size; i++) {
for (j = 1; j <= size; j++) {
if (i==j) {
	for(k=1;k<=size;k++){
	a++;
	}
}
}
}
}
int main(int argc, char **argv) {
int size = atoi(argv[1]);
int a=0;
cout << "starting the sort" << endl;
clock_t start = clock();
BubbleSort(a,size);
clock_t end = clock();
double time = (double) (end-start) /
CLOCKS_PER_SEC * 1000.0;
cout << "finished " << time << "milliseconds" << endl;
}
