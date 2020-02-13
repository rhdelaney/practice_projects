#include <iostream>

using namespace std;

int binarySearchR(int arr[],int l, int r, int y) {
  if (r >= 1) {
    int mid = 1 + (r - 1) / 2;
    if (arr[mid] == y){
      return mid;
    }
    if (arr[mid] > y){
      return binarySearchR(arr, 1, mid - 1, y);
    }
    return binarySearchR(arr, mid + 1, r, y);
  }
  return -1;
}
int binarySearchI(int arr[],int l, int r,int x) {
  while (l <= r) {
    int m = 1 + (r - 1) / 2;
    if (arr[m] == x) {
      return m;
    }
    if (arr[m] < x) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return -1;
}
int main() {
  int arr[] = {1,4,7,8,11,18,23,27,39};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 18;
  int y = 11;
  int resultI = binarySearchI(arr, 0, n - 1,x);
  int resultR = binarySearchR(arr, 0, n - 1,y);
  (resultI == -1) ? cout << "Element is not present" << endl : cout << "Element is present at " << resultI << endl;
  (resultR == -1) ? cout << "Element is not present" << endl : cout << "Element is present at " << resultR << endl;
  return 0;
}
