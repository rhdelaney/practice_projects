#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <ctype.h>
#include "dll.h"
#include "db.h"
#include "scanner.h"

int main() {
    FILE *data = fopen("data.txt", "r");
    FILE *queries = fopen("queries.txt", "r");
    FILE *rhd=fopen("rhdelaney.txt","w");
    //collection needs to be named "FINAL"
    dll *final =newDLL(NULL);
    int docID=0;
    int value=0;
    int v=0;
    char *name, *fin;
    char *field, *command;
    char dummy;
    char *operator;
    name=readToken(data);
    int index=1;
    dll *tprop=newDLL(NULL);
    //int tpropMade=0;
    while(!feof(data)){
        if(strcmp(name,"DocID")==0){
            dummy=readChar(data);
            docID=readInt(data);
        }
        else{
            dummy=readChar(data);
            value=readInt(data);
            insertDLL(tprop,0,newProperties(value,name));
        }
        dummy=fgetc(data);
        if(dummy=='\n'){
            if(!findDOCNode(final, docID)){ //search in DLL for docID
                dll *vprop=newDLL(NULL);
                insertDLL(vprop,0,newDBNode(1,index,tprop));
                insertDLL(final,0,newDocNode(docID,1,vprop));
                index++;
                tprop=newDLL(NULL);
            }
            else{
                docnode *dNode=findDOCNode(final,docID);
                dNode->numVersions=(dNode->numVersions) + 1;
                insertDLL(dNode->versions,0,newDBNode(dNode->numVersions,index,tprop));
                index++;
                tprop=newDLL(NULL);
            }
        }
        else{
            ungetc(dummy,data);
        }
        name=readToken(data);
        if(name==NULL){
            if(!findDOCNode(final, docID)){
                dll *vprop=newDLL(NULL);
                insertDLL(vprop,0,newDBNode(1,index,tprop));
                insertDLL(final,0,newDocNode(docID,1,vprop));
                index++;
                break;
            }
            else{
                docnode *dNode=findDOCNode(final,docID);
                dNode->numVersions=(dNode->numVersions) + 1;
                insertDLL(dNode->versions,0,newDBNode(dNode->numVersions,index,tprop));
                index++;
                break;
            }
        }
    }
    //dll *fields=newDLL(NULL);
    //fprintf(rhd,"Current DB: \n\n");
    //printValues(final,rhd,final,1);
    //fprintf(rhd,"\n");
    int con=0;
    int fie=0;
    int ver=0;
    int num=0;
    while(!feof(queries)) {
        fin=readTokenQ(queries); //final
        dummy=readChar(queries); //period
        command=readTokenQ(queries); //query,sort,insert,
        if(strcmp(fin,"final")==1){
            fin=readLine(queries);
            printf("This is an incorrect statement\n");
        }
        else if(strcmp(command,"query")==0){
            con=1;
            fie=1;
            ver=1;
            v=1;
            num=0;
            dll *fields=newDLL(NULL);
            //printf("in query\n");
            dummy=readChar(queries); //open paren
            dummy=readChar(queries); // open bracket/closed paren
            if(dummy!=')'){
                dummy=fgetc(queries);
                //dll *nFinal=final;
                dll *nFinal=newDLL(NULL);
                dll *tfields=newDLL(NULL);
                while(dummy!=']'){ //all [field=value, ], [fieldsToPrint], [versionToPrint]
                    if(dummy!=','){ //if it isn't a , put the val back if it is a comma get rid of it
                        ungetc(dummy,queries);
                    }
                    field=readTokenQ(queries);
                    //printf("field= %s ",field );
                    operator=readTokenI(queries);
                    //printf("operator= %s", operator);
                    value=readInt(queries);
                    con=0;
                    //printf(" Value= %d\n",value);
                    //nFinal=query(nFinal,field,operator,value,num);
                    dummy=fgetc(queries);
                    if(dummy==']'){
                        if(num==0){
                            //nFinal=query(nFinal,field,operator,value,num);
                            nFinal=query(final,field,operator,value,num);
                            break;
                        }
                        insertDLL(tfields,0,newQNode(field,operator,value));
                        nFinal=multiQ(final,tfields);
                        //unionDB(nFinal,temp); 
                        //nFinal=query(nFinal,field,operator,value,num);
                        break;
                    }
                    insertDLL(tfields,0,newQNode(field,operator,value));

                    num++;
                    //nFinal=query(nFinal,field,operator,value,num);
                    //temp=query(final,field,operator,value,num);
                    //unionDB(nFinal,temp);  
                }
                //printf("I'm out\n");
                dummy=readChar(queries); //comma
                //printf("dummy char comma %c\n",dummy );
                dummy=readChar(queries); //open bracket
                //printf("dummy char after comma %c\n",dummy);
                dummy=fgetc(queries);
                while(dummy!=']'){ //while loop to grab all the fields
                    if(dummy!=','){ //if not a comma you want to ungetc the token
                        ungetc(dummy,queries);
                    }
                    field=readTokenQ(queries); //get the field to print
                    //printf("field = %s\n",field);
                    insertDLL(fields,0,field); //insert field into dll to send into printVals
                    //printf("after dll insert\n");
                    fie=0;
                    dummy=fgetc(queries);
                    if(dummy==']'){
                        break;
                    }
                }
                //printf("ovaaa here\n");
                dummy=readChar(queries); //comma or bracket
                if(dummy==','){ 
                    //printf("in here?\n");
                    dummy=readChar(queries);//bracket
                    dummy=fgetc(queries);
                    if(dummy!=']'){
                        ungetc(dummy,queries);
                        //printf("in here-er?\n");
                        v=readInt(queries); //vNum
                        //printf("ver= %d\n",v);
                        ver=0;
                        dummy=readChar(queries); //bracket
                    }
                    //printf("in here-er?\n");
                    dummy=readChar(queries); //paren
                    //printf("paren? %c\n",dummy );
                }
               /* fprintf(rhd,"\ndisplaying DLL:\n");
                dllnode *f=fields->head;
                while(f!=NULL){
                    fprintf(rhd, "%s ",f->value);
                    f=f->next;
                }*/
                //fprintf(rhd,"\nQuerying with this DLL:\n");
                if(con && fie && ver){ //never entered any
                    fprintf(rhd,"\n\nQueried Values");
                    printAllValues(final,rhd);
                }
                else if(con && fie && !ver){//never entered condition or fields but entered version
                    //never got conditions or fields to print-> all of those for
                    //a specific versions
                    //fprintf(rhd, "All fields and conditions for a version\n");
                    fprintf(rhd,"\n\nQueried Values");
                    printAllValuesVer(nFinal,rhd,v);
                }
                else if(con && !fie && !ver){//didnt enter conditions but did enter field/ver
                    fprintf(rhd,"\n\nQueried Values");
                    printValues(final,rhd,fields,v);
                }
                else if(!con && !fie && ver){ //entered con and fie but not ver-> current
                    fprintf(rhd, "\n\nQueried Values");
                    printValues(nFinal,rhd, fields,1);
                }
                else{
                    //fprintf(rhd,"\nPrint fielded Values\n");
                    /*if(){
                        printValuesAllVers(final,rhd,fields,v);
                    }*/
                    fprintf(rhd,"\n\nQueried Values");
                    printValues(nFinal,rhd,fields,v);
                }
            }
            else{
                //case where final.query()
                //fprintf(rhd,"All Current Values\n");
                fprintf(rhd,"\n\nQueried Values\n");
                printAllCurrValues(final,rhd);
            }
            con=1;
            fie=1;
            ver=1;
        }
        //in progress....count can work for ([field]) ([field],[]) (what)
        else if(strcmp(command,"count")==0){
            //printf("in count\n");
            //COUNT CURRENTLY IS STRUGGLING WITH VERSION LIMITATIONS
            v=0;
            ver=0;
            dummy=readChar(queries);//paren
            dummy=readChar(queries);//open bracket
            field=readTokenQ(queries); //fieldName
            //printf("field %s\n",field);
            dummy=readChar(queries); //closed bracket
            dummy=readChar(queries);//possible paren or comma
            if(dummy==','){ //comma?
                dummy=readChar(queries);// open bracket
                dummy=fgetc(queries);
                if(dummy!=']'){
                    ungetc(dummy,queries);
                    v=readInt(queries); //vNum
                    //printf("ver= %d\n",v );
                    dummy=readChar(queries); //bracket
                    ver=1;
                }
                dummy=readChar(queries); //paren
                if(ver!=1){
                    //fprintf(rhd, "count all print out\n");
                    fprintf(rhd,"\n\nCount:\n%s : %d\n", field ,countAll(final,field));
                }
                else{
                    //fprintf(rhd, "count ver specific print out\n");
                    fprintf(rhd,"\n\nCount:\n%s : %d\n", field ,count(final,field, v));
                }
            }
            else{
                //fprintf(rhd, "count current print out\n");
                fprintf(rhd,"\n\nCount:\n%s : %d\n", field ,countCurr(final,field));
            }
            //count(final,field,v);
            v=0;
            ver=0;
        }
        else if(strcmp(command,"sort")==0){
            int all=0;
            v=0;
            //printf("in sort\n");
            dummy=readChar(queries); //read in paren
            dummy=readChar(queries); //read in bracket
            field=readTokenQ(queries); //field name
            //printf("field %s\n",field);
            dummy=readChar(queries); //read in end bracket
            dummy=readChar(queries); //read in end paren?
            if(dummy==','){  //or comma
                dummy=readChar(queries);//bracket
                dummy=fgetc(queries); //either number or end bracket
                if(dummy!=']'){
                    ungetc(dummy,queries);
                    v=readInt(queries); //vNum -> number of versions to print
                    //printf("ver= %d\n",v );
                    dummy=readChar(queries); //end bracket 
                }
                else if (dummy==']'){
                    all=1;
                }
                dummy=readChar(queries); //end paren
                if(all){ //case of sorting w/ empty brackets
                    fprintf(rhd, "\nSort by - %s\n",field);
                   //nFinal=sort(final,field);
                   //printAllValues(final,rhd);
                    sortAll(final,rhd,field);
                }
                else{
                    fprintf(rhd, "\nSort by - %s\n",field);
                    //sort x many versions
                    //nFinal=sort(final,field);
                    //need to change this to only print x many versions all values
                    //printAllCurrValues(final,rhd);
                    sortX(final,rhd,field,v);
                }
            }
            else{
                fprintf(rhd, "\nSort by - %s\n",field);
                sortC(final,rhd,field);
                //sort only current version
                //nFinal=sort(final,field);
               //printAllCurrValues(final,rhd);
            }
            //fprintf(rhd, "attempt to sort....\n");
            //sortC(final,rhd, field);
        }
        else if(strcmp(command,"insert")==0){
           // printf("in insert\n");
            dummy=readChar(queries); 
            final=insert(final,queries,index);
            index++;
            //dummy=readChar(queries);
            //printValues(final,rhd,final,1);
        }
        else{ 
            printf("This is an incorrect command\n");
            fin=readLine(queries);
            fin=readTokenQ(queries);
            if(fin==NULL){
                break;
            }
            else{
                command=readTokenQ(queries);
            }
        }
        //fix how to exit this loop :(
        dummy=fgetc(queries);
        if(dummy!='\n'){
           break; 
        }
        ungetc(dummy,queries);
    }
    // printValues(final,rhd,fields,v);
    // close files.
    fclose(data);
    fclose(queries);
    fclose(rhd);
    return 0;
}