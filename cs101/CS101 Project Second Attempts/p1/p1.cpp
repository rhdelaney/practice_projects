#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
/*	###############################################
	Raychel Delaney
	CS101-001
	Project 1
	due September 7, 2016

	Yo this is a sick program
	It's pretty cray

	It reads in those cool numbers/strings from a file like aye baby let me get your number/name
	Then it's like ohhh dang let me check out if my home boy command line has the same digits/name
	If they ain't matching we keep that gucci info and print it in the output file if it's the file's and to the stdout if it's std in's

	But dat info needs to be in ascending order (small to big big big)

	That's how my thug program works.
	###############################################*/

int main(int argc, char *argv[]){
	vector<string> fStuff;
	vector<string> clStuff;
	vector<string> trash;

	string clInput;
	string fileInput;

	ifstream fin;
	ofstream fout;
	
	string type=argv[1];
	fin.open(argv[2]);
	fout.open(argv[3]);
	
	if(type=="int"){
		int fileInput;
		int clInput;

		vector<int> fStuff;
		vector<int> clStuff;
		vector<int> trash;
		while(fin>>fileInput){
				fStuff.push_back(fileInput);
		}
		while(cin>>clInput){
			bool match=false;
			int sp=0;
			for (vector<int>::iterator i = fStuff.begin(); i != fStuff.end(); ++i, ++sp){	
				if(clInput==fStuff.at(sp)){
					trash.push_back(fStuff.at(sp));
					fStuff.erase(fStuff.begin() + sp);
					match=true;
				}
			}
			if (match==false){
				clStuff.push_back(clInput);
			}
		}	
		
		sort(fStuff.begin(),fStuff.end());
			fStuff.erase( unique( fStuff.begin(), fStuff.end() ), fStuff.end() );
		sort(clStuff.begin(),clStuff.end());
			clStuff.erase( unique( clStuff.begin(), clStuff.end() ), clStuff.end() );
		
		int ip=0;
		for (vector<int>::iterator i = clStuff.begin(); i != clStuff.end(); ++i,++ip){
			int jp=0;
			for (vector<int>::iterator j = trash.begin(); j != trash.end(); ++j,++jp){
					if(trash.at(jp)==clStuff.at(ip)){
						clStuff.erase(clStuff.begin()+ip);
					}
				}
			}
		ip=0;
		for (vector<int>::iterator i = fStuff.begin(); i != fStuff.end(); ++i, ++ip){
			int jp=0;
			for (vector<int>::iterator j = trash.begin(); j != trash.end(); ++j, ++jp){
				if(trash.at(jp)==fStuff.at(ip)){
					fStuff.erase(fStuff.begin()+ip);					
				}
			}
		}
		int jp=0;
		int kp=0;
		for (vector<int>::iterator j = fStuff.begin(); j != fStuff.end(); ++j, ++jp){
				fout<<fStuff.at(jp)<<endl;
			}
			for (vector<int>::iterator k = clStuff.begin(); k != clStuff.end(); ++k,++kp){
				cout<<clStuff.at(kp)<<endl;
			}
		}
	if(type=="str"){ 
		while(fin>>fileInput){
			fStuff.push_back(fileInput);}
		while(cin>>clInput){
			bool match=false;
			int ip=0;
			for (vector<string>::iterator i = fStuff.begin(); i != fStuff.end(); ++i, ++ip){
				if(fStuff.at(ip)==clInput){
					trash.push_back(fStuff.at(ip));
					fStuff.erase(fStuff.begin()+ip);
					match=true;
				}
			}
			if(match==false){
				clStuff.push_back(clInput);
			}
		}
		int ip=0;
		for (vector<string>::iterator i = clStuff.begin(); i != clStuff.end(); ++i, ++ip){
			int jp=0;
			for (vector<string>::iterator j = trash.begin(); j != trash.end(); ++j, ++jp){
				if(trash.at(jp)==clStuff.at(ip)){
					clStuff.erase(clStuff.begin()+ip);
				}
			}
		}
		sort(fStuff.begin(),fStuff.end());
		fStuff.erase( unique( fStuff.begin(), fStuff.end() ), fStuff.end() );

		sort(clStuff.begin(),clStuff.end());
		clStuff.erase( unique( clStuff.begin(), clStuff.end() ), clStuff.end() );
		int jp=0;
		for (vector<string>::iterator j = fStuff.begin(); j != fStuff.end(); ++j, ++jp){
			if(fStuff.at(jp)!=""){
				fout<<fStuff.at(jp)<<endl;
			}
		}
		int kp=0;
		for (vector<string>::iterator k = clStuff.begin(); k != clStuff.end(); ++k,++kp){
			if(clStuff.at(kp)!=""){
			cout<<clStuff.at(kp)<<endl;
			}
		}
	}
	return 0;
}