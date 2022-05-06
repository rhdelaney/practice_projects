#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <queue>
#include <cmath>
using namespace std;

//#include "name.h"
/****************************************************
/ Raychel Delaney
/ CS101
/ Richard Dixon
/
/ This program takes in a name, command and features
/ then proceeds to handle the following operations with 
/ matricies
******************************************************/
int main(){
	char name;
	char dummy;
	char command[500];
	int numdims=0;
	int dimlist[3]={0};
	vector<int> valueList;
	int num;
	while(cin>>name){
		cout<<"In the while loop\n";
		cin>>command;
		if(strcmp(command,"build")==0){
			cout<<"in build\n";
			cin>>numdims>>dummy;
			int i=0;
			if(numdims==0){
				cin>>dummy>>num;
				valueList.push_back(num);
				cout<<name<<" = "<<valueList.at(0)<<endl;
			}else{
				while(i<numdims){
					cin>>num;
					dimlist[i]=num;
					i++;
				}
			cin>>dummy;
			if(numdims==1){
				for (int i = 0; i < dimlist[0]; ++i){
					cin>>valueList.at(i);
				}
				cout<<name<<" = [";
				for (int i = 0; i < dimlist[0]; ++i)
				{
					cout<<valueList.at(i);
					if(i+1<dimlist[0]){
						cout<<",";
					}
				}
			}else{
				for(int i=0;i<dimlist[0]*dimlist[1];i++){
					cin>>valueList.at(i);
					if( i+1 < dimlist[0] * dimlist[1]){
						cin>>dummy;
					}
				}
			cout<<name<<" = "<<"[";
			for(int i=0;i<dimlist[0];i++){
				cout<<"[";
				for(int j=0;j<dimlist[1];j++){
					cout<<valueList.at(i*dimlist[1]+j);
					if(i+1<dimlist[1]){
						cout<<",";
					}
				}
				cout<<"]";
			}
			cout<<"]\n";
			}
		}
			//numdims:dimlist:valuelist	
			//makes the matrice
	}
		if(strcmp(command,"apply")==0){
			cout<<"In apply\n";
			for(unsigned int i=0;i<point.at(x_stuff).connectedEdges.size();i++){
			//name1 name2 operation
			//performs operation using already existing arrays
			//ex) (x,y,z)*(q,r,s)=> (xq,ry,sz)
		}
		if(strcmp(command,"cross")==0){
			cout<<"in cross\n";
			//name1 name2 operation
			//applies it to each number aka element and then keeps both matricies together
			//so basically it goes (x,y,z) * (q,r,s)=>(xq,xr,xs),(yq,yr,ys),(zq,zr,zs)
		}
		if(strcmp(command,"join")==0){
			cout<<"in join\n";
			//name1 name2 operation (for N... ED *) let E =1 D=2
			//matrice -> | (a1*a2,a1*b2,a1*c2) (b1*d2,b1*e2,b1*f2) 	|
			//			 | (c1*a2,c1*b2,c1*c2) (d1*d2,d1*e2,d1*f2)	|
			//			 | (e1*a2,e1*b2,e1*c2) (f1*d2,f1*e2,f1*f2)	|		
			//vs L .. DE *
			//			
		}
		if(strcmp(command,"reduce")==0){
			cout<<"in reduce\n";
			//name1 operation dimension
		}
		if(strcmp(command,"catenate")==0){
			cout<<"in catenate";
			//name1 name2 dimension
			//appends name1 and name2 along the specific dimension and associates the result with the variable name
		}

	}
	//while(feof!)
	//char name=argv[1];
	//string com=argv[2];



	return 0;
}