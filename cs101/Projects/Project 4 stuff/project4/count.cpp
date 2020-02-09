#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <istream>
using namespace std;

int main(int argc, char* argv[]){
	ifstream fin;
	ofstream fout;
	fin.open(argv[1]);
	fout.open(argv[2]);
	int app[127]={};
	char num;
	int ascii;
	while(fin>>noskipws>>num){
		ascii=static_cast<int>(num);
		app[ascii]+=1;
	}
	for(int i=32;i<127;i++){
		if(app[i]>0){
			fout<<i<<" "<<dec<<app[i]<<endl;}
		}
	return 0;
}
