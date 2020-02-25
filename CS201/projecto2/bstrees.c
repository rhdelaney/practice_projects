#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "bst.h"
#include "vbst.h"
#include "rbt.h"
#include "comparator.h"
#include "string.h"
#include "real.h"
#include "integer.h"
#include "parser.h"
#include "queue.h"
#include "sll.h"

void readCorpusV(vbst *tree, FILE *fp) {
    string *s = grabStr(fp);
    while(s != NULL || !feof(fp)) {
        if(s != NULL) { //&& !findVBST(tree, str) maybe noooottttt lol this is why i got no freqqq-ing frequency
            insertVBST(tree, s);
            //printf("%s\n", getString(s));
        }
        s=grabStr(fp);
    }
  //printf("finished Corpus");
}
void readCorpusR(rbt *tree, FILE *fp) {
    string *s = grabStr(fp);
    while(s != NULL || !feof(fp)) {
        if(s != NULL) { //&& !findRBT(tree, str) lol plz give me a treee thx homie
            insertRBT(tree,s);
            //continue;
        }
        //else{}
        s = grabStr(fp);
    }
}
void readCommands(queue *q, FILE *fp) {
    string *s = grabStr(fp);
    while(s!= NULL || !feof(fp)) {
    //printf("we wilding in this while\n");
        if(s== NULL) {
            enqueue(q, NULL);
        }
        else{
            enqueue(q,s);
        }
        s=grabStr(fp);
    //printf(" how about after ");
    }
  //printf("we left commands function");
}

int main(int argc, char **argv) {
    //printf("In Main:\n");
    if(argc!=4 && argc!=5) {
        //fprintf(stderr, "Invalid # of command arguments.\n");
        exit(-1);
    }  
    FILE *corpus = fopen(argv[2], "r");
    FILE *commands = fopen(argv[3], "r");
    FILE *fp;
    if(argc == 5){
        fp = fopen(argv[4], "w");
    }
    else{
        fp = stdout;
    }
    queue *q = newQueue(displayString);
    //printf("we are here huh?");
    readCommands(q, commands);
    //printf("made a queue right?\n");
    //printf("read some commands in plz?\n");
    //Gather and process command-line args.
    if(argv[1][1]=='v'){
        //printf("I'm in the v level rn\n");
        // Read the corpus.
        //queue *q = newQueue(displayString);
        //printf("we are here huh?");
        //readCommands(q, commands);
        vbst *tree = newVBST(displayString, stringComparator);
        readCorpusV(tree, corpus);
        while(sizeQueue(q)) {
           //printf("i'm in the while atm\n");
            char command = getString(dequeue(q))[0];
            switch(command) {
                case 'i':{
                    //printf("we are in insert V");
                    string *str = dequeue(q);
                    if(str == NULL){
                        break;
                    }
                    char *s = getString(str);
                    clnStr(s);
                    setString(str, s);
                    insertVBST(tree, str);
                    break;}
                case 'd':{ 
                    //printf("we are breaking here specifically");
                    string *str = dequeue(q);
                    /*char *s = getString(str);
                    clnStr(s);
                    setString(str, s);*/
                    /*int count=findVBST(tree, str);
                    if(count==0) {
                        fprintf(stderr, "Value ");
                        displayString(stderr, str);
                        fprintf(stderr, " not found.\n");
                        break;
                    }*/
                    deleteVBST(tree, str);
                    break;}
                case 'f':{
                //frequency
                    //printf("In frequency\n");
                    string *str = dequeue(q);
                    /*char *s = getString(str);
                    clnStr(s);
                    setString(str, s);*/
                    fprintf(fp,"Frequency of \"%s\": %d\n",getString(str),findVBST(tree,str));
                    break;}
                case 's':{ 
                    //printf("show dat tree\n");
                    displayVBST(fp, tree);
                    break;}
                case 'r':{ 
                //report stats
                    //printf("in stats\n");
                    statisticsVBST(tree,fp);
                    break;}
            }
        }
    }
    if(argv[1][1]=='r'){
        //red-black //For RBT
        //queue *q = newQueue(displayString);
        //readCommands(q, commands);
        rbt *tree = newRBT(displayString, stringComparator);
        readCorpusR(tree, corpus);
        while(sizeQueue(q)) {
            char command = getString(dequeue(q))[0];
            switch(command) {
                case 'i':{
                    string *str = dequeue(q);
                    if(str == NULL){ 
                        break;
                    }
                    char *s = getString(str);
                    clnStr(s);
                    setString(str, s);
                    insertRBT(tree, str);
                    break;}
                case 'd':{ //not in use atm
                    string *str = dequeue(q);
                    deleteRBT(tree, str);
                    break;}
                case 'f':{
                //frequency
                    string *s = dequeue(q);
                    fprintf(fp,"Frequency of \"%s\": %d\n",getString(s),findRBT(tree,s));
                    break;}
                case 's':{ 
                    //show tree
                    displayRBT(fp, tree);
                    break;}
                case 'r':{ 
                    //report stats
                    statisticsRBT(tree,fp);
                    break;}
            }
        }
    }
    // close files.
    fclose(corpus);
    fclose(commands);
    if(argc == 5){
        fclose(fp);
    }
    return 0;
}