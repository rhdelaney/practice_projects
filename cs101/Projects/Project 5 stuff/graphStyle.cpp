#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

class Edge {
    public:
        int startN, endN, middleN;
        Edge(int theStartNode, int theEndNode, int extra=0){
            startN = theStartNode;
            endN = theEndNode;
            middleN=extra;
        }
};
class Cell{
	public:
	int x_Value;
	int y_Value;
	int z_Value;
	vector<Edge> connectedEdges;
	Cell (int x, int y, int z=0) {
		x_Value = x; 
		y_Value = y; 
		z_Value = z;}

};
class Map{
	public:
	vector <Cell>point;	//Map.x     //Map[a].point.x
	//vector<Edge>connections;
	int size;
	int edges;
	int x;
	int y;
	int z;
	Map() { size = 0; edges = 0; x =0; y = 0; z = 0;}
	void addMap(int rows, int cols, int dimensions=0){
		x=rows;
		y=cols;
		z=dimensions;
		if(z==0){
			size=rows*cols;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					 Cell addCell(i, j);
                     point.push_back(addCell);
                     //cout<<point.at((i*y)+j).x_Value<<","<<point.at((i*y)+j).y_Value<<endl;
                }
			}
		}
		else{
			size=rows*cols*dimensions;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					for(int k=0;k<z;k++){
						Cell addCell(i, j, k);
                    	point.push_back(addCell);
            	     }
				}
			}
		}
	}
	int findSpot (int i, int j){ 	
		return i*y+j;
	}
	bool isThere(int x_stuff, int y_stuff){
		for(unsigned int i=0;i<point.at(x_stuff).connectedEdges.size();i++){
			if(point.at(x_stuff).connectedEdges.at(i).startN==x_stuff){
				if(point.at(x_stuff).connectedEdges.at(i).endN==y_stuff){
					return 1; 
				}
			}
		}
		return 0;
	}
	void math(int num1,int num2){
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					if((point.at(i).x_Value + num1)== point.at(j).x_Value && (point.at(i).y_Value + num2)==point.at(j).y_Value ){
						if(!(isThere(i,j))){
							Edge Edgy(i,j); //line
							point.at(i).connectedEdges.push_back(Edgy);
							} //this is a vector of lines within the cells[0,0]
					//cout<<connections.at(i).startN <<" "<<connections.at(i).endN<<endl;
					}
				}
			}
		}
	void math(int num1, int num2, int num3){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				if((point.at(i).x_Value + num1)== point.at(j).x_Value && (point.at(i).y_Value + num2)==point.at(j).y_Value && (point.at(i).z_Value+num3)==point.at(j).z_Value){
					if (!isThere(i,j)){
						Edge Edgy(i,j);
						point.at(i).connectedEdges.push_back(Edgy);
						cout<<point.at(i).connectedEdges.size()<<" ";
					}
				}
			}
		}
	}
};
/*inside Map:
for(int i = 0; i < 10; i++)
	{cout << point.at(i).x << endl;}
outside class; a.point.at(i).x;*/

/*
Spot a;
Spot a(1,3,5);
*/
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
	//fout<<dim<<endl;
	
	for(int i=0;i<dim;i++){
		fin>>arr[i];
		size*=arr[i];
	}
	//fout<<arr[0]<<" "<<arr[1]<<endl;
	Map dis;
	if(dim==2){
		dis.addMap(arr[0],arr[1]);}
	if(dim==3){
		dis.addMap(arr[0],arr[1],arr[2]);
	}
	fout<<size;
	
while(! fin.eof()){
		fin>>numbas[0];
		fin>>numbas[1];
		if(dim==2){
		sort (numbas,numbas+2);
  		do {
    		//fout << numbas[0] << ' ' << numbas[1] <<endl;
    			dis.math(numbas[0],numbas[1]);
    			dis.math(-1*numbas[0],-1*numbas[1]);
				dis.math(numbas[0],-1*numbas[1]);
    			dis.math(-1*numbas[0],numbas[1]);
    		} while (next_permutation(numbas,numbas+2) );
    	}
    	if(dim==3){
			fin>>numbas[2];
			do {
    		//fout << numbas[0] << ' ' << numbas[1] <<endl;
    			dis.math(numbas[0],numbas[1], numbas[2]);
    			dis.math(-1*numbas[0],-1*numbas[1], numbas[2]);
				dis.math(numbas[0],-1*numbas[1],-1*numbas[2]);
    			dis.math(-1*numbas[0],numbas[1],-1*numbas[2]);
				dis.math(-1*numbas[0],-1*numbas[1],numbas[2]);
				dis.math(-1*numbas[0],-1*numbas[1],-1*numbas[2]);
    		} while (next_permutation(numbas,numbas+3));
			dis.math(numbas[0],numbas[1],numbas[2]);
		}
	}
	int count=0;
	for(int i=0;i<size;i++){
		count+=dis.point.at(i).connectedEdges.size();}
	fout<<" "<<count/2<<endl;
	fout<<"1 "<<count<<endl;
	return 0;
}