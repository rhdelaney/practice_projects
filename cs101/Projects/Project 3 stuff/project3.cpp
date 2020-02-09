#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "List.h"

// This program should compile, but it should not run properly.
// Its only purpose is to detect compile-time errors such as spelling and type errors.

int main(int argc,char *argv[]) {
	ifstream fin;
	fin.open(argv[1]);
	char curr[100];	
	int i;
	bool b;
	List L;
	while(fin>>curr){
		if(strcmp(curr,"size")==0){i=L.size();
			cout<<i<<endl;}
		if(strcmp(curr,"currentValue")==0){i=L.currentValue();
			cout<<i<<endl;}
		if(strcmp(curr,"currentRank")==0){i=L.currentRank();
			cout<<i<<endl;}
		if(strcmp(curr,"gotoFirst")==0){L.gotoFirst();}
		if(strcmp(curr,"gotoLast")==0){L.gotoLast();}
		if(strcmp(curr,"retreat")==0){L.retreat();}
		if(strcmp(curr,"advance")==0){L.advance();}
		if(strcmp(curr,"gotoRank")==0){
			fin>>i;
			L.gotoRank(i);}
		if(strcmp(curr,"isNull")==0){
			b=L.isNull();
			cout<<boolalpha<<b<<endl;}
		if(strcmp(curr,"isFirst")==0){
			b=L.isFirst();
			cout<<boolalpha<<b<<endl;}
		if(strcmp(curr,"isLast")==0){
			b=L.isLast();
			cout<<boolalpha<<b<<endl;}
		if(strcmp(curr,"insertFirst")==0){
			fin>>i;
			L.insertFirst(i);}
		if(strcmp(curr,"insertLast")==0){
			fin>>i;
			L.insertLast(i);}
		if(strcmp(curr,"insertBefore")==0){
			fin>>i;
			L.insertBefore(i);}
		if(strcmp(curr,"insertAfter")==0){
			fin>>i;
			L.insertAfter(i);}
		if(strcmp(curr,"replace")==0){
			fin>>i;
			L.replace(i);}
		if(strcmp(curr,"removeFirst")==0){i=L.removeFirst();
			cout<<i<<endl;}
		if(strcmp(curr,"removeLast")==0){i=L.removeLast();
			cout<<i<<endl;}
		if(strcmp(curr,"remove")==0){i=L.remove();
			cout<<i<<endl;}
		if(strcmp(curr,"removeAndRetreat")==0){i=L.removeAndRetreat();
			cout<<i<<endl;}
		if(strcmp(curr,"removeAndAdvance")==0){i=L.removeAndAdvance();
			cout<<i<<endl;}
		if(strcmp(curr,"display")==0){
			L.display();
		}
	}

return 0;
}