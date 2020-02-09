#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

/*int graphArray(int rows, int cols){
	int graph[rows*cols];
	int k=0;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			graph[k]= (i*cols)+j;
			k++;
		}
	}
	return *graph;
} idk why this wants to shit on me rn*/

int math(int num1,int num2,int rows, int cols, int *graph){
	int temp1=0;
	int temp2=0;
	int val=0;
	int counter=0;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			temp1=i+num1;
			temp2=j+num2;
			val=temp1*cols+temp2;
		for(int k=0;k<(rows*cols);k++){
			if(graph[k]==(temp1*cols+temp2)){
					cout<<val<<endl;
					counter++;
					}
				}
			}
		}
	return counter;
}
//if you go for three->
//void math(int num1, int num2, int num3){return ;} 
int main(int argc, char* argv[]){
	ifstream fin;
	ofstream fout;
	fin.open(argv[1]);
	fout.open(argv[2]);
	int dim=0;
	int arr[12];
	int size=1;
	int numbas[12];
	fin>>dim;
	fout<<dim<<endl;
	
	for(int i=0;i<dim;i++){
		fin>>arr[i];
		size*=arr[i];
	}
	fout<<arr[0]<<" "<<arr[1]<<endl;

	fout<<"You need this number for the first line output: "<<size<<endl;
	
	int graph[size];
	if(dim==2){
	int k=0;
	for(int i=0;i<arr[0];i++){
		for(int j=0;j<arr[1];j++){
				graph[k]= (i*arr[1])+j;
				fout<<graph[k]<<" ";
				k++;
			}
		fout<<endl;
		}
	}

	int count=0;
	while(! fin.eof()){
		fin>>numbas[0];
		fin>>numbas[1];
		//when you edit for three->
		/*if(dim==3){
			fin>>numbas[2];
			math(numbas[0],numbas[1],numbas[2]);
		}*/
		sort (numbas,numbas+2);
  		do {
    	fout << numbas[0] << ' ' << numbas[1] <<endl;
    	count+=math(numbas[0],numbas[1],arr[0],arr[1],graph);
    	count+=math(-1*numbas[0],-1*numbas[1],arr[0],arr[1],graph);
		count+=math(numbas[0],-1*numbas[1],arr[0],arr[1],graph);
    	count+=math(-1*numbas[0],numbas[1],arr[0],arr[1],graph);
    	fout<<count<<" ";
  		} while (next_permutation(numbas,numbas+2) );
	}
	fout<<endl<<count<<endl;
	return 0;
}