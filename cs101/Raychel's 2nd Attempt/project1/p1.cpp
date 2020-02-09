#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <queue>
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
	ifstream fin;
	ofstream fout;
	
	string type=argv[1];
	fin.open(argv[2]);
	fout.open(argv[3]);
	
	if(type=="int"){
		int fileInput;
		int clInt;

		vector<int> fStuff;
		vector<int> clStuff;
		vector<int> trash;
		while(fin>>fileInput){
			fStuff.push_back(stoi(fileInput));
		}
		while(cin>>clInput){
			bool match=false;
			for (int i = 0; i <fStuff.size(); ++i)
			{
				if (clInput==fStuff.at(i))
				{
				trash.push_back(fStuff.at(i));
				fStuff.at(i).erase();
				match=true;
			}
			if (match==false)
			{
				clStuff.push_back(clInput);
			}
		}	
		}
		for(int i=0;i<clStuff.size();i++){
			for(int j=0;j<trash.size();j++){
				if(trash.at(j)==clStuff.at(i)){
					clStuff.at(i).erase();
				}
			}
		}	
		for(int i=0;i<fStuff.size();i++){
			for(int j=0;j<trash.size();j++){
				if(trash.at(j)==fStuff.at(i)){
					fStuff.at(i).erase();
				}
			}
		}
		
		sort(fStuff.begin(),fStuff.end(),less<int>());
fStuff.erase( unique( fStuff.begin(), fStuff.end() ), fStuff.end() );
		sort(clStuff.begin(),clStuff.end(),less<int>());
clStuff.erase( unique( clStuff.begin(), clStuff.end() ), clStuff.end() );
		
	priority_queue<int, vector<int>, greater<int> > q2;

	 for (int i = 0; i < fStuff.size(); ++i)
	 {
	 	q2.push(fStuff.at(i));
	 }
		for(int j=0;j<fStuff.size();j++){
			if(fStuff.at(j)!=""){
				fout<<fStuff.at(j)<<endl;
			}
		}
		for(int k=0;k<clStuff.size();k++){
			cout<<clStuff.at(k)<<endl;
		}
	}
	if(type=="str"){ 
		vector<string> fStuff;
		vector<string> clStuff;
		vector<string> trash;

		string clInput;
		string fileInput;
		while(fin>>fileInput){
			//cout<<fileInput<<endl;
			fStuff.push_back(fileInput);}
		while(cin>>clInput){
			//cout<<clInput<<endl;
			bool match=false;
			for(int i=0;i<fStuff.size();i++){
				if(fStuff.at(i)==clInput){
					//cout<<"It's a match yo!"<<endl;
					trash.push_back(fStuff.at(i));
					fStuff.at(i).erase();
					match=true;
				}
			}
			if(match==false){
				clStuff.push_back(clInput);
			}
		}
		for(int i=0;i<clStuff.size();i++){
			for(int j=0;j<trash.size();j++){
				if(trash.at(j)==clStuff.at(i)){
					clStuff.at(i).erase();
				}
			}
		}
		sort(fStuff.begin(),fStuff.end());
		fStuff.erase( unique( fStuff.begin(), fStuff.end() ), fStuff.end() );

		sort(clStuff.begin(),clStuff.end());
		clStuff.erase( unique( clStuff.begin(), clStuff.end() ), clStuff.end() );

		for(int j=0;j<fStuff.size();j++){
			if(fStuff.at(j)!=""){
				fout<<fStuff.at(j)<<endl;
			}
		}
		for(int k=0;k<clStuff.size();k++){
			if(clStuff.at(k)!=""){
			cout<<clStuff.at(k)<<endl;
			}
		}
	}
	return 0;
}