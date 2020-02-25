// STL implementation of Prim's algorithm for MST
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
#include <cstdlib>
#include <utility>
using namespace std;
  
struct edge
{
    int u, v;
    int weight;
};
  
void Enqueue(struct edge heap[], int size, struct edge value)
{
    heap[size] = value;
      
    int i = size;
    struct edge temp;
      
    while (i >= 1) {
        if (heap[i / 2].weight > heap[i].weight) {
            //Parent node is greater than Child Node
            //Heap Property violated
            //So, swap
            temp = heap[i / 2];
            heap[i / 2] = heap[i];
            heap[i] = temp;
              
            i = i / 2;
        } else {
            //Parent is less or equal to the child
            //Heap property not violated
            //So, Insertion is done, break
            break;
        }
    }
}  
void Heapify(struct edge heap[], int size, int index)
{
    int i = index;
    struct edge temp;
      
    while ((2 * i) < size) {
        //Left Child exists
          
        if ((2 * i) + 1 >= size) {
            //Right child does not exist, but left does
            if (heap[i].weight > heap[2 * i].weight) {
                //Left child is smaller than parent
                temp = heap[i];
                heap[i] = heap[2 * i];
                heap[2 * i] = temp;
                break;
                //Once you reach this level where it does not
                //have a right child, the heap ends here
                //taking it to the next iteration is pointless
            }
        }
          
        //Both Children exist
        if (heap[i].weight > heap[2 * i].weight || heap[i].weight > heap[2 * i + 1].weight) {
            //One of the other child is lesser than parent
            //Now find the least amoung 2 children
              
            if (heap[2 * i].weight <= heap[(2 * i) + 1].weight) {
                //Left Child is lesser, so, swap
                temp = heap[2 * i];
                heap[2 * i] = heap[i];
                heap[i] = temp;
                //And go down the heap
                i = 2 * i;
            } else if (heap[2 * i].weight > heap[(2 * i) + 1].weight) {
                //Left Child is lesser, so, swap
                temp = heap[(2 * i) + 1];
                heap[(2 * i) + 1] = heap[i];
                heap[i] = temp;
                //And go down the heap
                i = (2 * i) + 1;
            }
        } else {
            //Parent is lesser than its children
            break;
        }
    }
}
  
