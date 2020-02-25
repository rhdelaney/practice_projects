#include "binomial.h"
#include "integer.h"
//#include "comparator.h" *note to self move it to int
#include "darray.h"
#include "queue.h"
#include "sll.h"

struct BinomialNode{
	void *value;
	DArray *children;
	struct BinomialNode *parent;
	void (*display)(FILE *,void *);
};

struct Binomial{
	DArray *rootlist;
	int (*compare)(void *,void *);
	void (*update)(void *,BinomialNode *);
	BinomialNode *extreme;
	int size;
	void (*display)(FILE *,void *);
};

Binomial *newBinomial(void (*display)(FILE *,void *), int (*compare)(void *,void *), void (*update)(void *,BinomialNode *)){
	Binomial *b=malloc(sizeof(Binomial));
	b->display=display;
	b->compare=compare;
	b->update=update;
	b->rootlist=newDArray(display);
	b->extreme=NULL;
	b->size=0;
	return b;
}
static BinomialNode *getSubHeap(DArray *a, int degree) {
     if(degree > sizeDArray(a)) {
          //fprintf(stderr, "Error in getSubHeap!\n");
          exit(-1);
     } else if(degree == sizeDArray(a)) {
          return NULL;
     } else {
          return getDArray(a, degree);
     }
}
static void extremeCheck(Binomial *b, BinomialNode *v){
	if(b->extreme==NULL){
		b->extreme=v;
	}
	else if(b->compare(v->value,b->extreme->value)<0){
		b->extreme=v;
	}
}
static void setExtreme(Binomial *b){
	b->extreme=NULL;
	for(int i=0;i<sizeDArray(b->rootlist);i++){
		BinomialNode *v=getSubHeap(b->rootlist,i);
		if(v!=NULL){
			extremeCheck(b,v);
		}
	}
}
void displayBinomialNode(FILE *fp,BinomialNode *n){
	n->display(fp,n->value);
	fprintf(fp,"-%d",sizeDArray(n->children));
	if(n->parent != n){
		fprintf(fp,"(");
		n->parent->display(fp,n->parent->value);
		fprintf(fp,"-%d)",sizeDArray(n->parent->children));
		//fprintf(fp, ")");
	}
}
static BinomialNode *combine(Binomial *b,BinomialNode *x,BinomialNode *y){
	//printf("in combine\n");
	if(b->compare(x->value,y->value)<0){
		//printf("I'm in the mainframe\n");
		int i=sizeDArray(y->children);
		setDArray(x->children,i,y);
		y->parent=x;
		//printf("leaving first if in combine\n");
		return x;
	}
	else{
		//printf("please send help\n");
		int i=sizeDArray(x->children);
		setDArray(y->children,i,x);
		x->parent=y;
		//printf("leaving else in combine\n");
		return y;
	}
}
//send it a node and change it to a value
//check if it's null
//IT'S CONSOLIDATING BITCH
static void consol(Binomial *b, BinomialNode *n){
	//printf("In consol\n");
	int degree=sizeDArray(n->children);
	//printf("degree = %d\n",degree);
	//printf("am I breaking?\n");
	while(getSubHeap(b->rootlist,degree)){
		//printf("before combine\n");
		n=combine(b,n,getSubHeap(b->rootlist,degree));
		//printf("after combine\n");
		setDArray(b->rootlist,degree,0);
		degree++;
		if(degree==sizeDArray(b->rootlist)){
			insertDArray(b->rootlist, NULL);
		}
	}
	setDArray(b->rootlist,degree,n);
}
static void merge(Binomial *b, DArray *donor){
	for(int i=0;i<sizeDArray(donor);i++){
		BinomialNode *g=(BinomialNode *) getDArray(donor,i);
		g->parent=g;
		consol(b,g);
	}
	free(donor);
}
BinomialNode *newBinomialNode(void (*display)(FILE *,void *),void *value){
	BinomialNode *bNode=malloc(sizeof(BinomialNode));
	bNode->value=value;
	bNode->children=newDArray(display);
	bNode->parent=bNode;
	bNode->display=display;
	return bNode;
}
BinomialNode *insertBinomial(Binomial *b,void *value){
	//printf("We are in insertBinomial\n");
	BinomialNode *n=newBinomialNode(b->display,value);
	//n->parent=n;
	//printf("before consol\n");
	/*if(b->extreme==NULL){
		b->extreme=;
	}*/
	extremeCheck(b,n);
	consol(b,n);
	//printf("after consol\n");
	b->size++;
	//printf("We are leaving insertBinomial\n");
	return n;
}
int sizeBinomial(Binomial *b){
	return b->size;
}
void deleteBinomial(Binomial *b,BinomialNode *n){
	decreaseKeyBinomial(b,n,NULL);
	(void) extractBinomial(b);
}
static void *bubbleUp(Binomial *b,BinomialNode *n){
	if(n==n->parent){
		return n;
	}
	else if(b->compare(n->value,n->parent->value)>0){
		return n;
	}
	else{
		b->update(n->value,n->parent);
		b->update(n->parent->value,n);
		void *temp=n->value;
		n->value=n->parent->value;
		n->parent->value=temp;
		return bubbleUp(b,n->parent);
	}
}
void decreaseKeyBinomial(Binomial *b,BinomialNode *n,void *value){
	n->value=value;
	BinomialNode *a=bubbleUp(b,n); //bubble up?
	/*if(a!=n){
		b->update(a,n);//update?
	}*/
	extremeCheck(b,a);
}
void *extractBinomial(Binomial *b){
	BinomialNode *x=b->extreme;
	setDArray(b->rootlist,sizeDArray(x->children),NULL);
	merge(b,x->children);
	b->size--;
	void *val=x->value;
	free(x);
	setExtreme(b);
	return val;
}
static void printLevelOrder(FILE *fp, BinomialNode *n){
	queue *q=newQueue(n->display);
	enqueue(q,n);
	enqueue(q,NULL);
	int level=0;
	fprintf(fp, "%d: ",level);
	//BinomialNode *temp=NULL;
	while(sizeQueue(q)!=0){
		BinomialNode *temp=dequeue(q);
		if(temp==NULL){
			fprintf(fp, "\n");
			if(sizeQueue(q)!=0){
				level++;
				enqueue(q,NULL);
				fprintf(fp, "%d: ",level);
			}
		}
		else{
			displayBinomialNode(fp, temp);
			if(peekQueue(q)!=NULL){
				fprintf(fp, " ");
			}
			int i=0;
			while(i<sizeDArray(temp->children)){
				enqueue(q,getSubHeap(temp->children,i));
				//enqueue(q,getDArray(temp->children,i));
				i++;
			}
		}
	}
}
void displayBinomial(FILE *fp,Binomial *b){
	for(int i=0;i<sizeDArray(b->rootlist);i++){
		if(getSubHeap(b->rootlist,i)){
			printLevelOrder(fp, getSubHeap(b->rootlist,i));
			//printf("Number of children = %d\n", );
			fprintf(fp,"----\n");
		}
	}
}