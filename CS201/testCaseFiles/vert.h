#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "scanner.h"
#include "darray.h"
#include "integer.h"
#include "binomial.h"

#ifndef __VERT__H
#define __VERT__H

typedef struct edge {
     int vStart;
     int vEnd;
     int weight;
} edge;

typedef struct Vertex {
     int val;
     DArray *neigh;
     int dist;
     int steps;
     BinomialNode *bnode;
} Vertex;

typedef struct Neighbor {
     Vertex *vert;
     int weight;
     //int val;
} Neighbor;

typedef struct Graph{    
     int size;
     Binomial *b;
     int (*compare)(void *,void *);
     void (*update)(void *,BinomialNode *);
     void (*display)(FILE *,void *);
} Graph;

extern edge *readDef(FILE *);
extern Vertex *newVert(int vert);
extern Neighbor *newNeigh(int vert, int w);
extern void fillList(DArray *list, FILE *fp);
extern void insertVert(DArray *list, int a, int b, int w);
extern Neighbor * neighInList(DArray *list, int vert);
extern Vertex *vertInList(DArray *list, int vert);
extern void printList(FILE *fp, DArray *list);
extern int compareVert(void *, void *);
extern void displayVert(FILE *, edge *);
//extern void displayForest(DArray *list);
//extern Graph *newGraph(void (*display)(FILE *,void *), int (*compare)(void *,void *), void (*update)(void *,BinomialNode *));
//extern void dikjstras(Graph *g, Vert *v);

#endif