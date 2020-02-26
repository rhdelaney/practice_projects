#include "vert.h"

/*
Arbitrary number of edge descriptons
2 vertices (sometimes a third for weight); ->
x y weight;
x y;
x,y,weight can’t be negative and weight can’t be 0
no weight-> auto “1” weight
*/
// Find dat minnnnn
Vert *getMinVert(DArray *a) {
     //printf("in get min vert\n");
     if (sizeDArray(a) == 0){
          return NULL;
     }
     Vert *min = (Vert *) getDArray(a, 0);
     for (int i = 0; i < sizeDArray(a); i++) {
          Vert *spot = getDArray(a,i);
          if (spot->val < min->val){
               min = spot;
               //printf("min=%d",min);
          }
     }
     //printf("leaving get min vert\n");
     return min;
}
int compareVert(void *x, void *y) {
     //printf("in compare vert\n");
     if (x == NULL && y == NULL) {
        return 0;
     }
     else if (x == NULL) {
        return -1;
     }
     else if (y == NULL) {
        return 1;
     }
     Vert *a = (Vert *) x;
     Vert *b = (Vert *) y;
     if (a->dist == b->dist) {
     //printf("wtf why is this NULL?!?!\n", );
          //i'm stupid I wasn't comparing values
          if (a->val < b->val) {
               return -1;
          }
          else {
               return 1;
          }
     }
     else if (a->dist < b->dist) {
          return -1;
     }
     else {
          return 1;
     }
}
edgeDef *readDef(FILE *fp) {
     //printf("weeee are readinnnng why did I think using my string cleaner last time would help lol\n");
     char x = readChar(fp);
     if (x == EOF) {
          return NULL;
     }
     ungetc(x,fp);
     edgeDef *ed = malloc(sizeof(edgeDef));
     ed->vStart = readInt(fp);
     ed->vEnd = readInt(fp);
     char *token = readToken(fp);
     if (!strcmp(token,";")) {
          ed->weight = 1;
     }
     else {
          ed->weight=atoi(token);
          free(token);
          token = readToken(fp);
     }
     //printf("vStart= %d, vEnd = %d, weight= %d\n",ed->vStart,ed->vEnd,ed->weight);
     free(token);
     return ed;
}
// Returns the vertices by darray vert
Vert *vertInList(DArray *list, int vert) {
     //printf("in vert in List\n");
     for (int i = 0; i < sizeDArray(list); i++) {
          Vert *v=getDArray(list, i);
          if (v->val == vert) {
               //printf("we found vert in list!\n");
               return v;
          }
     }
     //printf("not in list\n");
     return NULL;
}

// finds and returns neighhhhhhh *horse noises lelelele*
Neigh *neighInList(DArray *list, int vert) {
     //printf("in horse in list lol puns\n");
     for (int i = 0;i < sizeDArray(list); i++) {
          Neigh *n = getDArray(list,i);
          if (n->vert->val == vert) {
               //printf("we found a neigh in list!\n");
               return n;
          }
     }
     //printf("no horse buisness here lol\n");
     return NULL;
}
/*
OUTPUT TIPS:
report source to the destination vertices
aka:
0: source
1: destination(weight)source
*/
void displayVert(FILE *fp, void *val) {
     //printf("In display verrrrt\n");
     Vert *v = (Vert *) val;
     fprintf(fp,"%d",v->val);
     if (v->prev != NULL && v->prev != v) {
          fprintf(fp,"(%d)",v->prev->val);
          fprintf(fp,"%d",v->dist);
     }
     //print("we done in display vert fam\n");
     return;
}
//constructoooooor
Vert *newVert(int vert) {
     //printf("making a new vert\n");
     Vert *new = malloc(sizeof(Vert));
     new->val = vert;
     new->neighs = newDArray(displayInteger);
     new->dist = INT_MAX;
     new->steps = 0;
     new->bnode = NULL;
     new->prev = NULL;
     new->visited = 0;
     //printf("it's a madeeeee sonnn\n");
     return new;
}
//constructoooor
Neigh *newNeigh(int vert, int weight) {
     //printf("new neighhh who dis\n");
     Neigh *n = malloc(sizeof(Neigh));
     n->vert = newVert(vert);
     n->weight = weight;
     //printf("print my life away fam");
     return n;
}
void insertVert(DArray *list, int a, int b, int w) {
     //printf("inside insertVert\n");
     Vert *v = vertInList(list,a);
     if (v == NULL) {
          //printf("inside vertex==NULL\n");
          v = newVert(a);
          Neigh *n = newNeigh(b,w);
          insertDArray(v->neighs,n);
          insertDArray(list, v);
     }
     else {
         // printf("inside vert!=NULL\n");
          Neigh *n = neighInList(v->neighs,b);
          if (n == NULL) {
               //printf("inside neigh ==NULL\n");
               n = newNeigh(b,w);
               insertDArray(v->neighs,n);
          }
          else {
               if (w < n->weight) {
                   // printf("we updating that weight\n");
                    n->weight = w;
               }
          }
     }
}
// this is the shit I interpreted from the hinted text in my dijkstras from chat....
//I think this is close to right
void update(void *v, BinomialNode *n) {
     //printf("update dis bitch....plz?\n");
     Vert *x = (Vert *) v;
     x->bnode = n;
}
//finds the parent to the neigh
Vert *findNeighVert(DArray *adjList, Neigh *n) {
     //printf("we are in find NeighVert\n");
     Vert *v = vertInList(adjList, n->vert->val);
     return v;
}

//fill dat adj upppppppp ugghhh so close to finishing!
void fillList(DArray *list, FILE *fp) {
     //printf("fill up that list\n");
     edgeDef *ed = readDef(fp);
     while (ed != NULL) {
          //goes until end of file
          insertVert(list,ed->vStart,ed->vEnd,ed->weight);
          insertVert(list,ed->vEnd,ed->vStart,ed->weight);
          free(ed);
          ed = readDef(fp);
     }
     //printf("we are done filling errrrr up\n");
}
