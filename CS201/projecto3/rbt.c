#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"

typedef struct rbtValue{
	void *value;
	int freq; //1
	char color; //RED
	void (*display)(FILE *x, void *);
	int (*comp)(void *, void *);
} rbtValue;

static void rbtDisplay(FILE *fp, void *value){
	rbtValue *v = value;
	v->display(fp,v->value);
	if(v->freq>1){
		fprintf(fp, "-%d", v->freq);
	}	
	fprintf(fp, "-%c", v->color);
}
static int rbtCompare(void *x, void *y){
	//not making sense
	rbtValue *a = x;
	rbtValue *b = y;
	return a->comp(a->value,b->value);
}
static rbtValue *newRBTValue(void (*display)(FILE *,void *),int (*comparator)(void *,void *)){
	rbtValue *nodeVal=malloc(sizeof(rbtValue));
	nodeVal->value=NULL; 
    nodeVal->freq=1;
    nodeVal->color='B';
    nodeVal->display=display;
    nodeVal->comp=comparator;
    return nodeVal;
}
rbt *newRBT(void (*display)(FILE *,void *),int (*comparator)(void *,void *)){
	rbt *rtree = malloc(sizeof(rbt));
	rtree->tree= newBST(rbtDisplay,rbtCompare); //specific display and compare to rbt
	rtree->display=display;
	rtree->compare=comparator;
	rtree->size=0;
	rtree->words=0;
	return rtree;
}
static char color(bstNode *x){
	if (x==NULL){
		return 'B';
	}     
    else{
    	return (((rbtValue *)(x)->value)->color);
    }
}
static int islChild(bstNode *x){
	return x->parent->left==x;
}
static int isrChild(bstNode *x){
	return x->parent->right==x;
}
static int isLine(bstNode *rent,bstNode *kid){
	if(islChild(rent)){
		if(islChild(kid)){
			return 1;
		}
		return 0;
	}
	else{
		if(isrChild(kid)){
			return 1;
		}
		return 0;
	}
}
static bstNode *uncle(bstNode *x){
	//printf("in uncle\n");
	if(islChild(x->parent)){
		//printf("why is this breaking?\n");
		return (x->parent->parent->right);
	}
	else{
		return (x->parent->parent->left);
	}
}	
static void rotate(bst *tree,bstNode *x){
	bstNode *gpa=x->parent->parent;
	bstNode *lC=x->left;
	bstNode *rC=x->right;
	bstNode *rent=x->parent;
	if(isrChild(x)){
		x->left=rent;
		rent->parent=x;
		rent->right=lC;
		if(lC!=NULL){
			lC->parent=rent;
		}
		if(rent==tree->root){
			x->parent=x;
			tree->root=x;
		}
		else{
			if(gpa->left == rent){
				gpa->left=x;
			}
			else{
				gpa->right=x;
			}
			x->parent=gpa;
		}
	}
	else{
		x->right=rent;
		rent->parent=x;
		rent->left=rC;
		if(rC!=NULL){
			rC->parent=rent;
			
		}
		if(rent==tree->root){
			x->parent=x;
			tree->root=x;

		}
		else{
			if(gpa->right == rent){
				gpa->right=x;
			}
			else{
				gpa->left=x;
			}
			x->parent=gpa;
		}
	}
}
static void insertionFixUp(bst *tree,bstNode *x){
	bstNode *gpa=NULL;
	bstNode *unc=NULL;
	bstNode *oldP=NULL;
	bstNode *oldC=NULL;
	bstNode *rent=NULL;
	while(1){
		//printf("in while\n");
		if(tree->root==x){
			break;
		}
		rent=x->parent;
		if(color(rent)=='B'){
			break;
		}
		gpa=(x->parent->parent);
		unc=uncle(x);
		//printf("it did get set though right?\n");
		if(color(unc)=='R'){
			//printf("no shit does it get sent in here?\n");
			((rbtValue *) rent->value)->color='B';
			((rbtValue *) unc->value)->color='B';
			((rbtValue *) gpa->value)->color='R';
			x=gpa;
		}
		else{
			if(isLine(x->parent,x)==0){
				oldP=rent;
				oldC=x;
				rotate(tree,x);
				x=oldP;
				rent=oldC;
			}
			//else{
				((rbtValue *) rent->value)->color='B';
				((rbtValue *) gpa->value)->color='R';
				rotate(tree,x->parent);
			//}
			break;
		}
	}
	((rbtValue *) tree->root->value)->color='B';
}
	//printf("Did it even make it in here?\n");
	/*while(1){
		if(tree->root==x){
			//printf("in root\n");
			((rbtValue *)(x->value))->color='B';
			break;
		}
		if(((rbtValue *)(x->parent))->color=='B'){
			//printf("if rent is black\n");
			//((rbtValue *)(x->parent))(x->parent) && 
			break;
		}
		//printf("breaking here?\n");
		if(((x->parent->parent->left==x->parent) && (((rbtValue *)(x->parent->parent->right))->color)=='R') || ((x->parent->parent->right==x->parent) && (((rbtValue *)(x->parent->parent->right))->color)=='R')){
			//printf("if uncle is red\n");
			((rbtValue *)(x->parent))->color='B';
			if(x->parent->parent->left==x->parent){
				//printf("if gpa left child is rent\n");
				((rbtValue *)(x->parent->parent->right))->color='B';
			}
			else{
				//printf("if gpa right child is rent\n");
				((rbtValue *)(x->parent->parent->left))->color='B';
			}
			((rbtValue *)(x->parent->parent))->color='R';
			x=x->parent->parent;
		}
		else{
			//printf("uncle is black\n");
			if((x->parent->right==x) && (x->parent->parent->left==x->parent)){
				//printf("remember old rent of x \n do a left rot on x \n recall the ole rent of x, & set to x\n");
			}
			else if((x->parent->left==x) && (x->parent->parent->right==x->parent)){
				//printf("remember old rent of x \n do a right rot on x \n recall the ole rent of x, & set to x \n");
			}
			((rbtValue *)(x->parent))->color='B';
			((rbtValue *)(x->parent->parent))->color='B';
			if(x->parent==x->parent->parent->left){
				//printf("do a right rot on parent(x)\n");
			}
			else{
				//printf("do a left rot on parent(x)\n");
			}
			break;
		}
	}}
	((rbtValue *)(tree->root))->color='B';*/


