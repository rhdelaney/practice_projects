#include "parser.h"

static char *clnStr(char *s){
     if (s == 0){
          return "";
     }
     else if (strlen(s) == 0){
          return "";
     }

     char temp[strlen(s)];
     unsigned int i;
     unsigned int count = 0, prevSpace = 0;
     for (i = 0; i < strlen(s); i++){
          if (isalpha(s[i])) {
               temp[count] = tolower(s[i]);
               prevSpace = 0;
               count++;
          }
          else if (isspace(s[i]) && !prevSpace){
               temp[count] = ' ';
               prevSpace = 1;
               count++;
          }
     }
     if (count == 0){
          return "";
     }
     char *t = malloc(sizeof(char) * (count + 1));
     if (t == 0){
          fprintf(stderr, "Out of memory\n");
     }
     for (i = 0; i < count; i++){
          t[i] = temp[i];
     }
     t[count] = '\0'; //insert null character
     return t;
}

string *grabStr(FILE *fp){
     char *str;
     if(stringPending(fp)){
          str=readString(fp);
          // EOF
          if(str==NULL){
               return NULL;
          }
          clnStr(str);
          if(strcmp("",str)==0){ //used to be nots
               return NULL;
          }
          else{
               return newString(str);
          }
     } 
     else{
          str=readToken(fp); // EOF
          if(str==NULL){ 
               return NULL;
          }
          clnStr(str);
          if(strcmp("", str)==0){ //used to be nots
               return NULL;
          }
          else{
               //printf("if it's you I'm fucked");
               return newString(str);
          }
     }
}