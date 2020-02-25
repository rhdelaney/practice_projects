#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <queue>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[]){
	ifstream fin;
	ofstream fout;

	fin.open(argv[1]);
	fout.open(argv[2]);
	char acter;
	int ascii;
	vector<int> v(127);
	while(fin>>noskipws>>acter){
		ascii=(int)acter;
		v.at(ascii)+=1;
	}
	for (unsigned int i=0;i<v.size();i++){
		if(v.at(i)!=0 && i>31){
			fout<<i<<" : "<<v.at(i)<<endl;
		}
	}
	return 0;
}