#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

class ItemToPurchase {
private:
	string itemName;
	int itemPrice;
	int itemQuantity;
public:
	ItemToPurchase();
	void SetName();
	string GetName();
	void SetPrice();
	int GetPrice();
	void SetQuantity();
	int GetQuantity();
}