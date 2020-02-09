#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
 int max = atoi(argv[1]);
 int a, b;
 for (a=0; a<=max; a++) {
 for (b=0; b<=max; b++)
 if (a != b) printf(".");
 else printf("%d", a);
 printf("\n");
 }
 return 0;
}
