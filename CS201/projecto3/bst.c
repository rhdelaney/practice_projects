#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "queue.h"

bst *newBST(void (*display)(FILE *,void *),int (*comparator)(void *,void *)){
	bst *tree = malloc(sizeof(bst));
	tree->root = NULL;
	tree->size=0;
	tree->display=display;
	tree->compare=comparator;
	//printf("Made into newBST\n");
	return tree;
}
bstNode *insertBST(bst *tree,void *value){
	//printf("Made into insertBST\n");
	bstNode *leaf= malloc(sizeof(bstNode));
	leaf->value=value;
	leaf->left=NULL;
	leaf->right=NULL;
	leaf->parent=NULL;
	tree->size=(tree->size) + 1;
	if(tree->root==NULL){
		//printf("Insert in root\n");
		tree->root=leaf;
		leaf->parent=leaf;
		//tree->size=(tree->size) + 1;
		return leaf;
	}
	else{
		bstNode *start=tree->root; 
		bstNode *rent=NULL;
		while(start!= NULL){
			rent=start;
			if(tree->compare(leaf->value, start->value)<0){ //if value is larger it goes to the right
				//if(start->left==NULL){//insert the babe
					//start->left=leaf;
					//leaf->parent=start;
					//tree->size=(tree->size) + 1;
					//printf("We inserted on the left dumbo\n");
					//return leaf;
				//}
				start=start->left; //if not keep moving
			}
			else {
				//if(start->left==NULL){//insert the babe
					//start->left=leaf;
					//leaf->parent=start;
					//tree->size=(tree->size) + 1;
					//printf("We inserted on the left\n");
					//return leaf;
				//}
				start=start->right; //if not keep moving
			}
		}
		leaf->parent=rent;
		if(tree->compare(leaf->value,rent->value)<0){
			rent->left=leaf;
		}
		else{
			rent->right=leaf;
		}
		return leaf;
	} 
} //returns inserted node
int findBST(bst *tree,void *value){
	//printf("Made it into findBST\n");
	if(tree->root==NULL){
		return 0;
	}
	else{
		bstNode *start=tree->root;
		while(start != NULL){
			if(tree->compare(value,start->value)==0){
				return 1;
			}
			else if(tree->compare(value, start->value)<0){ //if value is larger it goes to the right
				start=start->left;
			}
			else{
				start=start->right;
			}
		}
		return 0;
	}
} //returns 0 if not found if found 1 so it's boolean
bstNode *findBSTNode(bst *tree,void *value){
	//printf("Made it into findBSTNode\n");
	if(tree->root==NULL){
		return 0;
	}
	else{
		bstNode *start=tree->root;
		while(start != NULL){
			if(tree->compare(value,start->value)==0){
				return start;
			}
			else if(tree->compare(value, start->value)<0){ //if value is larger it goes to the right
				start=start->left;
			}
			else{
				start=start->right;
			}
		}
	}
	return 0;
}//returns 0 if not found returns node
bstNode *swapToLeafBSTNode(bstNode *n){
    bstNode *loc;
    void *temp;
    if(n->left==NULL && n->right==NULL){
        return n;
    } 
    else if(n->left!=NULL){
    	loc=n->left;
        while(loc->right!=NULL){
       		loc=loc->right;
        }
        	temp=n->value;
        	n->value=loc->value;
        	loc->value=temp;
    }
    else{
    	loc= n->right;
    	while(loc->left!=NULL){
        	loc=loc->left;
        }
        temp=n->value;
        n->value=loc->value;
        loc->value=temp;
    }
    return swapToLeafBSTNode(loc);
}
/*bstNode *swapToLeafBSTNode(bstNode *n){
	//printf("Made it into swapToLeafBSTNode\n");
	bstNode *loc;
	void *temp;
	if(n->left==NULL && n->right==NULL){
		return n;
	}
	else if(n->left!=NULL){
		loc=n->left;
		while(loc->right!=NULL){ //swap loc and n
			loc=loc->right;
		}
		temp=n->value;
		n->value=loc->value;
		loc->value=temp;
	}
	else if(n->right!=NULL){
		loc=n->right;
		while(loc->left!=NULL){
			loc=loc->left;
		}
		temp=n->value;
		n->value=loc->value;
		loc->value=temp;
	}
	return swapToLeafBSTNode(n);
	//for deletion purposes
} *///returns leaf node holding the original value
void pruneBSTNode(bst *tree,bstNode *leaf){
	//printf("Made it into pruneBSTNode\n");
	//bstNode *leaf=swapToLeafBSTNode(n);
	//printf("We pruning\n");
	if(leaf==tree->root && leaf->right==NULL && leaf->left==NULL){
		free(leaf);
		leaf=NULL;
		tree->root=NULL;
		tree->size=(tree->size)-1;
	}
	else if(leaf->parent->left==leaf){
		leaf->parent->left=NULL;
		tree->size=(tree->size)-1;
		free(leaf);
	}
	else{
		leaf->parent->right=NULL;
		tree->size=(tree->size)-1;
		free(leaf);
	}
} //disconnects n from tree
int sizeBST(bst *tree){
	//printf("Made it into sizeBST\n");
	return (tree->size);
} //returns the number of nodes in the tree
static int maxHeight(bstNode *n,int count){
	//printf("Made it into maxHeight\n");
	if(n){
		int x = maxHeight(n->left,count+1);
		int y = maxHeight(n->right,count+1);
		return ( x > y ? x : y);
	}
	return count;
}
static int minHeight(bstNode *n,int count){
	//printf("Made it into minHeight\n");
	if(n){
		int x = minHeight(n->left,count+1);
		int y = minHeight(n->right,count+1);
		return ( x < y ? x : y);
	}
	return count;
}
void statisticsBST(bst *tree,FILE *fp){
	//printf("Made it into statisticsBST\n");
	int min=minHeight(tree->root,0);
	int max=maxHeight(tree->root,0);
	/*if(min==1 && max!=1){
		min=max;
	}*/
	fprintf(fp, "Nodes: %d\n",sizeBST(tree));
	fprintf(fp, "Minimum depth: %d\n",min);
	fprintf(fp, "Maximum depth: %d\n",max);
} 
void displayBST(FILE *fp,bst *tree){ //displays tree, calls display function to display node value
	//okay so it needs a fixing with compare because a disply after swap tree is wack
	if(tree->root == NULL){
		fprintf(fp,"0:\n");
		return;
	}
	queue *disque = newQueue(tree->display);
	enqueue(disque, tree->root);
	enqueue(disque, NULL);
	bstNode *x = malloc(sizeof(bstNode));
	int level = 0;
	fprintf(fp, "%d:", level);
	/*if(tree->root == NULL){
		fprintf(fp," ");
		return;
	}*/
	while (sizeQueue(disque)){ 
		x = dequeue(disque);
		if(sizeQueue(disque) == 0){
			fprintf(fp, "\n");
			break;
		}
		else if(x == NULL){	//if the dequeue value is null
			fprintf(fp,"\n");
			enqueue(disque, NULL);	//enqueue null to represent end of level
			level++;
			fprintf(fp, "%d:", level);
		}
		else{
			fprintf(fp," ");
			if(x->left == NULL && x->right == NULL){
				fprintf(fp, "="); //it's a leaf bitch
			}
			//fprintf(fp, "\"");
			//fprintf(fp," ");
			tree->display(fp, x->value);
			//fprintf(fp, "\"");
			if(x == tree->root){
				fprintf(fp, "("); 
				tree->display(fp, x->parent->value);
				fprintf(fp, ")-"); //this test is on no space after root
			}
			else if(x->parent != NULL){
				if(tree->compare(x->value, x->parent->value)<0){
					fprintf(fp, "("); 
					tree->display(fp, x->parent->value);
					fprintf(fp, ")-l"); //since it isn't a right child it's obvi the wrong one
				}
				else{
					fprintf(fp, "("); 
					tree->display(fp, x->parent->value);
					fprintf(fp, ")-r"); //ayyeee lmao you had the right child congrats and sit on your lazy ass
				}
			}
			if(x->left != NULL){
				enqueue(disque, x->left);
			}
			if(x->right != NULL){
				enqueue(disque, x->right);
			}
		}
	}
}
//displays min and max depth shortest and longest trees height
/*void displayBST(FILE *fp,bst *tree){    //needs more work
	//printf("Made it into displayBST\n");
	if(sizeBST(tree)==0){
		fprintf(fp,"0: ");
		return;
	}
	queue *disque=disqueueue(tree->display);
	enqueue(disque,tree->root);
	while(sizeQueue(disque)){
		bstNode *x=dequeue(disque);
		if(x==NULL){
			fprintf(fp,"\n");
		}
		else{
			tree->display(fp,x->value);
			fprintf(fp, " ");
			if(x->left!=NULL){
				enqueue(disque,x->left);
			}
			if(x->right!=NULL){
				enqueue(disque,x->right);
			}
		}
		fprintf(fp, "\n");
	}
} //displays tree, calls display function to display node value
--an equals sign if the node is a leaf, 
--the node value, which may include a frequency count (if the count is greater than one) and a color, 
--a parenthesized display of the parent's value (which again may include a frequency count and color),
--a - if the node is the root, a -l if the node is a left child, and a -r otherwise*/
