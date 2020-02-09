#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//-std=c++0x compile with that

int main(){
	int n=10;
	while (n>0){
		cout<< n << ",";
		--n;
	}

	cout<<"liftoff!\n";

	string str;
	do {
		cout<< "Enter text: ";
		getline (cin,str);
		cout << "You entered: " <<str <<'\n';}
		while (str !="goodbye");
	for(int a=0; a<11; a++){
		cout<< a<<",";}
		cout<<"done!"<<"\n";
	int b, c;
	for(b=0, c=100; b!=c/2; b+=2, --c){
		cout<<c<<",";}
		cout<<"what did I do?"<<"\n";
	string star {"GROUPME"};
	for(char d : star){
		cout<<"[" << d << "]";}
		cout<< '\n';
	for(int e=10; e>0; e--){
		cout<<e<<",";
		if(e==3){
			cout<<"countdown aborted!"<<"\n";
			break;}
		}
	for(int f=20; f>0; f--){
		if (f==15 || f==10 || f==5) continue;
		cout<< f << ",";
		}
		cout<<"liftoff!\n";
		return 0;
}