void insertRBT(rbt *rtree,void *value){
	rbtValue *val=newRBTValue(rtree->display,rtree->compare);
	val->value=value;
	val->color='R';
	bstNode *n=findBSTNode(rtree->tree,val);
	if(n!=NULL){
		((rbtValue *) n->value)->freq++;
		rtree->words++;
	}
	else{
		n=insertBST(rtree->tree,val);
		insertionFixUp(rtree->tree,n);
		rtree->size++;
		rtree->words++;
	}
}
int findRBT(rbt *rtree,void *value){
	rbtValue *val=newRBTValue(rtree->display,rtree->compare);
	val->value=value;
	bstNode *n=findBSTNode(rtree->tree,val);
	if(n!=NULL){
		return (((rbtValue *)(n->value))->freq);
	}
	else{
		return 0;
	}
}
void deleteRBT(rbt *rtree,void *value){
	rbtValue *val=newRBTValue(rtree->display,rtree->compare);
    val->value=value;
    bstNode *x=findBSTNode(rtree->tree,val);
    if(x==NULL) {
        fprintf(stderr, "Value ");
        val->display(stderr,val->value);
        fprintf(stderr," not found.\n");
        return;
     }
}
   /* bstNode *val=findBSTNode(rtree->tree, value);
    while(val!=NULL){
        if(val->parent==val){ 
        	break;
        }
        if((((rbtValue *)(val->value))->color)=='R'){
        	break;
        }
        if(sibling is red){
            color parent red
            color sibling black
            rotate sibling to parent
            // should have black sibling now
		}
        else if (nephew is red){
            color sibling the same as parent
            color parent black
            color nephew black
            rotate sibling to parent
            // subtree and tree is BH balanced
            exit the loop
		}
        else if (niece is red){
            // nephew must be black
			color niece black
            color sibling red
            rotate niece to sibling
            // should have red nephew now
        }
        // sibling, niece, and nephew must be black
        else{
            color sibling red
			x = parent
		// this subtree is BH balanced, but tree is not
		}
	}
	color x black*/
int sizeRBT(rbt *rtree){
	return (rtree->size);
}
int wordsRBT(rbt *rtree){
	return (rtree->words);
}
void statisticsRBT(rbt *rtree,FILE *fp){
	fprintf(fp, "Words/Phrases: %d\n",wordsRBT(rtree));
	//fprintf(fp, "Nodes: %d\n",sizeRBT(rtree));
	statisticsBST(rtree->tree,fp);
}
void displayRBT(FILE *fp,rbt *rtree){
	displayBST(fp,rtree->tree);
}
// void checkRBT(rbt *);               //optional