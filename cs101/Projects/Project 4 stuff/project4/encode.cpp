#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <istream>
#include <cstdlib>
#include <cstdio>
using namespace std;

//encode: 
//1. reads code.txt
//2. reads source.txt
//3. if matches print result.txt
int main(int argc, char* argv[]){
	ifstream fin1;
	ifstream fin2;
	ofstream fout;
	fin1.open(argv[1]);
	fin2.open(argv[2]);
	fout.open(argv[3]);
	int asc=0;
	int huff=0;
	int arr[200];
	char let;
	int num;
	while(fin1>>asc){
		fin1>>huff;
		arr[asc]=huff;
	}
	while(fin2>>noskipws>>let){
			num=let-0;
		if(num<32){
			fout<<endl;
		}
		else{
			fout<<arr[num];}
	}
	return 0;
}
