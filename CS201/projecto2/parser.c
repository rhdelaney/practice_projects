#include "parser.h"

void clnStr(char *s) {
     int o = 0; //original gangsta string
     int n = 0; //that new new gansta vibe string it's lit fam
     while (s[o] != '\0') { // Loop until we hit the null character in the string.
          if (isspace(s[o])) { // give me someeee space or nah?
               while (isspace(s[o]) || ispunct(s[o]) || isdigit(s[o])) { // Skip dat whitespace y invalid chars
                    ++o;
               }
               s[n]=' ';// leave a single space like a kisss gb
               ++n;
               //printf("In space: %s\n", s);
          }
          else if (!isalpha(s[o])) { // punct or digit -> skip
               ++o;
               //printf("In punct or digit: %s\n", s);
          }
          else if (isupper(s[o])) {
               s[n] = tolower(s[o]); // uppercase->lowercase.
               ++n;
               ++o;
               //printf("in up to low: %s\n", s);
          }
          else if (o == n) { //if sameiez, inc
               ++o;
               ++n;
               //printf("In else if same: %s\n", s);
          }
          else {
               s[n] = s[o]; //Copy lol just noticed sog is like british slang lol
               ++n;
               ++o;
               //printf("In else copy over: %s\n", s);
          }
     }
     s[n] = '\0'; //null like my life
     //printf("%s\n", s);
}

string *grabStr(FILE *fp) {
     char *str;
     if (stringPending(fp)) {
          str = readString(fp);
          if (str == NULL) {
              //printf("%s\n", str);
               return NULL;
          }
          clnStr(str);
          if (!strcmp("",str)) { //used to not be not nots
               //printf("%s\n", str);
               return NULL;
          }
          else {
               //printf("%s\n", str);
               return newString(str);
          }
     }
     else {
          str = readToken(fp);
          if (str == NULL) {
               //printf("%s\n", str);
               return NULL;
          }
          clnStr(str);
          if (!strcmp("",str)) { //used to not be nots
               //printf("%s\n", str);
               return NULL;
          }
          else {
               //printf("if it's you I'm fucked");
               //printf("%s\n", str);
               return newString(str);
          }
     }
}
