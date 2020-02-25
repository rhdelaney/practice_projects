#include <iostream>
#include <fstream>
using namespace std;
/*steps:
1. read numbers from file
2. first number is root ->
3. if number is less than root it goes to the left of it
3. if number is greater than root it goes to the right of it
4. if space is occupied repeat using the new number as the root.
5. print out the preorder traversal and values-> start with less than

ideas for implementation:
* nodes / linked list
* use old format but get fancier
*/
struct Node{
	int rank;
	int value; //needs to be float variant tommorrow
	Node *leftChild;
	Node *rightChild;
	Node(int v, int level){
		value=v;
		rank=level;
		leftChild=rightChild=NULL;
	}
};
class Build{
public:
	Node *root; 
	Build(){
		root=NULL;
	}
	/*void makeTree(int x){
		//used list insertLast
		Node *temp=new Node;
		temp->value=x;
		Node *head=root;
		int level=0;
		addNode(temp,head,level);
	}*/
	void insert(int v){
		int level=0;
		if (root==NULL){
			root=new Node(v,0);
		}
		else{
			ins(root,v,level);
		}
	}
	void ins(Node* &n, int v,int level) {
        if(n == NULL){
        	n = new Node(v,level);
        }
        else{
        	level++;
        	ins((v < n->value ? n->leftChild : n->rightChild),v, level);
        }
    }
	/*void addNode(Node *temp, Node *head, int level){
		if(!(n==0)){
			if(x < head->value){
				while(head->leftChild!=NULL){
					head=head->leftChild;
					level++;
				}
				temp->root=head;
				head->leftChild=temp;
				temp->rank=level;
				n+=1;
			}
			else{
				temp->value=x
				temp->rank=level;
				temp->root=tail;
				tail->rightChild=temp;
				n+=1;
			}
		}
		else{
			temp->rank=0;
			temp->value=x;
			root=temp;
			leftChild=NULL;
			rightChild=NULL;
			n+=1;
		}
	}*/
	void preorder(Node *n) {
        if (n) {
        	preorder(n->leftChild);
            preorder(n->rightChild);
            cout << n->value << " : "<<n->rank<<endl;
        }
    }
    void printTree() {
        preorder(root);
        cout << endl;
    }
};

int main(int argc, char const *argv[]){
	ifstream fin;
	//ofstream fout;

	fin.open(argv[1]);
	Build tree;
	int value=0;

	while(fin>>value){
		tree.insert(value);
	}
	tree.printTree();
	return 0;
}