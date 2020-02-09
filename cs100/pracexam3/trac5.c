#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
 int a, b, num = atoi(argv[1]);
 int **m;
 m = malloc( sizeof(int *) * num );
 for (a=0; a<num; a++)
 m[a] = malloc( sizeof(int) * num);
 for (a=0; a<num; a++)
 for (b=0; b<num; b++)
 m[a][b] = (a+1) * (b+1);
 printf(" ");
 for (a=0; a<num; a++)
 printf("%3d", a);
 printf("\n");
 printf(" +");
 for (a=0; a<num; a++)
 printf("---");
 printf("\n");
 for (a=0; a<num; a++) {
 printf("%3d |", a);
 for (b=0; b<num; b++)
 printf("%3d", m[a][b]);
 printf("\n");
 }
 return 0;
}
