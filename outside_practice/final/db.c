#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"
#include "dll.h"
#include "scanner.h"
#include <limits.h>
//#include "integer.h"

//gets props
int getPropVal(properties *a){
	return a->val;
}
char *getPropName(properties *a){
	return a->name;
}
//gets dbnode
int getDBNodeVer(dbnode *a){
	return a->version;
}
int getDBNodeSys(dbnode *a){
	return a->sysid;
}
dll *getDBNodeData(dbnode *a){
	return a->data;
}
//gets docnode
int getDocNodeID(docnode *a){
	return a->docID;
}
int getDocNodeNumVer(docnode *a){
	return a->numVersions;
}
dll *getDocNodeVers(docnode *a){
	return a->versions;
}
//new functions
qNode *newQNode(char *field,char *op,int val){
	qNode *node= malloc(sizeof(qNode));
	node->val = val;
	node->op = op;
	node->fieldN=field;
	return node;
}
properties *newProperties(int value, char *name){
	properties *node= malloc(sizeof(properties));
	node->val = value;
	node->name = name;
	return node;
}
dbnode *newDBNode(int version,int sysid, dll *data){
	dbnode *items = malloc(sizeof(dbnode));
	if (items == 0){
		fprintf(stderr,"out of memory");
		exit(-1);
	}
	items->sysid=sysid;
	items->version = version;
	items->data = data;
	return items;
} 
docnode *newDocNode(int docID, int numVersions,dll *data){
	docnode *items = malloc(sizeof(docnode));
	if (items == 0){
		fprintf(stderr,"out of memory");
		exit(-1);
	}
	items->docID = docID;
	items->numVersions = numVersions;
	items->versions = data;
	return items;
} 
void *findDOCNode(dll *node,int ID){
	//printf("Made it into findBSTNode\n");
	if(sizeDLL(node)==0){
		return 0;
	}
	else{
		dllnode *start=node->head;
		while(start!= NULL){
			if( ((docnode *) (start->value))->docID == ID){
				//printf("starts value %d\n", ((docnode *) (start->value))->docID);
				return ((docnode *) (start->value));
			}
			start=start->next;
		}
	}
	return 0;
}
void *findDBNode(docnode *node,int ID){
	//printf("Made it into findBSTNode\n");
	if(sizeDLL(node->versions)==0){
		return 0;
	}
	else{
		dllnode *start=node->versions->head;
		while(start!= NULL){
				if( ((dbnode *) (start->value))->version == ID){
				//printf("starts value %d\n", ((docnode *) (start->value))->docID);
					return ((dbnode *) (start->value));
				}
			start=start->next;
		}
	}
	return 0;
}
int equalToQ(docnode *doc,dbnode *db, char *field, int value){
	int flag=0;
	if(strcmp(field,"sysid")==0 && getDBNodeSys(db)!=value){
		flag=1;
	}
	if(strcmp(field,"vn")==0 && getDBNodeVer(db)!=value){
		flag=1;
	}
	if(strcmp(field,"DocID")==0 && getDocNodeID(doc)!=value){
		flag=1;
	}
	dllnode *tempB=db->data->head;
	if(doc->versions->head!=NULL){
		while(tempB!=NULL){
			properties *p=tempB->value;
			if(strcmp(field,getPropName(p))==0 && getPropVal(p)!=value){
					flag=1;							
			}
			tempB=tempB->next;	
		}
	}
	return flag;
}
int greaterThanQ(docnode *doc,dbnode *db, char *field, int value){
	int flag=0;
	if(strcmp(field,"sysid")==0 && !(getDBNodeSys(db)>value) ){
		flag=1;
	}
	if(strcmp(field,"vn")==0 && !(getDBNodeVer(db)>value)) {
		flag=1;
	}
	if(strcmp(field,"DocID")==0 && !(getDocNodeID(doc)>value)) {
		flag=1;
	}
	dllnode *tempB=db->data->head;
	if(doc->versions->head!=NULL){
		while(tempB!=NULL){
			properties *p=tempB->value;
			if(strcmp(field,getPropName(p))==0 && !(getPropVal(p)>value)) {
					flag=1;							
			}
			tempB=tempB->next;	
		}
	}
	return flag;
}
int lessThanQ(docnode *doc,dbnode *db, char *field, int value){
	int flag=0;
	if(strcmp(field,"sysid")==0 && !(getDBNodeSys(db)<value) ){
		flag=1;
	}
	if(strcmp(field,"vn")==0 && !(getDBNodeVer(db)<value)) {
		flag=1;
	}
	if(strcmp(field,"DocID")==0 && !(getDocNodeID(doc)<value)) {
		flag=1;
	}
	dllnode *tempB=db->data->head;
	if(doc->versions->head!=NULL){
		while(tempB!=NULL){
			properties *p=tempB->value;
			if(strcmp(field,getPropName(p))==0 && !(getPropVal(p)<value)) {
				flag=1;							
			}
			tempB=tempB->next;	
		}
	}
	return flag;
}
int lessOEqualQ(docnode *doc,dbnode *db, char *field, int value){
	int flag=0;
	if(strcmp(field,"sysid")==0 && !(getDBNodeSys(db)<=value) ){
		flag=1;
	}
	if(strcmp(field,"vn")==0 && !(getDBNodeVer(db)<=value)) {
		flag=1;
	}
	if(strcmp(field,"DocID")==0 && !(getDocNodeID(doc)<=value)) {
		flag=1;
	}
	dllnode *tempB=db->data->head;
	if(doc->versions->head!=NULL){
		while(tempB!=NULL){
			properties *p=tempB->value;
			if(strcmp(field,getPropName(p))==0 && !(getPropVal(p)<=value)) {
				flag=1;							
			}
			tempB=tempB->next;	
		}
	}
	return flag;
}
int greaterOEqualQ(docnode *doc,dbnode *db, char *field, int value){
	int flag=0;
	if(strcmp(field,"sysid")==0 && !(getDBNodeSys(db)>=value) ){
		flag=1;
	}
	if(strcmp(field,"vn")==0 && !(getDBNodeVer(db)>=value)) {
		flag=1;
	}
	if(strcmp(field,"DocID")==0 && !(getDocNodeID(doc)>=value)) {
		flag=1;
	}
	dllnode *tempB=db->data->head;
	if(doc->versions->head!=NULL){
		while(tempB!=NULL){
			properties *p=tempB->value;
			if(strcmp(field,getPropName(p))==0 && !(getPropVal(p)>=value)) {
				flag=1;							
			}
			tempB=tempB->next;	
		}
	}
	return flag;
}
int notEqualQ(docnode *doc,dbnode *db, char *field, int value){
	int flag=0;
	if(strcmp(field,"sysid")==0 && getDBNodeSys(db)==value ){
		flag=1;
	}
	if(strcmp(field,"vn")==0 && getDBNodeVer(db)==value) {
		flag=1;
	}
	if(strcmp(field,"DocID")==0 && getDocNodeID(doc)==value) {
		flag=1;
	}
	dllnode *tempB=db->data->head;
	if(doc->versions->head!=NULL){
		while(tempB!=NULL){
			properties *p=tempB->value;
			if(strcmp(field,getPropName(p))==0 && getPropVal(p)==value) {
				flag=1;							
			}
			tempB=tempB->next;	
		}
	}
	return flag;
}
dll *multiQ(dll *items,dll *qList){
	dll *nItems=newDLL(NULL);
	int flag=0;
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		while(tempN!=NULL){
			docnode *doc=tempN->value;
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				while(tempA!=NULL){
					dbnode *db=tempA->value;
					dllnode *tempB=qList->head;
					if(qList->head!=NULL){
						while(tempB!=NULL){
							qNode *q=tempB->value;
							if(strcmp(q->op,"<")==0){
								flag=lessThanQ(doc,db,q->fieldN,q->val);
								if(flag){
									break;
								}
							}
							else if(strcmp(q->op,">")==0){
								flag=greaterThanQ(doc,db,q->fieldN,q->val);
								if(flag){
									break;
								}
							}
							else if(strcmp(q->op,"=")==0){
								flag=equalToQ(doc,db,q->fieldN,q->val);
								if(flag){
									break;
								}							
							}
							else if(strcmp(q->op,"<=")==0){
								flag=lessOEqualQ(doc,db,q->fieldN,q->val);
								if(flag){
									break;
								}
							}
							else if(strcmp(q->op,">=")==0){
								flag=greaterOEqualQ(doc,db,q->fieldN,q->val);
								if(flag){
									break;
								}
							}
							else if(strcmp(q->op,"<>")==0){
								flag=notEqualQ(doc,db,q->fieldN,q->val);
								if(flag){
									break;
								}
							}
							tempB=tempB->next;
						}
					}
					if(!flag){
						flag=0;
						dbnode *dbt=tempA->value;
						dll *tprop=newDLL(NULL);
						dllnode *tempC=dbt->data->head;
						while(tempC!=NULL){
							properties *p=tempC->value;
							insertDLL(tprop,sizeDLL(tprop),newProperties(getPropVal(p),getPropName(p)));
							tempC=tempC->next;	
						}
						if(!findDOCNode(nItems, getDocNodeID(doc))) { //search in DLL for docID
			                dll *vprop=newDLL(NULL);
			                insertDLL(vprop,sizeDLL(vprop),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                insertDLL(nItems,sizeDLL(nItems),newDocNode(getDocNodeID(doc),1,vprop));
			                tprop=newDLL(NULL);
			            }
			            else{
			                docnode *dNode=findDOCNode(nItems,getDocNodeID(doc));
			                insertDLL(dNode->versions,sizeDLL(dNode->versions),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                tprop=newDLL(NULL);
			            }
					}
					flag=0;
					tempA=tempA->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
	return nItems;
}
dll *lessThan(dll *items, char *field, int value, int numQ){
	dll *nItems=newDLL(NULL);
	int flag=numQ;
	flag=0;
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		while(tempN!=NULL){
			docnode *doc=tempN->value;
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				while(tempA!=NULL){
					dbnode *db=tempA->value;
					if(strcmp(field,"sysid")==0 && getDBNodeSys(db)<value){
						flag=1;
					}
					if(strcmp(field,"vn")==0 && getDBNodeVer(db)<value){
						flag=1;
					}
					if(strcmp(field,"DocID")==0 && getDocNodeID(doc)<value){
						flag=1;
					}
					dllnode *tempB=db->data->head;
					if(doc->versions->head!=NULL){
						while(tempB!=NULL){
							properties *p=tempB->value;
							if(strcmp(field,getPropName(p))==0 && getPropVal(p)<value){
								flag=1;
							}
							tempB=tempB->next;	
						}
					}
					if(flag){
						flag=0;
						dbnode *dbt=tempA->value;
						dll *tprop=newDLL(NULL);
						//fprintf(f, "vn: %d ",getDBNodeVer(dbt));
						//fprintf(f, "sysid: %d ",getDBNodeSys(dbt));
						//fprintf(f,"DocID: %d ",getDocNodeID(doc));
						dllnode *tempB=dbt->data->head;
						while(tempB!=NULL){
							properties *p=tempB->value;
							insertDLL(tprop,sizeDLL(tprop),newProperties(getPropVal(p),getPropName(p)));
							//fprintf(f, "%s: %d ",getPropName(p),getPropVal(p));
							tempB=tempB->next;	
						}
						if(!findDOCNode(nItems, getDocNodeID(doc))) { //search in DLL for docID
			                dll *vprop=newDLL(NULL);
			                insertDLL(vprop,sizeDLL(vprop),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                insertDLL(nItems,sizeDLL(nItems),newDocNode(getDocNodeID(doc),1,vprop));
			                tprop=newDLL(NULL);
			            }
			            else{
			                docnode *dNode=findDOCNode(nItems,getDocNodeID(doc));
			                insertDLL(dNode->versions,sizeDLL(dNode->versions),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                tprop=newDLL(NULL);
			            }
						//fprintf(f,"\n");
					}
					tempA=tempA->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
	return nItems;
}
dll *greaterThan(dll *items, char *field, int value, int numQ){
	dll *nItems=newDLL(NULL);
	int flag=numQ;
	flag=0;
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		while(tempN!=NULL){
			docnode *doc=tempN->value;
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				while(tempA!=NULL){
					dbnode *db=tempA->value;
					if(strcmp(field,"sysid")==0 && getDBNodeSys(db)>value){
						flag=1;
					}
					if(strcmp(field,"vn")==0 && getDBNodeVer(db)>value){
						flag=1;
					}
					if(strcmp(field,"DocID")==0 && getDocNodeID(doc)>value){
						flag=1;
					}
					dllnode *tempB=db->data->head;
					if(doc->versions->head!=NULL){
						while(tempB!=NULL){
							properties *p=tempB->value;
							if(strcmp(field,getPropName(p))==0 && getPropVal(p)>value){
								flag=1;
							}
							tempB=tempB->next;	
						}
					}
					if(flag){
						flag=0;
						dbnode *dbt=tempA->value;
						dll *tprop=newDLL(NULL);
						//fprintf(f, "vn: %d ",getDBNodeVer(dbt));
						//fprintf(f, "sysid: %d ",getDBNodeSys(dbt));
						//fprintf(f,"DocID: %d ",getDocNodeID(doc));
						dllnode *tempB=dbt->data->head;
						while(tempB!=NULL){
							properties *p=tempB->value;
							insertDLL(tprop,sizeDLL(tprop),newProperties(getPropVal(p),getPropName(p)));
							//fprintf(f, "%s: %d ",getPropName(p),getPropVal(p));
							tempB=tempB->next;	
						}
						if(!findDOCNode(nItems, getDocNodeID(doc))) { //search in DLL for docID
			                dll *vprop=newDLL(NULL);
			                insertDLL(vprop,sizeDLL(vprop),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                insertDLL(nItems,sizeDLL(nItems),newDocNode(getDocNodeID(doc),1,vprop));
			                tprop=newDLL(NULL);
			            }
			            else{
			                docnode *dNode=findDOCNode(nItems,getDocNodeID(doc));
			                insertDLL(dNode->versions,sizeDLL(dNode->versions),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                tprop=newDLL(NULL);
			            }
						//fprintf(f,"\n");
					}
					tempA=tempA->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
	return nItems;
}
dll *equalTo(dll *items, char *field, int value, int numQ){
	dll *nItems=newDLL(NULL);
	int flag=numQ;
	flag=0;
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		while(tempN!=NULL){
			docnode *doc=tempN->value;
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				while(tempA!=NULL){
					dbnode *db=tempA->value;
					if(strcmp(field,"sysid")==0 && getDBNodeSys(db)==value){
						flag=1;
					}
					if(strcmp(field,"vn")==0 && getDBNodeVer(db)==value){
						flag=1;
					}
					if(strcmp(field,"DocID")==0 && getDocNodeID(doc)==value){
						flag=1;
					}
					dllnode *tempB=db->data->head;
					if(doc->versions->head!=NULL){
						while(tempB!=NULL){
							properties *p=tempB->value;
							if(strcmp(field,getPropName(p))==0 && getPropVal(p)==value){
								flag=1;
							}
							tempB=tempB->next;	
						}
					}
					if(flag){
						flag=0;
						dbnode *dbt=tempA->value;
						dll *tprop=newDLL(NULL);
						//fprintf(f, "vn: %d ",getDBNodeVer(dbt));
						//fprintf(f, "sysid: %d ",getDBNodeSys(dbt));
						//fprintf(f,"DocID: %d ",getDocNodeID(doc));
						dllnode *tempB=dbt->data->head;
						while(tempB!=NULL){
							properties *p=tempB->value;
							insertDLL(tprop,sizeDLL(tprop),newProperties(getPropVal(p),getPropName(p)));
							//fprintf(f, "%s: %d ",getPropName(p),getPropVal(p));
							tempB=tempB->next;	
						}
						if(!findDOCNode(nItems, getDocNodeID(doc))) { //search in DLL for docID
			                dll *vprop=newDLL(NULL);
			                insertDLL(vprop,sizeDLL(vprop),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                insertDLL(nItems,sizeDLL(nItems),newDocNode(getDocNodeID(doc),1,vprop));
			                tprop=newDLL(NULL);
			            }
			            else{
			                docnode *dNode=findDOCNode(nItems,getDocNodeID(doc));
			                insertDLL(dNode->versions,sizeDLL(dNode->versions),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                tprop=newDLL(NULL);
			            }
						//fprintf(f,"\n");
					}
					tempA=tempA->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
	return nItems;
}
dll *lessOEqual(dll *items, char *field, int value, int numQ){
	dll *nItems=newDLL(NULL);
	int flag=numQ;
	flag=0;
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		while(tempN!=NULL){
			docnode *doc=tempN->value;
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				while(tempA!=NULL){
					dbnode *db=tempA->value;
					if(strcmp(field,"sysid")==0 && getDBNodeSys(db)<=value){
						flag=1;
					}
					if(strcmp(field,"vn")==0 && getDBNodeVer(db)<=value){
						flag=1;
					}
					if(strcmp(field,"DocID")==0 && getDocNodeID(doc)<=value){
						flag=1;
					}
					dllnode *tempB=db->data->head;
					if(doc->versions->head!=NULL){
						while(tempB!=NULL){
							properties *p=tempB->value;
							if(strcmp(field,getPropName(p))==0 && getPropVal(p)<=value){
								flag=1;
							}
							tempB=tempB->next;	
						}
					}
					if(flag){
						flag=0;
						dbnode *dbt=tempA->value;
						dll *tprop=newDLL(NULL);
						//fprintf(f, "vn: %d ",getDBNodeVer(dbt));
						//fprintf(f, "sysid: %d ",getDBNodeSys(dbt));
						//fprintf(f,"DocID: %d ",getDocNodeID(doc));
						dllnode *tempB=dbt->data->head;
						while(tempB!=NULL){
							properties *p=tempB->value;
							insertDLL(tprop,sizeDLL(tprop),newProperties(getPropVal(p),getPropName(p)));
							//fprintf(f, "%s: %d ",getPropName(p),getPropVal(p));
							tempB=tempB->next;	
						}
						if(!findDOCNode(nItems, getDocNodeID(doc))) { //search in DLL for docID
			                dll *vprop=newDLL(NULL);
			                insertDLL(vprop,sizeDLL(vprop),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                insertDLL(nItems,sizeDLL(nItems),newDocNode(getDocNodeID(doc),1,vprop));
			                tprop=newDLL(NULL);
			            }
			            else{
			                docnode *dNode=findDOCNode(nItems,getDocNodeID(doc));
			                insertDLL(dNode->versions,sizeDLL(dNode->versions),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                tprop=newDLL(NULL);
			            }
						//fprintf(f,"\n");
					}
					tempA=tempA->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
	return nItems;
}
dll *greaterOEqual(dll *items, char *field, int value, int numQ){
	dll *nItems=newDLL(NULL);
	int flag=numQ;
	flag=0;
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		while(tempN!=NULL){
			docnode *doc=tempN->value;
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				while(tempA!=NULL){
					dbnode *db=tempA->value;
					if(strcmp(field,"sysid")==0 && getDBNodeSys(db)>=value){
						flag=1;
					}
					if(strcmp(field,"vn")==0 && getDBNodeVer(db)>=value){
						flag=1;
					}
					if(strcmp(field,"DocID")==0 && getDocNodeID(doc)>=value){
						flag=1;
					}
					dllnode *tempB=db->data->head;
					if(doc->versions->head!=NULL){
						while(tempB!=NULL){
							properties *p=tempB->value;
							if(strcmp(field,getPropName(p))==0 && getPropVal(p)>=value){
								flag=1;
							}
							tempB=tempB->next;	
						}
					}
					if(flag){
						flag=0;
						dbnode *dbt=tempA->value;
						dll *tprop=newDLL(NULL);
						//fprintf(f, "vn: %d ",getDBNodeVer(dbt));
						//fprintf(f, "sysid: %d ",getDBNodeSys(dbt));
						//fprintf(f,"DocID: %d ",getDocNodeID(doc));
						dllnode *tempB=dbt->data->head;
						while(tempB!=NULL){
							properties *p=tempB->value;
							insertDLL(tprop,sizeDLL(tprop),newProperties(getPropVal(p),getPropName(p)));
							//fprintf(f, "%s: %d ",getPropName(p),getPropVal(p));
							tempB=tempB->next;	
						}
						if(!findDOCNode(nItems, getDocNodeID(doc))) { //search in DLL for docID
			                dll *vprop=newDLL(NULL);
			                insertDLL(vprop,sizeDLL(vprop),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                insertDLL(nItems,sizeDLL(nItems),newDocNode(getDocNodeID(doc),1,vprop));
			                tprop=newDLL(NULL);
			            }
			            else{
			                docnode *dNode=findDOCNode(nItems,getDocNodeID(doc));
			                insertDLL(dNode->versions,sizeDLL(dNode->versions),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                tprop=newDLL(NULL);
			            }
						//fprintf(f,"\n");
					}
					tempA=tempA->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
	return nItems;
}
dll *notEqual(dll *items, char *field, int value, int numQ){
	dll *nItems=newDLL(NULL);
	int flag=numQ;
	flag=0;
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		while(tempN!=NULL){
			docnode *doc=tempN->value;
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				while(tempA!=NULL){
					dbnode *db=tempA->value;
					if(strcmp(field,"sysid")==0 && getDBNodeSys(db)!=value){
						flag=1;
					}
					if(strcmp(field,"vn")==0 && getDBNodeVer(db)!=value){
						flag=1;
					}
					if(strcmp(field,"DocID")==0 && getDocNodeID(doc)!=value){
						flag=1;
					}
					dllnode *tempB=db->data->head;
					if(doc->versions->head!=NULL){
						while(tempB!=NULL){
							properties *p=tempB->value;
							if(strcmp(field,getPropName(p))==0 && getPropVal(p)!=value){
								flag=1;
							}
							tempB=tempB->next;	
						}
					}
					if(flag){
						flag=0;
						dbnode *dbt=tempA->value;
						dll *tprop=newDLL(NULL);
						//fprintf(f, "vn: %d ",getDBNodeVer(dbt));
						//fprintf(f, "sysid: %d ",getDBNodeSys(dbt));
						//fprintf(f,"DocID: %d ",getDocNodeID(doc));
						dllnode *tempB=dbt->data->head;
						while(tempB!=NULL){
							properties *p=tempB->value;
							insertDLL(tprop,sizeDLL(tprop),newProperties(getPropVal(p),getPropName(p)));
							//fprintf(f, "%s: %d ",getPropName(p),getPropVal(p));
							tempB=tempB->next;	
						}
						if(!findDOCNode(nItems, getDocNodeID(doc))) { //search in DLL for docID
			                dll *vprop=newDLL(NULL);
			                insertDLL(vprop,sizeDLL(vprop),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                insertDLL(nItems,sizeDLL(nItems),newDocNode(getDocNodeID(doc),1,vprop));
			                tprop=newDLL(NULL);
			            }
			            else{
			                docnode *dNode=findDOCNode(nItems,getDocNodeID(doc));
			                insertDLL(dNode->versions,sizeDLL(dNode->versions),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                tprop=newDLL(NULL);
			            }
						//fprintf(f,"\n");
					}
					tempA=tempA->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
	return nItems;
}
dll *query(dll *items,char *field,char *operator,int value,int numQ){
	dll *nItems=newDLL(NULL);
	if(strcmp(operator,"<")==0){
		nItems=lessThan(items,field,value, numQ);
	}
	else if(strcmp(operator,">")==0){
		nItems=greaterThan(items,field,value,numQ);
	}
	else if(strcmp(operator,"=")==0){
		nItems=equalTo(items,field,value,numQ);
	}
	else if(strcmp(operator,"<=")==0){
		nItems=lessOEqual(items,field,value,numQ);
	}
	else if(strcmp(operator,">=")==0){
		nItems=greaterOEqual(items,field,value,numQ);
	}
	else if(strcmp(operator,"<>")==0){
		nItems=notEqual(items,field,value,numQ);
	}
	return nItems;
}
//this is broken
//it isn't counting to the versions needed atm

int count(dll *items,char *field,int ver){
	int c=0;
	int all=0;
 	//set to 1 for all //0 for field searches
	//change this value based on above queries
	dllnode *tempN=items->head;
	if (items->head !=NULL && all>=0){
		//if head isn't null
		while(tempN!=NULL){
			//if the node isn't null?
			docnode *doc=tempN->value;
			//dllnode's value=docnode 
			//print that doc id
			//attempt to go lower
			//all=0;
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				//this is where shit gets weird
				all=0;
				while(tempA!=NULL && all<ver){
					dbnode *db=tempA->value;
						if(strcmp(field,"vn")==0){
							c++;
							all++;
						}
					//we need if's to check if these fields are needed
						if(strcmp(field,"sysid")==0){
							c++;
							all++;
						}
					//anotha one
						if(strcmp(field,"DocID")==0){
							c++;
							all++;
						}
					//fprintf(f,"DocID: %d ",getDocNodeID(doc));
					dllnode *tempB=db->data->head;
					if(doc->versions->head!=NULL){
						//this is where shit gets weird
						while(tempB!=NULL){
							properties *p=tempB->value;
							//code here to the end of the if braces is an attempt to do this
								if(strcmp(field,getPropName(p))==0){
									//changed to belowfprintf(f, "sysid: %d ",getDBNodeSys(db));
									c++;
									all++;
								}
							tempB=tempB->next;	
						}
					}
					//all++;
					tempA=tempA->next;	
				}
			}
			tempN=tempN->next;	
		}
	}	
	return c;
}
int countCurr(dll *items, char *field){
	int c=0;
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		//if head isn't null
		while(tempN!=NULL){
			docnode *doc=tempN->value;
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				dbnode *db=tempA->value;
				if(strcmp(field,"sysid")==0){
					c++;
				}
				if(strcmp(field,"vn")==0){
					c++;
				}
				if(strcmp(field,"DocID")==0){
					c++;
				}
				dllnode *tempB=db->data->head;
				while(tempB!=NULL){
					properties *p=tempB->value;
					if(strcmp(field,getPropName(p))==0){
						c++;
					}
					tempB=tempB->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
	return c;
}
void sortC(dll *items,FILE *f, char *field){
	int i=0;
	int flag=0;
	int max=INT_MIN;
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		//if head isn't null
		while(tempN!=NULL){
			docnode *doc=tempN->value;
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				dbnode *db=tempA->value;
				if(strcmp(field,"sysid")==0){
					if(getDBNodeSys(db)>max){
						max=getDBNodeSys(db);
					}
				}
				if(strcmp(field,"vn")==0){
					if(getDBNodeVer(db)>max){
						max=getDBNodeVer(db);
					}
				}
				if(strcmp(field,"DocID")==0){
					if(getDocNodeID(doc)>max){
						max=getDocNodeID(doc);
					}
				}
				dllnode *tempB=db->data->head;
				while(tempB!=NULL){
					properties *p=tempB->value;
					if(strcmp(field,getPropName(p))==0){
						if(getPropVal(p)>max){
							max=getPropVal(p);
						}
						break;
					}
					tempB=tempB->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
	//loop start
	for(i=0;i<max;i++){
		dllnode *tempN=items->head;
		if (items->head !=NULL){
			//if head isn't null
			while(tempN!=NULL){
				docnode *doc=tempN->value;
				dllnode *tempA=doc->versions->head;
				if(doc->versions->head!=NULL){
					dbnode *db=tempA->value;
					if(strcmp(field,"sysid")==0 && getDBNodeSys(db)==i){
						flag=1;
					}
					if(strcmp(field,"vn")==0 && getDBNodeVer(db)==i){
						flag=1;
					}
					if(strcmp(field,"DocID")==0 && getDocNodeID(doc)==i){
						flag=1;
					}
					dllnode *tempB=db->data->head;
					while(tempB!=NULL){
						properties *p=tempB->value;
						if(strcmp(field,getPropName(p))==0 && getPropVal(p)==i){
							flag=1;
							break;
						}
						tempB=tempB->next;	
					}
				}
				if(flag){
					flag=0;
					dbnode *dbt=tempA->value;
					fprintf(f, "vn: %d ",getDBNodeVer(dbt));
					fprintf(f, "sysid: %d ",getDBNodeSys(dbt));
					fprintf(f,"DocID: %d ",getDocNodeID(doc));
					dllnode *tempB=dbt->data->head;
					while(tempB!=NULL){
						properties *p=tempB->value;
						fprintf(f, "%s: %d ",getPropName(p),getPropVal(p));
						tempB=tempB->next;	
					}
					fprintf(f,"\n");
				}
				tempN=tempN->next;	
			}
		}
	}
}
void sortX(dll *items, FILE *f, char *field, int v){
	int i=0;
	int flag=0;
	int max=INT_MIN;
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		while(tempN!=NULL){
			docnode *doc=tempN->value;
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				while(tempA!=NULL){
					dbnode *db=tempA->value;
					if(strcmp(field,"sysid")==0){
						if(getDBNodeSys(db)>max){
							max=getDBNodeSys(db);
						}
					}
					if(strcmp(field,"vn")==0){
						if(getDBNodeVer(db)>max){
							max=getDBNodeVer(db);
						}
					}
					if(strcmp(field,"DocID")==0){
						if(getDocNodeID(doc)>max){
							max=getDocNodeID(doc);
						}
					}
					dllnode *tempB=db->data->head;
					if(doc->versions->head!=NULL){
						//this is where shit gets weird
						while(tempB!=NULL){
							properties *p=tempB->value;
							//code here to the end of the if braces is an attempt to do this
							if(strcmp(field,getPropName(p))==0){
								if(getPropVal(p)>max){
									max=getPropVal(p);
								}
							}
							tempB=tempB->next;	
						}
					}
					tempA=tempA->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
	int count=0;
	for(i=0;i<max;i++){
		dllnode *tempN=items->head;
		if (items->head !=NULL){
			while(tempN!=NULL){
				docnode *doc=tempN->value;
				dllnode *tempA=doc->versions->head;
				if(doc->versions->head!=NULL){
					count=0;
					while(tempA!=NULL && count<v){
						dbnode *db=tempA->value;
						if(strcmp(field,"sysid")==0 && getDBNodeSys(db)==i){
							flag=1;
						}
						if(strcmp(field,"vn")==0 && getDBNodeVer(db)==i){
							flag=1;
						}
						if(strcmp(field,"DocID")==0 && getDocNodeID(doc)==i){
							flag=1;
						}
						dllnode *tempB=db->data->head;
						if(doc->versions->head!=NULL){
							//this is where shit gets weird
							while(tempB!=NULL){
								properties *p=tempB->value;
								//code here to the end of the if braces is an attempt to do this
								if(strcmp(field,getPropName(p))==0 && getPropVal(p)==i){
									flag=1;
								}
								tempB=tempB->next;	
							}
						}
						if(flag){
							flag=0;
							dbnode *dbt=tempA->value;
							fprintf(f, "vn: %d ",getDBNodeVer(dbt));
							fprintf(f, "sysid: %d ",getDBNodeSys(dbt));
							fprintf(f,"DocID: %d ",getDocNodeID(doc));
							dllnode *tempB=dbt->data->head;
							while(tempB!=NULL){
								properties *p=tempB->value;
								fprintf(f, "%s: %d ",getPropName(p),getPropVal(p));
								tempB=tempB->next;	
							}
							fprintf(f,"\n");
						}
						count++;
						tempA=tempA->next;	
					}
				}
				tempN=tempN->next;	
			}
		}
	}
}
void sortAll(dll *items, FILE *f, char *field){
	int i=0;
	int flag=0;
	int max=INT_MIN;
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		//if head isn't null
		while(tempN!=NULL){
			//if the node isn't null?
			docnode *doc=tempN->value;
			//dllnode's value=docnode 
			//print that doc id
			//attempt to go lower
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				//this is where shit gets weird
				while(tempA!=NULL){
					dbnode *db=tempA->value;
					if(strcmp(field,"sysid")==0){
						if(getDBNodeSys(db)>max){
							max=getDBNodeSys(db);
						}
					}
					if(strcmp(field,"vn")==0){ 
						if(getDBNodeVer(db)>max){
							max=getDBNodeVer(db);
						}
					}
					if(strcmp(field,"DocID")==0){
						if(getDocNodeID(doc)>max){
							max=getDocNodeID(doc);
						}
					}
					dllnode *tempB=db->data->head;
					if(doc->versions->head!=NULL){
						//this is where shit gets weird
						while(tempB!=NULL){
							properties *p=tempB->value;
							//code here to the end of the if braces is an attempt to do this
							if(strcmp(field,getPropName(p))==0){
								if(getPropVal(p)>max){
									max=getPropVal(p);
								}
							}
							tempB=tempB->next;	
						}
					}
					tempA=tempA->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
	for(i=0;i<max;i++){
		dllnode *tempN=items->head;
		if (items->head !=NULL){
			//if head isn't null
			while(tempN!=NULL){
				//if the node isn't null?
				docnode *doc=tempN->value;
				//dllnode's value=docnode 
				//print that doc id
				//attempt to go lower
				dllnode *tempA=doc->versions->head;
				if(doc->versions->head!=NULL){
					//this is where shit gets weird
					while(tempA!=NULL){
						dbnode *db=tempA->value;
						if(strcmp(field,"sysid")==0 && getDBNodeSys(db)==i){
							flag=1;
						}
						if(strcmp(field,"vn")==0 && getDBNodeVer(db)==i){
							flag=1;
						}
						if(strcmp(field,"DocID")==0 && getDocNodeID(doc)==i){
							flag=1;
						}
						dllnode *tempB=db->data->head;
						if(doc->versions->head!=NULL){
							//this is where shit gets weird
							while(tempB!=NULL){
								properties *p=tempB->value;
								//code here to the end of the if braces is an attempt to do this
								if(strcmp(field,getPropName(p))==0 && getPropVal(p)==i){
									flag=1;
								}
								tempB=tempB->next;	
							}
						}
						if(flag){
							flag=0;
							dbnode *dbt=tempA->value;
							fprintf(f, "vn: %d ",getDBNodeVer(dbt));
							fprintf(f, "sysid: %d ",getDBNodeSys(dbt));
							fprintf(f,"DocID: %d ",getDocNodeID(doc));
							dllnode *tempB=dbt->data->head;
							while(tempB!=NULL){
								properties *p=tempB->value;
								fprintf(f, "%s: %d ",getPropName(p),getPropVal(p));
								tempB=tempB->next;	
							}
							fprintf(f,"\n");
						}
						tempA=tempA->next;	
					}
				// if(flag){
				// 	flag=0;
				// 	dbnode *dbt=tempA->value;
				// 	fprintf(f, "vn: %d ",getDBNodeVer(dbt));
				// 	fprintf(f, "sysid: %d ",getDBNodeSys(dbt));
				// 	fprintf(f,"DocID: %d ",getDocNodeID(doc));
				// 	dllnode *tempB=dbt->data->head;
				// 	while(tempB!=NULL){
				// 		properties *p=tempB->value;
				// 		fprintf(f, "%s: %d ",getPropName(p),getPropVal(p));
				// 		tempB=tempB->next;	
				// 	}
				// 	fprintf(f,"\n");
				// }
				}
				tempN=tempN->next;	
			}
		}
	}
}
//void sort(dll *final, char *field, int v){}

int countAll(dll *items, char *field){
	int c=0;
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		//if head isn't null
		while(tempN!=NULL){
			//if the node isn't null?
			docnode *doc=tempN->value;
			//dllnode's value=docnode 
			//print that doc id
			//attempt to go lower
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				//this is where shit gets weird
				while(tempA!=NULL){
					dbnode *db=tempA->value;
					if(strcmp(field,"sysid")==0){
						c++;
					}
					if(strcmp(field,"vn")==0){
						c++;
					}
					if(strcmp(field,"DocID")==0){
						c++;
					}
					dllnode *tempB=db->data->head;
					if(doc->versions->head!=NULL){
						//this is where shit gets weird
						while(tempB!=NULL){
							properties *p=tempB->value;
							//code here to the end of the if braces is an attempt to do this
							if(strcmp(field,getPropName(p))==0){
								c++;
							}
							tempB=tempB->next;	
						}
					}
					tempA=tempA->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
	return c;
}
dll *insert(dll *final, FILE *data, int index){
	char dummy;
	int docID, value;
	char *name=readToken(data);
	dll *tprop=newDLL(NULL);
	while(name!=NULL){
        if(strcmp(name,"DocID")==0){
            dummy=readChar(data);
            docID=readInt(data);
        }
        else{
            dummy=readChar(data);
            value=readInt(data);
            insertDLL(tprop,sizeDLL(tprop),newProperties(value,name));
        }
        dummy=fgetc(data);
        if(dummy==')'){
            if(!findDOCNode(final, docID)){ //search in DLL for docID
                dll *vprop=newDLL(NULL);
                insertDLL(vprop,sizeDLL(vprop),newDBNode(1,index,tprop));
                insertDLL(final,sizeDLL(final),newDocNode(docID,1,vprop));
                break;
            }
            else{
            	docnode *dNode=findDOCNode(final,docID);
            	dNode->numVersions=(dNode->numVersions) + 1;
              	insertDLL(dNode->versions,sizeDLL(dNode->versions),newDBNode(dNode->numVersions,index,tprop));
                break;
            }
        }
        else{
            ungetc(dummy,data);
        }
        name=readToken(data);
    }
    return final;
}
//needs some work for certain versions only filter etc-> maybe use versions to filter
//then send here to only print fields? idk wtf rip
void printValues(dll *items, FILE *f,dll *fields,int versions){
	int count=0;
	dllnode *tempN=items->head;
	if (items->head !=NULL && fields!=NULL){
		//if head isn't null
		while(tempN!=NULL){
			//if the node isn't null?
			docnode *doc=tempN->value;
			//dllnode's value=docnode 
			//print that doc id
			//attempt to go lower
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				//this is where shit gets weird
				count=0;
				while(tempA!=NULL && count<versions){
					dbnode *db=tempA->value;
					fprintf(f, "\nvn:%d ",getDBNodeVer(db));
					//we need if's to check if these fields are needed
					dllnode *start=fields->head;
					if(fields->head!=NULL){
						while(start!=NULL){
							if(strcmp((char*)start->value,"sysid")==0){
								fprintf(f, "sysid:%d ",getDBNodeSys(db));
							}
							start=start->next;
						}
					}
					//anotha one
					start=fields->head;
					if(fields->head!=NULL){
						while(start!=NULL){
							if(strcmp((char*)start->value,"DocID")==0){
								fprintf(f,"DocID:%d ",getDocNodeID(doc));
							}
							start=start->next;
						}
					}
					//fprintf(f,"DocID: %d ",getDocNodeID(doc));
					dllnode *tempB=db->data->head;
					if(doc->versions->head!=NULL){
						//this is where shit gets weird
						while(tempB!=NULL){
							properties *p=tempB->value;
							//code here to the end of the if braces is an attempt to do this
							start=fields->head;
							if(fields->head!=NULL){
								while(start!=NULL){
									if(strcmp((char*)start->value,getPropName(p))==0){
										//changed to belowfprintf(f, "sysid: %d ",getDBNodeSys(db));
										fprintf(f, "%s:%d ",getPropName(p),getPropVal(p));
									}
									start=start->next;
								}
							}
							//added code here
							//fprintf(f, "%s:%d",getPropName(p),getPropVal(p));
							// if(tempB->next!=NULL){
							// 	fprintf(f," ");
							// }
							tempB=tempB->next;	
						}
					}
					//if(tempA->next!=NULL){
					//	fprintf(f," \n");
					//}
					count++;
					tempA=tempA->next;	
				}
			}
			//if(tempN->next!=NULL){
			//	fprintf(f,"\n");
			//}
			tempN=tempN->next;	
		}
	}
	//fprintf(f,"\n");	
}
void printAllValues(dll *items, FILE *f){
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		//if head isn't null
		while(tempN!=NULL){
			//if the node isn't null?
			docnode *doc=tempN->value;
			//dllnode's value=docnode 
			//print that doc id
			//attempt to go lower
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				//this is where shit gets weird
				while(tempA!=NULL){
					dbnode *db=tempA->value;
					fprintf(f, "\nvn:%d ",getDBNodeVer(db));
					//we need if's to check if these fields are needed
					fprintf(f, "sysid:%d ",getDBNodeSys(db));
					fprintf(f,"DocID:%d ",getDocNodeID(doc));
					//fprintf(f,"DocID: %d ",getDocNodeID(doc));
					dllnode *tempB=db->data->head;
					if(doc->versions->head!=NULL){
						//this is where shit gets weird
						while(tempB!=NULL){
							properties *p=tempB->value;
							//code here to the end of the if braces is an attempt to do this
							fprintf(f, "%s:%d ",getPropName(p),getPropVal(p));
							// if(tempB->next!=NULL){
							// 	fprintf(f," ");
							// }
							tempB=tempB->next;	
						}
					}
					// if(tempA->next!=NULL){
					// 	fprintf(f," \n");
					// }
					tempA=tempA->next;	
				}
			}
			// if(tempN->next!=NULL){
			// 	fprintf(f,"\n");
			// }
			tempN=tempN->next;	
		}
	}
	//fprintf(f,"\n");	
}
void printCurrValues(dll *items, FILE *f, dll *fields){
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		//if head isn't null
		while(tempN!=NULL){
			docnode *doc=tempN->value;
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				dbnode *db=tempA->value;
				fprintf(f, "\nvn:%d ",getDBNodeVer(db));
				dllnode *start=fields->head;
				if(fields->head!=NULL){
					while(start!=NULL){
						if(strcmp((char*)start->value,"sysid")==0){
							fprintf(f, "sysid:%d ",getDBNodeSys(db));
						}
						start=start->next;
					}
				}
				//anotha one
				start=fields->head;
				if(fields->head!=NULL){
					while(start!=NULL){
						if(strcmp((char*)start->value,"DocID")==0){
							fprintf(f,"DocID:%d ",getDocNodeID(doc));
						}
						start=start->next;
					}
				}
				//fprintf(f,"DocID: %d ",getDocNodeID(doc));
				dllnode *tempB=db->data->head;
				if(doc->versions->head!=NULL){
					//this is where shit gets weird
					while(tempB!=NULL){
						properties *p=tempB->value;
						//code here to the end of the if braces is an attempt to do this
						start=fields->head;
						if(fields->head!=NULL){
							while(start!=NULL){
								if(strcmp((char*)start->value,getPropName(p))==0){
									//changed to belowfprintf(f, "sysid: %d ",getDBNodeSys(db));
									fprintf(f, "%s:%d ",getPropName(p),getPropVal(p));
								}
								start=start->next;
							}
						}
						// if(tempB->next!=NULL){
						// 	fprintf(f," ");
						// }
						tempB=tempB->next;	
					}
				}
			}
			// if(tempN->next!=NULL){
			// 	fprintf(f,"\n");
			// }
		tempN=tempN->next;
		}	
	}
	// fprintf(f,"\n");	
}
void printAllCurrValues(dll *items, FILE *f){
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		//if head isn't null
		while(tempN!=NULL){
			docnode *doc=tempN->value;
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				dbnode *db=tempA->value;
				fprintf(f, "\nvn: %d ",getDBNodeVer(db));
				fprintf(f, "sysid: %d ",getDBNodeSys(db));
				fprintf(f,"DocID: %d ",getDocNodeID(doc));
				dllnode *tempB=db->data->head;
				while(tempB!=NULL){
					properties *p=tempB->value;
					fprintf(f, "%s:%d ",getPropName(p),getPropVal(p));
					tempB=tempB->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
}
void printAllValuesVer(dll *items, FILE *f, int versions){
	int count=0;
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		//if head isn't null
		while(tempN!=NULL){
			//if the node isn't null?
			docnode *doc=tempN->value;
			//dllnode's value=docnode 
			//print that doc id
			//attempt to go lower
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				//this is where shit gets weird
				count=0;
				while(tempA!=NULL && count<versions){
					dbnode *db=tempA->value;
					fprintf(f, "\nvn:%d ",getDBNodeVer(db));
					//we need if's to check if these fields are needed
					fprintf(f, "sysid:%d ",getDBNodeSys(db));
					fprintf(f,"DocID:%d ",getDocNodeID(doc));
					//fprintf(f,"DocID: %d ",getDocNodeID(doc));
					dllnode *tempB=db->data->head;
					if(doc->versions->head!=NULL){
						//this is where shit gets weird
						while(tempB!=NULL){
							properties *p=tempB->value;
							//code here to the end of the if braces is an attempt to do this
							fprintf(f, "%s:%d ",getPropName(p),getPropVal(p));
							tempB=tempB->next;	
						}
					}
					count++;
					tempA=tempA->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
}
void unionDB(dll *og, dll *items){
	dllnode *tempN=items->head;
	if (items->head !=NULL){
		while(tempN!=NULL){
			docnode *doc=tempN->value;
			dllnode *tempA=doc->versions->head;
			if(doc->versions->head!=NULL){
				while(tempA!=NULL){
						dbnode *dbt=tempA->value;
						dll *tprop=newDLL(NULL);
						dllnode *tempB=dbt->data->head;
						while(tempB!=NULL){
							properties *p=tempB->value;
							insertDLL(tprop,sizeDLL(tprop),newProperties(getPropVal(p),getPropName(p)));
							//fprintf(f, "%s: %d ",getPropName(p),getPropVal(p));
							tempB=tempB->next;	
						}
						if(!findDOCNode(og, getDocNodeID(doc))) { //search in DLL for docID
			                dll *vprop=newDLL(NULL);
			                insertDLL(vprop,sizeDLL(vprop),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                insertDLL(og,sizeDLL(og),newDocNode(getDocNodeID(doc),1,vprop));
			                tprop=newDLL(NULL);
			            }
			            else{
			            	docnode *dNode=findDOCNode(og,getDocNodeID(doc));
			            	if(!findDBNode(dNode, getDBNodeVer(dbt))) { //search in DLL for docID
			                	insertDLL(dNode->versions,sizeDLL(dNode->versions),newDBNode(getDBNodeVer(dbt),getDBNodeSys(dbt),tprop));
			                	tprop=newDLL(NULL);
			            	}
			            }
					tempA=tempA->next;	
				}
			}
			tempN=tempN->next;	
		}
	}
}