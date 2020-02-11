#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void BubbleSort (int arr[], int size) {
   int i,j,tmp;
   for(j = 1; j < size; j++) {
     for (i = 0; i < size - j; i++) {
        if (arr[i] > arr[i + 1]) {
           tmp = arr[i];
           arr[i] = arr[i + 1];
           arr[i + 1] = tmp;
        }
     }
   }
}

int main (int argc, char **argv) {
    int size = atoi(argv[1]);
    int a[size];
    for(int i = 0; i < size; i++) {
        a[i] = rand();
        /* std::cout << a[i] << endl; */
    }
    cout << "starting the sort" << endl;
    clock_t start = clock();

    BubbleSort(a,size);

    clock_t end = clock();
    double time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
    cout << "finished " << time << " milliseconds" << endl;
    return 0;
}
