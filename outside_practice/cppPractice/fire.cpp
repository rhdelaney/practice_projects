#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
	cout<<"Enter 3 numbers that represent objects being burned in a fire: "<<endl;
	int time=0;
	int num1;
	int num2;
	int num3;
	cin>>num1>>num2>>num3;
if(num1>0){
	time+=num1;
}
if(num2>0){
	time+=num2;
}
if(num3>0){
	time+=num3;
}
cout<<time<<endl;
return 0;
}