#ifndef __DB_INCLUDED__
#define __DB_INCLUDED__
#include "dll.h"

typedef struct qNode{
	char *fieldN;
	char *op;
	int val;
} qNode;
typedef struct properties{
    int val;
    char *name;
    //struct properies *next;
} properties;

typedef struct dbnode{
    int version;
    int sysid;
    dll *data;
} dbnode;

typedef struct docNode{
    int docID;
    int numVersions;
    dll *versions;  
} docnode;

//gets props
extern int getPropVal(properties *);
extern char *getPropName(properties *);
//gets dbnode
extern int getDBNodeVer(dbnode *);
extern int getDBNodeSys(dbnode *);
extern dll *getDBNodeData(dbnode *);
//gets docnode
extern int getDocNodeID(docnode *);
extern int getDocNodeNumVer(docnode *);
extern dll *getDocNodeVers(docnode *);
//new functions
extern properties *newProperties(int val, char *name);
extern qNode *newQNode(char *field,char *op,int val);
extern dbnode *newDBNode(int version,int sysid,dll *data);
extern docnode *newDocNode(int docID, int numVersions,dll *versions);
extern void *findDOCNode(dll *node,int ID);
extern void *findDBNode(docnode *node,int ID);
//query functions
extern dll *lessThan(dll *items, char *field, int value, int numQ);
extern dll *greaterThan(dll *items, char *field, int value, int numQ);
extern dll *equalTo(dll *items, char *field, int value, int numQ);
extern dll *lessOEqual(dll *items, char *field, int value, int numQ);
extern dll *greaterOEqual(dll *items, char *field, int value, int numQ);
extern dll *notEqual(dll *items, char *field, int value, int numQ);
extern dll *query(dll *final,char *field,char *oper,int val, int numQ);
//sort functions
extern void sortC(dll *final, FILE *rhd, char *field);
extern void sortAll(dll *final,FILE *rhd, char *field);
extern void sortX(dll *final, FILE *rhd,char *field, int v);
//count functions
extern int count(dll *final,char *field,int ver);
extern int countCurr(dll *final, char *field);
extern int countAll(dll *final, char *field);
//insert function
extern dll *insert(dll *final, FILE *f, int index);
//print functions
extern void printValues(dll *items, FILE *f,dll *fields,int versions);
extern void printAllValues(dll *items, FILE *f);
extern void printCurrValues(dll *items, FILE *f, dll *fields);
extern void printAllCurrValues(dll *items, FILE *f);
extern void printAllValuesVer(dll *items, FILE *f, int versions);
//Union
extern void unionDB(dll *og, dll *added);
//fuck
extern int equalToQ(docnode *doc,dbnode *db, char *field, int value);
extern int greaterThanQ(docnode *doc,dbnode *db, char *field, int value);
extern int lessThanQ(docnode *doc,dbnode *db, char *field, int value);
extern int lessOEqualQ(docnode *doc,dbnode *db, char *field, int value);
extern int greaterOEqualQ(docnode *doc,dbnode *db, char *field, int value);
extern int notEqualQ(docnode *doc,dbnode *db, char *field, int value);
extern dll *multiQ(dll *items,dll *qList);














#endif