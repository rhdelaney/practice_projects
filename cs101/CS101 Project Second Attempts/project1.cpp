#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

void first(int a, int b, string name, ofstream &fout);
void middle(int a, int b, string name, ofstream &fout);
void last(int a, int b, string name, ofstream &fout,int i, int j, int k);
void lastName(int a, int b, string name, ofstream &fout,int i, int j, int k);
void lastPeriod(int a, int b, string name, ofstream &fout,int i, int j, int k);

int main(int argc, char *argv[]){
	ifstream fin;
	ofstream fout;
	
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	fin.open(argv[3]);
	fout.open(argv[4]);

	string name1="Raychel";
	string name2="Hana";
	string name3="Delaney";	

	int i=0;
	int j=1;
	int k=1;
	first(a,b,name1,fout);
	middle(a,b,name2,fout);
	last(a,b,name3,fout,i,j,k);		
	
	while(fin>>name1){
		fin>>name2>>name3;
			first(a,b,name1,fout);
			middle(a,b,name2,fout);
			last(a,b,name3,fout,i,j,k);}
	
	name1="Raychel";
	name2="Hana";
	name3="Delaney";	

	first(a,b,name1,fout);
	middle(a,b,name2,fout);
	last(a,b,name3,fout,i,j,k);		
	
	fin.close();
	fout.close();
	return 0;
}
void first(int a, int b, string name, ofstream &fout){
	fout<<endl;
	for(int i=0;i<a;i++){						//this for loop is fresh out the the oven
		for(int j=0;j<b;j++){					//wew lad that's a fancy loop
			for(int k=0;k<=j;k++){				//look at it go "fout"ing Names like a pro
				fout<<".";}
			fout<<name;}
	for(int z=0;z<=b;z++){
		fout<<".";}
		fout<<"\n";}
		fout<<"\n";
	}
void middle(int a, int b, string name, ofstream &fout){
	int i=0;
	int j=0;
	int k=0;
	while(i<a){
		j=0;
		while(j<b){
			k=0;
			while(k<j+1){
				fout<<".";
				k++;
			}
			fout<<name;
			j++;
		}
		k=0;
		while(k<=b){
			fout<<".";
			k++;
		}
		fout<<endl;
		i++;
	}
	fout<<endl;
}

void last(int a, int b, string name, ofstream &fout,int i, int j, int k){
	if(i<j){
		lastPeriod(a,b,name,fout,i,j,k);
	}
	else if(i==j){
		lastName(a,b,name,fout,i,j,k);
		}
	}
void lastName(int a, int b, string name, ofstream &fout,int i, int j, int k){
	if(j<=b){
		fout<<name;}
	if(j==b+1){
		fout<<endl;
		if(k==a){
			fout<<endl;
			return;
			}
		last(a,b,name,fout,i=0,j=1,k+1);	
		}
	else{
		last(a,b,name,fout,i=0,j+1,k);
		}
}
void lastPeriod(int a, int b, string name, ofstream &fout,int i, int j, int k){
	if(i<j){
		fout<<".";
		lastPeriod(a,b,name,fout,i+1,j,k);
	}
	else{
		last(a,b,name,fout,i,j,k);
	}
}





