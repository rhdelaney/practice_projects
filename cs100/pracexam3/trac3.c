#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
 char *str;
 int len = strlen(argv[1]);
 char *s = argv[1];
 str = malloc( sizeof(char) * len * 2 );
 int x;
 for (x = 0; x < len; x++)
 str[x] = s[x];
 for (x = 0; x < len-1; x++)
 str[len+x] = s[len-2-x];
 str[len*2] = '\0';
 printf("%s and %d and %s\n", argv[1],len,str);
 return 0;
}
