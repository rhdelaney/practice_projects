#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "vbst.h"

typedef struct vbstValue{
    void *value;
    int freq;
    void (*display)(FILE *,void *);
    int (*compare)(void *,void *);
} vbstValue;

static void vbstDisplay(FILE *fp, void *value){
	vbstValue *v = value;
	v->display(fp,v->value);
	if(v->freq >1){
		fprintf(fp, "-%d", v->freq);
	}
}//this may need more work tbh fam
static int vbstCompare(void *x, void *y){
	//not making sense
	vbstValue *a = x;
	vbstValue *b = y;
	return a->compare(a->value,b->value);
}
static vbstValue *newVBSTValue(void (*display)(FILE *,void *),int (*comparator)(void *,void *)){
	vbstValue *v=malloc(sizeof(vbstValue)); 
    v->value=NULL;
    v->freq=1;
    v->display=display;
    v->compare=comparator;
    return v;
}
vbst *newVBST(void (*display)(FILE *,void *),int (*comparator)(void *,void *)){
	vbst *vtree = malloc(sizeof(vbst));
	vtree->tree= newBST(vbstDisplay,vbstCompare); //specific display & compare to vbst...wtf
	vtree->display=display;
	vtree->compare=comparator;
	vtree->size=0;
	vtree->words=0;
	return vtree;
}
void insertVBST(vbst *vtree,void *value){
	vbstValue *val=newVBSTValue(vtree->display,vtree->compare);
	val->value=value;
	bstNode *n=findBSTNode(vtree->tree,val);
	if(n!=NULL){
		vbstValue *x = n->value;
        x->freq += 1;
		//(((vbstValue *)(n->value))->freq)++;
		vtree->words++;
	}
	else{
		n = insertBST(vtree->tree,val);
		vtree->size++;
		vtree->words++;
	}
}
int findVBST(vbst *vtree, void *val) {
    vbstValue *temp = newVBSTValue(vtree->display, vtree->compare);
    temp->value = val;
    bstNode *n = findBSTNode(vtree->tree, temp);
    if(n == NULL){
        free(temp);
        return 0;
    } 
    else{
        free(temp);
        temp = n->value;
        return temp->freq;
    }
}
/*int findVBST(vbst *vtree,void *value){
	vbstValue *val=newVBSTValue(vtree->display,vtree->compare);
	val->value=value;
	bstNode *n=findBSTNode(vtree->tree,val);
	if(n){
		//free(val);
		//val=n->value;
		return (((vbstValue *)(n->value))->freq);
	}
	else{
		//free(val);
		return 0;
	}
}*/
void deleteVBST(vbst *vtree,void *value){
	//printf("we are in here\n");
    vbstValue *val=newVBSTValue(vtree->display,vtree->compare);
	val->value=value;
	bstNode *temp=findBSTNode(vtree->tree, val);
	if(!temp){
		fprintf(stderr, "Value ");
        val->display(stderr, val->value);
        fprintf(stderr," not found.\n");
		return;
	}
	val=temp->value;
	if(val->freq>1){
        val->freq -=1;
        vtree->words -=1;
    }
    else{
		temp=swapToLeafBSTNode(temp);
		pruneBSTNode(vtree->tree,temp);
		vtree->size -=1;
		vtree->words -=1;
	}
}
int sizeVBST(vbst *vtree){
	return (vtree->size);
}
int wordsVBST(vbst *vtree){
	return (vtree->words);
}
void statisticsVBST(vbst *vtree,FILE *fp){
    fprintf(fp, "Words/Phrases: %d\n",wordsVBST(vtree));
	//fprintf(fp, "Nodes: %d\n",sizeVBST(vtree));
	statisticsBST(vtree->tree, fp);
}
void displayVBST(FILE *fp,vbst *vtree){
	displayBST(fp,vtree->tree);
}
// void checkvbst(vbst *);               //optional