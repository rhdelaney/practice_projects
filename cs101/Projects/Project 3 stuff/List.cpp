#include <iostream>
using namespace std;

#include "List.h"

List::List( ) {
	head=NULL;
	current=NULL;
	tail=NULL;
	n=0;
}
int List::size( ) {
	return n; } 
int List::currentValue( ) { 
	if(current==NULL){
		return 0;}
	int val=current->data;
	return val; }
int List::currentRank( ) { 
	if(current==NULL){
		return 0;}
	return current->rank; }
void List::gotoFirst( ) {
	if(n==0){
		return;
	}
	current=head;
	current->rank=0; 
	return; }
void List::gotoLast( ) {
	if(n==0){
		return;
	}
	else{
		current=tail;
		current->rank=n-1;
	}
	return; }
void List::retreat( ) { 
	int num;
	if(n==0 || current==NULL || current->prev==NULL){
		return;
	}
	else{
		num=current->rank;
		current=current->prev;
		current->rank=num-1;
}	
	return;
}
void List::advance( ) {
	int num; 
	if(n==0 || current==NULL || current->next==NULL){// || current==tail){
		return;
	}
	else{
		num=current->rank;
		current=current->next;
		current->rank=num+1;
	}

	return;
}
void List::gotoRank(int r) {
	Node *temp=head;
	if(n==0){
		return;
	} 
	else{
	
		for(int i=0;i<n;i++){
			if(i==r){
				current=temp;
				current->rank=r;
				return;
			}
		temp=temp->next;
		}
	}
} //should be in O(n) time
bool List::isNull( ) { 
	return ((current==NULL &&(current==tail || current==head)) || n==0);}
bool List::isFirst( ) { 
	if(current==NULL){
		return false;}
	else{
		return current==head;}
	}
bool List::isLast( ) { 
	if(current==NULL){
		return false;}
	else{
		return current==tail;
		}
}
void List::insertFirst(int x) { 
	Node *temp=new Node;
	temp->data=x;	
	temp->rank=0;		
	if(!(n==0)){
		temp->next=head;
		head->prev=temp;
		head=temp;
		n+=1;
		if(current!=NULL){
			current->rank+=1;
		}
	}
	else{	
		temp->next=head;
		tail=temp;
		head=temp;
		n+=1;
		if(current!=NULL){
			current->rank+=1;
		}
	}
}
void List::insertLast(int x) { 
	Node *temp=new Node;
	temp->data=x;
	if(!(n==0)){
		temp->prev=tail;
		tail->next=temp;
		tail=temp;
		n+=1;
	}
	else{
		temp->prev=tail;
		head=temp;
		tail=temp;
		n+=1;
	}
}
void List::insertBefore(int x) { 
	if(current==NULL){
		return;
	}
	else{
		Node *temp=new Node;
		temp->data=x;
		if(!(n==0)){
			if(current!=head){
				temp->prev=current->prev;
				temp->next=current;
				current->prev->next=temp;
				current->prev=temp;
				current->rank+=1;
				n+=1;}
			
			else{
				temp->next=current;
				//current->prev->next=temp;
				current->prev=temp;
				current->rank+=1;
				n+=1;
				head=temp;
			}
		}
		else{	
			head=temp;
			tail=temp;
						//cout<<head->data<<endl;
			current->rank+=1;
			n+=1;
		}
	}			
}
void List::insertAfter(int x) { 
	Node *temp=new Node;
	temp->data=x;
	if(current==NULL){
		return;
	}
	else{ 
		if(!(n==0)){
			if(current!=tail){
			current->next->prev=temp;
			temp->prev=current;
			temp->next=current->next;
			current->next=temp;
			n+=1;}
			else{
				temp->prev=current;
				//temp->next=current->next;
				current->next=temp;
				tail=temp;
				n+=1;
			}
		}
		else{
			head=temp;
			tail=temp;
			n+=1;
		}
	}
}
void List::replace(int x) {
	if(current==NULL){
		return;
	}
	else{
	current->data=x;}
 }
int List::removeFirst( ) { 
	Node *temp=new Node;
	int rm=0;
	if(n>=2){
		temp=head;
		rm=head->data;
		head=temp->next;
		head->prev=NULL;
		delete temp;
		n-=1;
		if(current!=NULL){
			current->rank-=1;
		}
		return rm;
	}
	else if(n==1){
		temp=head;
		rm=head->data;
		head=temp->next;
		tail=NULL;
		delete temp;
		n-=1;
		if (current!=NULL){
			current->rank-=1;;}
		return rm;
	}
	return rm; }
int List::removeLast( ) { 
	Node *temp=new Node;
	int rm=0;
	if (n==0){
		rm=0;
		return rm;
	}
	else if(n>=2){	
		temp=tail;
		rm=tail->data;
		tail=temp->prev;
		tail->next=NULL;
		delete temp;
		n-=1;
		return rm;
	}
	else if(n==1){
		temp=tail;
		rm=tail->data;
		tail=temp->prev;
		head=NULL;
		delete temp;
		n-=1;
		return rm;
	}
	
	return rm; }
int List::remove( ) { 	
	int rm=0;
	//int num=0;
	if(n==0 || current==NULL){
		return rm;
	}
	else{
		Node *temp=new Node;
		rm=current->data;
		//num=current->rank;
		temp=current;   //attaches to current
		//temp->prev->prev->next=current;
		current=temp->prev;
		temp->prev->prev->next=current;
		temp->next->prev=current;
		//current->next=
		current->prev=temp->prev->prev;
		//temp->next->prev=current;
		//current->prev=temp->prev->prev;
		//temp->prev->prev->next=current;
		current->next=temp->next;
		delete temp;
		n-=1;
		//current->rank=num;
		return rm;}
	return rm; }
int List::removeAndRetreat( ) { 
		int rm=0;
		//int num=0;
	if(n==0 || current==NULL){
		return rm;
	}
	else{
		Node *temp=new Node;
		rm=current->data;
		//num=current->rank;
		temp=current;
		current=temp->prev;
		current->next=temp->next;
		delete temp;
		//current->rank=num;
		n-=1;
		return rm;}
	return rm; }
int List::removeAndAdvance( ) { 
		int rm=0;
		//int num=0;
	if(n==0 || current==NULL){
		return rm;
	}
	else{
		Node *temp=new Node;
		rm=current->data;
		//num=current->rank;
		temp=current;
		current=temp->prev;
		current->next=temp->next;
		delete temp;
		current=current->next;
		//current->rank=num+1;
		n-=1;
		return rm;
		display();
	}
	return rm; 
}
void List::display( ) {
	cout<<"[ ";
	Node *start=head;	
		for(int i=0;i<n;i++){
			if(start==current){
				cout<<"("<< start->data <<")"<<" ";
			}
			else{
				cout<< start->data <<" ";
			}
			start=start->next;
		}
	cout<<"]"<<endl;
	return;
} //should be in O(n) time
