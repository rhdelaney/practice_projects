#include <stdio.h>
#include <string.h>
#include <ctype.h>
void function(char *str) {
 int x;
 for (x=0; x<strlen(str); x++) {
 char ch = str[x]; //ch is the letter
 if ( isalpha(ch) ){
 if ( islower(ch) ) str[x] = toupper(ch);
 else {str[x] = tolower(ch);}}
}
 return;
}
int main(int argc, char *argv[]) {
 int a;
 for (a = 1; a < argc; a++)
 { function(argv[a]); printf("%s\n", argv[a]); }
 return 0;
}
