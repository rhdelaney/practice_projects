#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctype>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;

class Cell{
	public:
	int x_Value; //row
	int y_Value; //column
	int z_Value; //dimension if we need it but idk if we will :D
	//vector<Edge> connectedEdges;
	Cell (int x, int y, int z=0); //makes cell with specific x/y/z values -> matrices :D

};
class Map{
	public:
	vector <Cell>point;	//Map.x     //Map[a].point.x
	//vector<Edge>connections;
	int size;
	//int edges;
	int x;
	int y;
	int z;
	Map();//constructor for a "new Map"
	void addMap(int rows, int cols, int dimensions=0);//adds a cell with a specific dimension/value
	int findSpot (int i, int j);//finds the location in array :D
};
