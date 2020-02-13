#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "ItemToPurchase.h"
using namespace std;

int main() {
  cout << "Item 1" << endl;
  cout << "Enter the item name: " << endl;
  cin >> itemName;
  cout << "Enter the item price: " << endl;
  cin >> itemPrice;
  cout << "Enter the item quantity: " << endl << endl;
  cin >> itemQuantity;
  cout << "Item 2" << endl;
  cout << "Enter the item name: " << endl;
  cin >> itemName2;
  cout << "Enter the item price: " << endl;
  cin >> itemPrice2;
  cout << "Enter the item quantity: " << endl << endl;
  cin >> itemQuantity2;


  cout << "TOTAL COST" << endl;
  cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = " << itemPrice * itemQuantity << endl;
  cout << itemName2 << " " << itemQuantity2 << " @ $" << itemPrice2 << " = " << itemPrice2 * itemQuantity2 << endl << endl;

  cout << "Total: " << endl;
	return 0;
}
