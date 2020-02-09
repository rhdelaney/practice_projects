#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <queue>
#include <functional>
#include <unordered_map>
using namespace std;

struct Edge {
	int vertex1;
	int vertex2;
	int weight;
	Edge(int v1, int v2, int w):vertex1(v1), vertex2(v2), weight(w) {}
};

struct Graph {
	vector<int> vertice;
	vector<Edge> edges;
	vector< pair<int, Edge> > adjacent(int u) {
		vector< pair<int, Edge> > res;
		for (Edge e : edges) {
			if (e.vertex1 == u) {
				res.push_back( make_pair(e.vertex2, e));
			} else if (e.vertex2 == u) {
				res.push_back( make_pair(e.vertex1, e));
			}
		}
		return res;
	}
};



void prim(Graph& g, int root) {
	unordered_map<int, int> res;
	unordered_map<int, int> PARENT;
	unordered_map<int, int> KEY;

	for (auto c : g.vertice) {
		PARENT[c] = '\0';
		KEY[c] = INT_MAX;
	}
	KEY[root] = 0;
	vector<int> Q = g.vertice; 

	while (!Q.empty()) {    // O(V)
		int u = *min_element(Q.begin(), Q.end(), [&](int x, int y) {return KEY[x] < KEY[y];});  // O(v)
		vector<int>::iterator itr = remove(Q.begin(), Q.end(), u);  // O(V)
		Q.erase(itr, Q.end());  // erase() following remove() idiom
		if (PARENT[u] != '\0') {
			res[u] = PARENT[u];   // This is one edge of MST
		}
		vector< pair<int, Edge> > adj = g.adjacent(u);   // O(E)
		for (pair<int, Edge> v : adj) {
			if (find(Q.begin(), Q.end(), v.first) != Q.end()) {   // O(V)
				if (v.second.weight < KEY[v.first]) {
					PARENT[v.first] = u;
					KEY[v.first] = v.second.weight;
				}
			}
		}
	}

	for (auto e : res) {
		cout << e.first << " -- " << e.second << endl;
	}
}

int main(int argc, char *argv[]){
	ifstream fin;
	//int x=atoi(argv[2]);
	fin.open(argv[1]);
	
	int numVerts=0;
	int numEdge=0;
	fin>>numVerts>>numEdge;
	cout<<"After this?";
	//int t[numVerts];
	Graph g;
	//for(int i=0; i<numVerts;i++){
	//	t[i]=i;
	//}
	//g.vertice = vector<int>(t, t + sizeof(t)/sizeof(t[0]));

	int sNode, eNode=0;
	char color;

	while(fin>>sNode){
		fin>>eNode>>color;
		if(color=='C'){
			cout<<"in C";
			g.edges.push_back(Edge(sNode,eNode, 1));
		}
		else{
			cout<<"in W";
			g.edges.push_back(Edge(sNode,eNode, 5000));
		}
	}

	prim(g, 0);

	return 0;
}