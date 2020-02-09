// Contacts.cpp
#include <iostream>
using namespace std;

#include "Contacts.h"
//Tests that InsertAfter() correctly inserts Juan Alberto Jr.'s ContactNode after Roxanne Hughes's ContactNode and GetNext() correctly returns Juan Alberto Jr.'s ContactNode.

		ContactNode::ContactNode(string name,string number){
			contactName=name;
			contactPhoneNum=number;
			this->nextNodePtr=0;
			//if(tail==NULL){
			//	tail=this;}
		}
		void ContactNode::InsertAfter(string name, string number){
			//string name, string number, ContactNode *temp){
			ContactNode *temp=new ContactNode(name, number);
			tail->nextNodePtr=temp;
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