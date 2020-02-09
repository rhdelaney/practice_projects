#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
 int a, num, total = 0;
 for (a=0; a<argc; a++) {
 num = strlen(argv[a]);
 total += num;
 printf("%s and %d and %d\n",
 argv[a], num, total);
 }
 return 0;
}
