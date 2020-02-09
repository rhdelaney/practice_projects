#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <queue>
#include <functional>
#include <iterator>
#include <cstdio>
#include <list>
#include <utility>
using namespace std;

class Edge {
    public:
    int startN, endN;
    char color;
    bool seen;
    Edge(int theStartNode, int theEndNode, char let){
        startN = theStartNode;
        endN = theEndNode;
        color=let;
        seen=false;
    }
};

class Cell{
	public:
	int theNode;
	vector<Edge> connectedEdges;
	bool visited;
	Cell (int num) {
		theNode= num;
		visited=false;
	}
};

class Map{
	public:
	vector <Cell> point;
	int edges;
	int verts;
	int stop;
	bool pathExists;
	Map() { edges=0; verts=0; stop=0;}
	Map(int numEdge, int numVerts, int stopIn){
		edges=numEdge;
		verts=numVerts;
		stop=stopIn;
		pathExists=false;
	}
	void addMap(int sNode, int eNode, char color){
		if(isThere(sNode) && isThere(eNode)){
			if(EisThere(sNode,eNode)){
				//if the nodes exist and the edge exists
				return;
			}
			//consider making one that checks edges color too(dude idk man it's rough)
			else{
				//the nodes exist but the edge doesn't
				findAdd(sNode,eNode,color);
				findAdd(eNode,sNode,color);
			}
		}
		else if (isThere(sNode) && !(isThere(eNode))){
			//if only start node exists
			addCells(eNode,sNode,color);
			findAdd(sNode,eNode,color);
		}
		else if (!(isThere(sNode)) && isThere(eNode)){
			//if only end node exists
            addCells(sNode,eNode,color);  
            findAdd(eNode,sNode,color); 
		}
		else{
			//if neither node exists
			addCells(sNode,eNode,color);
			addCells(eNode,sNode,color);
		}
	}
	void findAdd(int start, int end, char color){
		for(unsigned int i=0;i<point.size();i++){
			if(point.at(i).theNode==start){
				Edge Edgy(start,end,color);
				point.at(i).connectedEdges.push_back(Edgy);
				return;
			}
		}
	}
	void addCells(int start, int end, char color){
		Cell addCell(start);
        Edge Edgy(start,end,color);
		addCell.connectedEdges.push_back(Edgy);
        point.push_back(addCell);
	}
	bool isThere(int value){
		for(unsigned int i=0;i<point.size();i++){
			if(point.at(i).theNode==value){
					return 1; 
			}
		}
		return 0;
	}
	bool EisThere(int sNode, int eNode){
		int value=0;
		for(unsigned int i=0;i<point.size();i++){
			if(point.at(i).theNode==sNode){
				value=i;
			}
		}
		for(unsigned int i=0;i<point.at(value).connectedEdges.size();i++){
			if(point.at(value).connectedEdges.at(i).endN==eNode){
					return 1; 
			}
		}
		return 0;
	}
	void display(){
		for(unsigned int i=0;i<point.size();i++){
			for(unsigned int j=0;j<point.at(i).connectedEdges.size();j++){
				cout<<point.at(i).connectedEdges.at(j).startN<<" "<<point.at(i).connectedEdges.at(j).endN<<" "<<point.at(i).connectedEdges.at(j).color<<endl;
			}
		}
	}
	bool Compare(Edge c1, Edge c2){
    	return c1.color < c2.color;
	}
	void secondA(){
		//first take random Node
		//then grab it's edges
		//sort it by color
		//take the crimson first
		//then 
		vector<int> spotsV;
		priority_queue<Edge,function<bool(Edge, Edge)>> epq(Compare) ;
		for(unsigned int j=0;j<point.at(0).connectedEdges.size();j++){
			epq.push_back(point.at(0).connectedEdges.at(j));
		}
			cout<<"Edge color: "<<epq.top().color<<" to "<<epq.top().endN<<endl;
			spotsV.push_back(point.at(0));
			spotsV.push_back(epq.top().eNode);
			int spot=epq.eNode;
			epq.pop();
			thirdA(eNode,spotsV);
	}
	void thirdA(){
		priority_queue<Edge,function<bool(Edge, Edge)>> epq(Compare) ;
		for(unsigned int j=0;j<point.at(0).connectedEdges.size();j++){
			epq.push_back(point.at(0).connectedEdges.at(j));
			
		}
	}
	void pq(){
		//priority_queue<Cell> mypq;
		//mypq.push_back()
		//recursive
		//send i, j, k and count
		//return count/ print the path after checked and sees at least the given x input of C's 
		//basically send in a point.at(i) -> do this loop thingy below
		//after the if part becomes true/ count ++ -> recursively drop the end location aka point.at(k) as "i"
		//so path(int startNodeLoc, count++)
		//the final else -> if there are no places to go-> if count= given x -> exit program and print the path...
		//if not then RESET the visited/seen nodes/edges and then go to start at the next number and send it in
		int count, numPr=0;
		for(unsigned int i=0;i<point.size();i++){
			pathRecur(i,count);
			if(pathExists==true){
				display();
				cout<<numPr++<<endl<<endl;
			}
			else{
				resetSeen();
				count=0;
			}
		}
		/*int count=0;
		for(unsigned int i=0;i<point.size();i++){
			if(point.at(i).visited==false){
				for(unsigned int j=0;j<point.at(i).connectedEdges.size();j++){
					if(point.at(i).connectedEdges.at(j).color=='C' && point.at(i).connectedEdges.at(j).seen==false){
						for(unsigned int k=0;k<point.size();k++){
							if(point.at(i).connectedEdges.at(j).endN==point.at(k).theNode){
								point.at(k).visited=true;
								point.at(i).visited=true;
								point.at(i).connectedEdges.at(j).seen=true;
								count++;
							}
						}
					}
				}
			}
		}
		return count;}*/
	}
	void pathRecur(int startNodeLoc, int count){
		if(count<stop){
			for(unsigned int j=0;j<point.at(startNodeLoc).connectedEdges.size();j++){
				if(point.at(startNodeLoc).connectedEdges.at(j).color=='C' && point.at(startNodeLoc).connectedEdges.at(j).seen==false){
					for(unsigned int k=0;k<point.size();k++){
						if(point.at(startNodeLoc).connectedEdges.at(j).endN==point.at(k).theNode){
							point.at(k).visited=true;
							point.at(startNodeLoc).visited=true;
							point.at(startNodeLoc).connectedEdges.at(j).seen=true;
							pathRecur(k,count++);
						}
					}
				}
			}
			//pathRecur(count,-1);
		}
		else{
			pathExists=true;
		}
	}
	bool checkAllSeen(){
		for(unsigned int i=0;i<point.size();i++){
			if(point.at(i).visited==false){
				return false;
			}
		}
		return true;
	}
	void resetSeen(){
		for(unsigned int i=0;i<point.size();i++){
			if(point.at(i).visited==true){
				for(unsigned int j=0;j<point.at(i).connectedEdges.size();j++){
					if(point.at(i).connectedEdges.at(j).seen==true){
						point.at(i).connectedEdges.at(j).seen=false;
					}
				}
				point.at(i).visited=false;
			}
		}
	}
};

int main(int argc, char const *argv[]){
	ifstream fin;
	int x=atoi(argv[2]);
	fin.open(argv[1]);
	
	int numVerts=0;
	int numEdge=0;
	
	fin>>numVerts>>numEdge;
	Map A(numEdge,numVerts,x);
	int sNode, eNode=0;
	char color;

	while(fin>>sNode){
		fin>>eNode>>color;
		A.addMap(sNode,eNode,color);
	}
	//make_heap




	//A.display();
	//cout<<endl;
	//cout<<"Count = "<<A.pq()<<endl;
	A.pq();
	//steps: 
	//first pick crimson and find x amount of edges and then print out all the edges
	//each choose the smallest point then continue
	
	return 0;
}