#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <istream>
#include <cstdlib>
#include <cstdio>
using namespace std;
//decode: 
//1. read k-ary int
//2. reads tree.txt
//3. reads result.txt
//4. makes source.txt

//VERY VERY WRONG

//function to read in/add a result character/ read a new one.
//function to read through values in the file till you find the one you wanted

//read in result for #>32 so read in each int and put it together
//determine if I or L
//if I number*10 if last digit=k-1-> number/10
int main(int argc, char* argv[]){
	ifstream fin1;
	ifstream fin2;
	ofstream fout;
	int k=atoi(argv[1]);
	fin1.open(argv[2]);
	fin2.open(argv[3]);
	fout.open(argv[4]);
	char letter;    //L/I in the front of the node
	char dummy;     //basically to hold the colon that nobody cares about
	int arr[200000000];			//array holding [huff]=count
	char asc[200000000];
	int num=0;
	int count=0;
	char digit[1];  
	int dig=0;
	while(fin1>>letter){
		fin1>>dummy>>asc; //takes in the letter and colon and number
		num=(int)asc;
		arr[count]=num;
		if(letter=='I'){
			count=(count*10)-1; // times ten and return right after
		}
		else if((count%10)==k-1){ //
			count/=10;
		}	
		count++;
	}
	int sub=0;
	while(fin2>>noskipws>>digit[0]){
		try{
		sub=digit[0];
		dig+=sub;   //seg fault here right here lololololol
		if(arr[dig]!=0 && arr[dig]<=126){
			fout<<(char)arr[dig];
			dig=0;
		}
		else{
			dig*=10;
		}
		}
		catch(...){fout<<endl;
	}
}
	return 0;
}
