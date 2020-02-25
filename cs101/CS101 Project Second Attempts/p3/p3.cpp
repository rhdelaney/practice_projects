#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/****************************************************
/ Raychel Delaney
/ CS101
/ Richard Dixon
/
/ This program takes stock stats (buy/sell #shares at $price )
/ then proceeds to make nodes and calculations using stack, queue
/and the wtAvg
******************************************************/
	//current list to fix:

// * Floats aka the price take in for accuracy print out
// * Printing to File instead of counsol-> (return back to main to print?)
// * WtAvg-> setting values :()

struct Node{
	float nShares=0.00;
	float ogPrice=0.00; //needs to be float variant tommorrow
	Node *next; //points at the next node
	Node *prev; //points at the previous node
};
class FIFO{
public:
	Node *head;
	Node *tail;
	int n; //size
	float total;
	FIFO(){
		head=NULL;
		tail=NULL;
		n=0;
		total=0.00;
	}
	void setValue(float x, float y){
		//used list insertLast
		Node *temp=new Node;
		temp->nShares=x;
		temp->ogPrice=y;
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
	float sellStocks(float x, float y){
		Node *temp=new Node;
		float rm=0.00;
		float rm2=0.00;
		float totalShares=0.00;
		float totalB=0.00;
		while(totalShares!=x){
			if(n>=2){
				temp=head;
				rm=head->nShares;
				rm2=head->ogPrice;
				if( totalShares + rm > x){
					head->nShares = ((totalShares+rm) - x);
					totalB += ((x-totalShares) * rm2);
					return mathTime(totalB, x, y);
				} else if(totalShares+rm == x){
					totalShares+=rm;
					totalB+= (rm*rm2);
					head=temp->next;
					head->prev=NULL;
					delete temp;
					n-=1;
					return mathTime(totalB, x, y);
				}else{
					totalShares+=rm;
					totalB+= (rm*rm2);
					head=temp->next;
					head->prev=NULL;
					delete temp;
					n-=1;
				}
			} else{
				temp=head;
				rm=head->nShares;
				rm2=head->ogPrice;
				if( totalShares + rm > x){
					head->nShares= ((totalShares+rm)-x);
					totalB += ((x-totalShares) * rm2);
					return mathTime(totalB, x, y);
				} else if(totalShares+rm == x){
					totalShares+= rm;
					totalB+= (rm*rm2);
					head=temp->next;
					tail=NULL;
					delete temp;
					n-=1;
					return mathTime(totalB, x, y);
				}else{
					totalShares+= rm;
					totalB+= (rm*rm2);
					head=temp->next;
					tail=NULL;
					delete temp;
					n-=1;
				}
			}
		}
		return 0;
	}
	float mathTime(float tBasis, float x, float y){
		//cout<<"Gain = "<< x*y - tBasis <<endl;
		total+= ((x*y) - tBasis) ;
		return ((x*y) - (tBasis));
	}
};
class LIFO{
public:
	Node *head;
	Node *tail;
	int n;
	float total;
	LIFO(){
		head=NULL;
		tail=NULL;
		n=0;
		total=0.00;
	}
	void setValue(float x, float y){
		Node *temp=new Node;
		temp->nShares = x;
		temp->ogPrice = y;
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
	float sellStocks(float x, float y){
		Node *temp=new Node;
		float rm=0.00;
		float rm2=0.00;
		float totalShares=0.00;
		float totalB=0.00;
		while(totalShares!=x){
			if(n>=2){	
				temp=tail;
				rm = tail -> nShares;
				rm2 = tail -> ogPrice;
				if( totalShares + rm > x){
					tail->nShares = ((totalShares + rm) - x);
					totalB += ((x - totalShares) * rm2);
					return mathTime(totalB, x, y);
				}else if(totalShares+rm == x){
					totalShares+=rm;
					totalB+= (rm * rm2);
					tail=temp->prev;
					tail->next=NULL;
					delete temp;
					n-=1;
					return mathTime(totalB, x, y);
				}else{
					totalShares+= rm;
					totalB+= (rm*rm2);
					tail=temp->prev;
					tail->next=NULL;
					delete temp;
					n-=1;
				}
			} else{
				temp=tail;
				rm=tail->nShares;
				rm2=tail->ogPrice;
				if( totalShares + rm > x){
					tail->nShares= ((totalShares+rm)-x);
					totalB += ((x - totalShares) * rm2);
					return mathTime(totalB, x, y);
				} else if(totalShares+rm == x){
					totalShares+=rm;
					totalB+= (rm * rm2);
					tail=temp->prev;
					head=NULL;
					delete temp;
					n-=1;
					return mathTime(totalB, x, y);
				}else{
					totalShares+= rm;
					totalB+= (rm * rm2);
					tail=temp->prev;
					head=NULL;
					delete temp;
					n-=1;
				}
			}
		}
		return 0;
	}
	float mathTime(float tBasis, float x, float y){
		total+= ((x*y) - tBasis) ;
		return ((x*y) - tBasis);
	}
};
class WtA{
public:
	float SharesOwned;
	float totalOGVal;
	float average;
	float total;
	WtA(){
		SharesOwned=0.00;
		totalOGVal=0.00;
		average=0.00;
		total=0.00;
	}
	void setValue(float x, float y){ //x is ya shares // y is ya price
		SharesOwned+= x;
		totalOGVal+= (x * y);
		average= totalOGVal/SharesOwned;
	}
	float sellStocks(float x, float y){
		SharesOwned-= x;
		totalOGVal-= (x * average);
		return mathTime(x,y);
	}
	float mathTime(float x, float y){
		total+= ((x*y) - (x * average));
		return ((x * y) - (x * average));
	}
};

int main(){
	string command;
	float numShares;
	float price; //this should be a float figure it out later

	ifstream fin;
	ofstream fifo;
	ofstream lifo;
	ofstream wAvg;
	
	fin.open("Transactions.txt");
	fifo.open("FIFO.txt");
	lifo.open("LIFO.txt");
	wAvg.open("WtAvg.txt");

	FIFO first;
	LIFO last;
	WtA average;
	while(fin>>command){
		fin>>numShares>>price;
		if (command=="Buy"){
			first.setValue(numShares,price);
			last.setValue(numShares,price);
			average.setValue(numShares,price);
			//needs to make node and connects them in 3 different set ups
		}else if(command=="Sell"){
			fifo<<"Gain = "<<first.sellStocks(numShares,price)<<endl;
			lifo<<"Gain = "<<last.sellStocks(numShares,price)<<endl;
			wAvg<<"Gain = "<<average.sellStocks(numShares,price)<<endl;
			//needs to calculate cost basis & then take sale price vs bought price and print gain
		}
		else{
			cout<<"Ya done goofed"<<endl;
		}
	}
	fifo<<"Total = "<<first.total<<endl;
	lifo<<"Total = "<<last.total<<endl;
	wAvg<<"Total = "<<average.total<<endl;

	return 0;
}