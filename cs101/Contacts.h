//Contacts.h
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class ContactNode {		
	public:	
		string contactName;
		string contactPhoneNum;
		ContactNode* nextNodePtr;
		//ContactNode* head;
		//ContactNode* tail;

		ContactNode(string name, string number);
		void InsertAfter(string name, string number);
		//void InsertAfter(ContactNode temp);
		string GetName();
		string GetPhoneNumber();
		ContactNode* GetNext();
		void PrintContactNode();
	};