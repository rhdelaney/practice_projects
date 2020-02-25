#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "vert.h"
#include "queue.h"
#include "darray.h"
#include "binomial.h"

edge *readDef(FILE *fp){
	char x=readChar(fp);
	if(x==EOF){
		return NULL;
	}
	ungetc(x,fp);
	edge *e=malloc(sizeof(edge));
	e->vStart=readInt(fp);
	e->vEnd=readInt(fp);
	char *toke = readToken(fp);
	if(!strcmp(toke,";")){
		e->weight=1;
	}
	else{
		e->weight=atoi(toke);
		free(toke);
		toke=readToken(fp);
	}
	free(toke);
	return e;
}
Vertex *newVert(int vert){
	Vertex *v=malloc(sizeof(Vertex));
	v->val=vert;
	v->neigh=newDArray(displayInteger);
	v->dist=INT_MAX;
	v->steps=0;
	v->bnode=NULL;
	return v;
}
Neighbor *newNeigh(int vert, int w){
	Neighbor *n=malloc(sizeof(Neighbor));
	n->vert=newVert(vert);
	n->weight=w;
	//n->val=val;
	return n;
}
Vertex *vertInList(DArray *list, int v){
	for(int i=0;i<sizeDArray(list);i++){
		Vertex *vt=getDArray(list,i);
		if(vt->val==v){
			return vt;
		}
	}
	return NULL;
}
Neighbor *neighInList(DArray *list, int vert){
	for(int i=0;i<sizeDArray(list);i++){
		Neighbor *neigh=getDArray(list,i);
		if(neigh->vert->val==vert){
			return neigh;
		}
	}
	return NULL;
}
int insertVert(DArray *list, int start, int end, int w,int size){ //og void
	Vertex *vt = vertInList(list,start);
	if(vt==NULL){
		vt=newVert(start);
		Neighbor *neigh = newNeigh(end,w);
		insertDArray(vt->neigh,neigh);
		insertDArray(list,vt);
		size++;
		return size;
	}
	else{
		Neighbor *neigh=neighInList(vt->neigh,end);
		if(neigh==NULL){
			neigh=newNeigh(end,w);
			insertDArray(vt->neigh,neigh);
			return 0;
		}
		else{
			if(w<neigh->weight){
				neigh->weight=w;
			}
			return 0;
		}
	}
}
void displayVert(FILE *fp, edge *e){
	fprintf(fp, "%d(%d)%d",e->vStart,e->weight,e->vEnd);
}
/*void displayForest(DArray *nodes){ //add file pointer
	if(sizeDArray(nodes) == 0){
	//printf("0:\n");
	return;
	}
	int maxSteps = 0;
	for(int i=0; i<sizeDArray(nodes); i++){
		Vertex *getMax = (Vertex *) getDArray(nodes, i);
		if(getMax->steps > maxSteps){
			maxSteps = getMax->steps;
		}
	}
	queue *level[maxSteps];
	for(int j=0; j<=maxSteps; j++){
		level[j] = newQueue(displayVertex);
	}
	for(int k=0; k<sizeDArray(nodes); k++){
		Vertex *v = (Vertex *) getDArray(nodes, k);
		enqueue(level[v->steps], v);
	}
	for(int a=0; a<=maxSteps; a++){
		printf("%d : ", a);
		while(sizeQueue(level[a]) != 0){
			Vertex *print = (Vertex *) dequeue(level[a]);
			displayVert(stdout, print);
			if(sizeQueue(level[a]) > 0)
				fprintf(stdout, " "); 
		}
		fprintf(stdout, "\n");
	} 
	fprintf(stdout, "----\n");
}*/
int fillList(DArray *list, FILE *fp){ //og void
	edge *e=readDef(fp);
	int size=0;
	while(e!=NULL){
		size+=insertVert(list,e->vStart,e->vEnd,e->weight);
		size+=insertVert(list,e->vEnd,e->vStart,e->weight);
		free(e);
		//size++;
		e=readDef(fp);
	}
	return size;//displayForest(list);
}
void printList(FILE *fp, DArray *list){
     int a, b;
     for(a = 0; a < sizeDArray(list); a++) {
          Vertex *v = getDArray(list, a);
          fprintf(fp, "%d: ", a);
          for(b = 0; b < sizeDArray(v->neigh); b++) {
               Neighbor *n = getDArray(v->neigh, b);
               fprintf(fp, "%d(%d)%d", n->vert->val, n->weight,v->val);
               if((sizeDArray(v->neigh) - b) > 1) {
                    fprintf(fp, "->");
               }
          }
          fprintf(fp, "\n");
     }
}
int compareVert(void *x, void *y){
	if(!x && !y){
		return 0;
	}
	else if(!x){
		return -1;
	}
	else if(!y){
		return 1;
	}
	Vertex *v1= (Vertex *) x;
	Vertex *v2= (Vertex *) y;
	if(v1->val == v2->val){
		return 0;
	}
	else if(v1->val < v2->val){
		return -1;
	}
	else{
		return 1;
	}
}
Graph *newGraph(void (*display)(FILE *,void *), int (*compare)(void *,void *), void (*update)(void *,BinomialNode *)){
	Graph *g=malloc(sizeof(Graph));
	g->display=display;
	g->compare=compare;
	g->update=update;
	g->b=NULL;
	return g;
}
void dikjstras(DArray *list, Vert *v,int size){
	int visited[size];
	v->dist=0;
	int distances[size]=NULL;
	int parent[size]=NULL;
	for (i = 0; i < vertices; ++i) {
        distances[i] = INT_MAX;
        parent[i] = 0;
        visited[i] = 0;
    }
	for(int i=0;i<size;i++){
		int minVert=getMinVert(dist,visited,vert);
		Vertex *temp=v[]
		while()
	}
}




