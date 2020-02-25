#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "scanner.h"
#include "darray.h"
#include "integer.h"
#include "binomial.h"

#ifndef __VERT_INCLUDED__
#define __VERT_INCLUDED__

typedef struct edgeDef {
     int vStart;
     int vEnd;
     int weight;
} edgeDef;
typedef struct Vert {
     int val;
     DArray *neighs;
     int dist;
     int steps;
     BinomialNode *bnode;
     int visited;
     struct Vert *prev;
} Vert;
typedef struct Neigh {
     Vert *vert;
     int weight;
} Neigh;

extern int neighWeight(DArray *, int);
extern void update(void *, BinomialNode *);
extern Vert *findNeighVert(DArray *, Neigh *);
extern edgeDef *readDef(FILE *);
extern void displayVert(FILE *, void *);
extern Vert *newVert(int vert);
extern Neigh *newNeigh(int vert, int weight);
extern void fillList(DArray *list, FILE *fp);
extern void insertVert(DArray *list, int a, int b, int w);
extern Neigh *neighInList(DArray *list, int vert);
extern Vert *vertInList(DArray *list, int vert);
extern int compareVert(void *, void *);
extern Vert *getMinVert(DArray *);

#endif