void DeleteNode(struct edge heap[], int size, int index)
{
    //Swap the indexed element with the last
    struct edge temp = heap[index];
    heap[index] = heap[size - 1];
    heap[size - 1] = temp;
      
    int i = index;
    --size;
      
    Heapify(heap, size, i);
}
/*void DeleteMaxNode(struct edge heap[], int size, int index){
    //Swap the indexed element with the last
    struct edge temp = heap[index];
    heap[index] = heap[size - 1];
    heap[size - 1] = temp;
    int i = index;
    --size;
}*/
// Returns the element with
// Minimum Priority and deletes it
struct edge ExtractMin(struct edge heap[], int size){
    struct edge min = heap[0];
    DeleteNode(heap, size, 0);
    return min;
}
/*struct edge ExtractMax(struct edge heap[], int size){
    struct edge max = heap[size-1];
    DeleteMaxNode(heap, size, size-1);
    return max;
}*/
// Prim's Algorithm function
void Prim( vector< list< pair<int, int> > > & adjacencyList, int vertices, int edges, int startVertex, 
            vector< list< pair<int, int> > > & MST)
{
    int current = startVertex, newVertex;
    bool visited[vertices + 1];
    struct edge var;
    struct edge PriorityQueue[2 * edges];
    int QueueSize = 0;
    int i;
    for (i = 0; i < vertices; ++i) {        // Initializing
        visited[i] = false;
    }
    i = 0;
    while (i < vertices) {
        if (!visited[current]) {            // If current node is not visited
            visited[current] = true;        // Mark it visited  
            list< pair<int, int> >::iterator itr = adjacencyList[current].begin();
            while (itr != adjacencyList[current].end()) {                
                if (!visited[(*itr).first]) {
                    // If the edge leads to an un-visited
                    // vertex only then enqueue it
                    var.u = current;
                    var.v = (*itr).first;
                    var.weight = (*itr).second;
                    Enqueue(PriorityQueue, QueueSize, var);
                    ++QueueSize;
                }
                ++itr;
            }
   
            var = ExtractMin(PriorityQueue, QueueSize);     // The greedy choice
            --QueueSize;
            newVertex = var.v;
            current = var.u;
            if (!visited[newVertex]) {
                MST[current].push_back(make_pair(newVertex, var.weight));
                MST[newVertex].push_back(make_pair(current, var.weight));
            }
            current = newVertex;
            ++i;
        } else {
            var = ExtractMin(PriorityQueue, QueueSize);
            --QueueSize;
            newVertex = var.v;
            current = var.u;
            if (!visited[newVertex]) {
                MST[current].push_back(make_pair(newVertex, var.weight));
                MST[newVertex].push_back(make_pair(current, var.weight));
            }
            current = newVertex;
        }
    }
}
int main(int argc, char *argv[]){
    int vertices, edges, v1, v2;
    char weight;
    ifstream fin;
	int x=atoi(argv[2]);
	fin.open(argv[1]);
	fin>>vertices>>edges;  

    vector< list< pair<int, int> > > adjacencyList(vertices);
    vector< list< pair<int, int> > > MST(vertices);
    vector< list< pair<int, int> > > adjL(vertices);
    vector< list< pair<int, int> > > TSM(vertices);

    for (unsigned int i = 0; i < edges; ++i) {
        fin>>v1>>v2>>weight;
          if(weight=='C'){
        	adjacencyList[v1].push_back(make_pair(v2, 1));
      	  	adjacencyList[v2].push_back(make_pair(v1, 1));
    	    adjL[v1].push_back(make_pair(v2, 50));
            adjL[v2].push_back(make_pair(v1, 50));
        } else{
    	   adjacencyList[v1].push_back(make_pair(v2, 50));
           adjacencyList[v2].push_back(make_pair(v1, 50));
    	   adjL[v1].push_back(make_pair(v2, 1));
           adjL[v2].push_back(make_pair(v1, 1));
        }
    }  
    vector<int> icu;
    Prim(adjacencyList, vertices, edges, 0 , MST);
    Prim(adjL, vertices, edges, 0, TSM);

    int max, count=0;
    bool hitMaxC=false;
    ostringstream os;
    for (unsigned int i = 0; i < MST.size(); ++i) {
        list< pair<int, int> >::iterator itr = MST[i].begin();
        while (itr != MST[i].end()) {  
            bool haventVisted=true;
                if(i > (*itr).first){
                    haventVisted=false;
                }
                if(haventVisted && !hitMaxC){
                    os<<i<<" "<<(*itr).first<<endl;
                    icu.push_back((*itr).first);
                    icu.push_back(i);
                    if((*itr).second==1){
                        count++;
                        if(count==x){
                            hitMaxC=true;
                        }
                    }
                }
            ++itr;
        }
        max=count;
    }
    for (unsigned int i = 0; i < TSM.size(); ++i) {
        list< pair<int, int> >::iterator itr = TSM[i].begin();
        while (itr != TSM[i].end()) {  
            bool haventVistedstart=true;
            bool haventVistedend=true;
            for(unsigned int j=0;j<icu.size();j++){
                if(icu.at(j) == i){
                    haventVistedstart=false;
                }
                if(icu.at(j)==(*itr).first){
                    haventVistedend=false;
                }
            }
            if(haventVistedstart || haventVistedend){
                os<<i<<" "<<(*itr).first<<endl;
                icu.push_back((*itr).first);
                icu.push_back(i);
                if((*itr).second==1){
                    count++;
                }
            }
            ++itr;
        }
    }
    if(x <= max && count==vertices-1){
    	cout<<os.str();
	} else{
		cout<<"No spanning tree with "<<x<<" Crimson edges exists"<<endl;
	}
    return 0;
}