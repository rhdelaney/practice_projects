#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <queue>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]){
	int n=atoi(argv[1]);
	int m=atoi(argv[2]);
	deque<int> A;
	deque<int> B;
	int num=0;
	for(int i=1;i<=n;i++){
		A.push_back(i);
	}
	cout<<"Queue A: ";
	for(int i=0;i<A.size();i++){
		cout<<A.at(i)<<" ";
	}
	cout<<endl;

	while(!A.empty() || !B.empty()){
		while(!A.empty()){
			for(int i=0;i<A.size();i++){
				if( i != m-1 ){
					if( i == (m-1) - A.size() ){
						num=A.front();
						cout<<"Moving value "<<num<<" to queue B"<<endl;
						A.pop_front();
						B.push_back(num);
						cout<<"Queue A: ";
						for(int i=0;i<A.size();i++){
							cout<<A.at(i)<<" ";
						}
						cout<<endl;
						break;
					} else{
						num=A.front();
						A.pop_front();
						A.push_back(num);
					}
				}
				 else{
					num=A.front();
					cout<<"Moving value "<<num<<" to queue B"<<endl;
					A.pop_front();
					B.push_back(num);
					cout<<"Queue A: ";
					for(int i=0;i<A.size();i++){
							cout<<A.at(i)<<" ";
					}
					cout<<endl;
					break;
				}
			}
			if(A.size()==1){
				if(B.empty()){
					cout<<"Queue A: "<<A.front()<<endl;
					cout<<"Winner is "<<A.front()<<endl;
					A.pop_front();
					break;
				}
				else{
					cout<<"Eliminate: "<<A.front()<<endl<<endl;
					A.pop_front();
					break;
				}
			}
		}
		while(!B.empty()){
			for(int i=0;i<B.size();i++){
				if( i != m-1 ){
					if( i == (m-1) - B.size() ){
						num=B.front();
						cout<<"Moving value "<<num<<" to queue A"<<endl;
						B.pop_front();
						A.push_back(num);
						cout<<"Queue B: ";
						for(int i=0;i<B.size();i++){
							cout<<B.at(i)<<" ";
						}
						cout<<endl;
						break;
					} else{
						num=B.front();
						B.pop_front();
						B.push_back(num);
					}
				}
				 else{
					num=B.front();
					cout<<"Moving value "<<num<<" to queue A"<<endl;
					B.pop_front();
					A.push_back(num);
					cout<<"Queue B: ";
					for(int i=0;i<B.size();i++){
							cout<<B.at(i)<<" ";
					}
					cout<<endl;
					break;
				}
			}
			if(B.size()==1){
				if(A.empty()){
					cout<<"Queue B: "<<B.front()<<endl;
					cout<<"Winner is "<<B.front()<<endl;
					B.pop_front();
					break;
				}else{
					cout<<"Eliminate: "<<B.front()<<endl<<endl;
					B.pop_front();
					break;
				}
			}
		}
	}
	return 0;
}