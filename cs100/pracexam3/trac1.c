#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
 int max = atoi(argv[1]);
 int a, b;
 for (a=0; a<max; a++) {
 for (b=0; b<=a; b++)
 printf("%d", a);
 printf("\n");
 }
 return 0;
}
