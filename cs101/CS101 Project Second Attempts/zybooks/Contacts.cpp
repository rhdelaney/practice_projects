// Contacts.cpp
#include <iostream>
using namespace std;

#include "Contacts.h"
//Tests that InsertAfter() correctly inserts Juan Alberto Jr.'s 
//ContactNode after Roxanne Hughes's ContactNode and GetNext() 
//correctly returns Juan Alberto Jr.'s ContactNode.
		ContactNode::ContactNode(){
			contactName="";
			contactPhoneNum="";
			nextNodePtr=0;
		}
		ContactNode::ContactNode(string name,string number){
			contactName=name;
			contactPhoneNum=number;
			nextNodePtr=0;
		}
		void ContactNode::InsertAfter(string name, string number){
			ContactNode temp;
			temp.contactName=name;
			temp.contactPhoneNum=number;
			nextNodePtr=&temp;
		}
		string ContactNode::GetName(){
			return contactName;
		}
		string ContactNode::GetPhoneNumber(){
			return contactPhoneNum;
		}
		ContactNode* ContactNode::GetNext(){
			return nextNodePtr;
		}
		void ContactNode::PrintContactNode(){
			cout<<"Name: "<<this->contactName<<endl;
			cout<<"Phone number: "<<this->contactPhoneNum<<endl<<endl;
		}		