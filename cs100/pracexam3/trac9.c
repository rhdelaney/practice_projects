#include <stdio.h>
#include <string.h>
int function(char *str, char ch) {
 if (*str == '\0') return 0;
 if (*str == ch) return 1 + function(str+1, ch);
 return function(str+1, ch);
}
int main(int argc, char *argv[]) {
 char s[8] = "alabama";
 printf("%d for a\n", function(s, 'a'));
 printf("%d for b\n", function(s, 'b'));
 printf("%d for c\n", function(s, 'c'));
 return 0;
}
