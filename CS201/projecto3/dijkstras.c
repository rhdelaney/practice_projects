#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "string.h"
#include "real.h"
#include "integer.h"
#include "darray.h"
//#include "comparator.h" man this almost fucked me up
#include "binomial.h"
#include "vert.h"
#include "queue.h"
/*
Someone mentioned it in chat so basically using this as guidance to navigate this code jungle
void updateVertex(void *value,BinomialNode *b){
	Vertex *vertex=(Vertex *)value;
	vertex->position=bnode;
}
 Given by Jrob
Notes / psuedo code on self loops and ignoring them while adding edges for dijkstras:D
void addEdge(Graph* g, int u, int v, int w) {
    if(u == v) return;
    // else insert the edge

    // please don't forget this part, I know a 
    // professor who forgot this.
    Edge* e = getEdge(g, u, v);
    if(e != NULL) {
        if(w < e->weight) {
            e->weight = w;
        }
        return;
    }
    // add it

tbh I got a shit ton of help from a few different people for dijkstras because i don't get it too well
I also lucked out that someone had a good guide for binomial from last year when they did Prims algo
tbh prims would have beeen PRIMEEEEE to do


Notes for Fran on this project:
	-for the display :
-use the pseudo code I sent you but make sure that you use getSubHeap not getDArray
also the if statement for checking if the next is not Null only is printing a space the rest is done in the else :D
	-for extremes:
-you want a check aka (if extreme is Null or comp returns <0 set the extreme to the value )
-you want a set->it’s Null to start and go through the loop to find the comp<0 (hint hint use 2 functions an call to the previous one here) to fill the extreme’s role :D
-you want to check the extremes when you insert and decrease and you want to call the set in extract <3
	-for dijkstras/main
		-remember invocation is dijkstras and the file to read from
		-send the info to read from file to a function
		-print stdout after you are done
	-dike (aka your file read in and dijkstras functions and file)
		-first set up your structs ->
			-probably want a vert and edge at least
				-make “new____() “ functions for them aka newVertex ect.
-give it some values and shit you deem as “useful” for solving Dijkstras (start, end, weights are usually good but you need to read code and decided what you want)
		-second we make a adjList
			-read the info in
-clean that ish out and remember sometimes the weight is given(aka sometimes 3 and “;” other times 2 and “;”  when 2 assume weight is 1) 
-send the info to insert into the adjList (both : (start, end, weight) 
and (end, start, weight)
		-third you wanna work on where that booger of info goes…there is lots of 
adj matrix/list info out there you can use to model it after
-be sure to check if it’s already in the list....
-if it is grab it and update it’s info accordingly
-else add it
		
*/


/*
OUTPUT:
It’s a shortest path forest
In breadth first-traversal
->start with SMALLEST vertex on level 0
weights add by each jump
if they aren’t connected--→

First Tree
----
Second Tree
----

*/
static void displayForest(FILE *fp, queue *visited) {
	if(sizeQueue(visited)==0){
		//printf("you better not print hoe\n");
		return;
	}
	Binomial *b=newBinomial(displayVert,compareVert,update);
	int size=sizeQueue(visited);
	int maxS=0;
	//vert into a binomial
	for(int i=0;i<size;i++){
		Vert *v= (Vert *) dequeue(visited);
		if(v->steps > maxS){
			//printf("update them steppsss\n");
			maxS=v->steps;
		}
		insertBinomial(b,v);
	}
	//level into queue fuckkk should have used DArray
	queue *level[maxS+1];
	for(int i =0;i<=maxS;i++){
		level[i]=newQueue(displayVert);
	}
	// vertex from the heap into its queue in level.
	// binomial min -> sorts it to work in my favor
	for(int i=0;i<size;i++){
		Vert *v=(Vert *) extractBinomial(b);
		enqueue(level[v->steps],v);
	}
	// print out queue per lvl
	for(int i=0;i<=maxS;i++){
		fprintf(fp,"%d : ", i);
		//printf("we are right here \n");
		while(sizeQueue(level[i]) != 0){
			//printf("wtf familia\n");
			Vert *v=(Vert *) dequeue(level[i]);
            displayVert(stdout, v);
			if(sizeQueue(level[i]) > 0){
				//printf("we have a sibling\n");
				fprintf(fp," ");
			}
		}
		fprintf(fp,"\n");
	}
	fprintf(fp,"----\n");
}
static void dijkstra(FILE *fp, DArray *adjList, Binomial *heap){
	//printf("in dijkstra\n");
	queue *visited=newQueue(displayVert);
	Vert *min=getMinVert(adjList);
	//printf("got the min losers\n");
	min->dist=0;
	min->prev=min;
	min->steps=0;
	while(sizeBinomial(heap)!= 0){
		//printf("In dijk while loooop for heap\n");
		Vert *u=(Vert *) extractBinomial(heap);
		if(u->prev==NULL){
			//this is the end of a tree -> print it and break off to the next one (aka disjointed set)
			u->dist=0;
			displayForest(fp,visited);
			visited=newQueue(displayVert);
		}
		enqueue(visited,u);
		u->visited=1;
		for(int i=0; i<sizeDArray(u->neighs); i++){
			Neigh *n=(Neigh *) getDArray(u->neighs, i);
			Vert *v=findNeighVert(adjList, n);
			//printf("in the for loop\n");
			if(v->visited!= 1){
				//printf("not visited\n");
				int distance=u->dist + n->weight;
				if(distance<v->dist){
					//printf("dis<v->dis\n");
					v->prev=u;
					v->dist=distance;
					v->steps=v->prev->steps + 1;
					decreaseKeyBinomial(heap,v->bnode,v);
					//printf("are we breakkkking\n");
				}
			}
		}
	}
	//Show me dat treeeeeee
	displayForest(fp, visited);
}
int main(int argc, char const *argv[]){
	if(argc < 2) {
		//fprintf(stderr, "Not enough arguments.\n");
		exit(1);
	}
	//printf("before the file comes in\n");
	//printf("reading in from file\n");
	FILE *fp = fopen(argv[1], "r");
	DArray *adList = newDArray(displayVert);
	//printf("Filling up the list\n");
	fillList(adList, fp);
	//printf("we made the list\n");
	Binomial *heap=newBinomial(displayVert, compareVert, update);
	//printf("insert into binomial\n");
	for(int i=0;i<sizeDArray(adList);i++){
		Vert *v=getDArray(adList,i);
		v->bnode=insertBinomial(heap, v);
	}
	//displayBinomial(stdout, heap);
	// Run dijkstra's algorithm on the heap.
	//printf("Before dijkstra\n");
	dijkstra(stdout, adList, heap);
	fclose(fp);
	return 0;
}