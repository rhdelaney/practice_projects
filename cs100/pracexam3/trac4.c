#include <stdio.h>
#include <stdlib.h>
int funct(int num) {
 if (num == 7 || num == -7) return 1;
 if (num <= 0) return 0;
	printf("%d ",num);
 return funct( (num / 10) - 2 * (num % 10) );
}
int main(int argc, char *argv[]) {
 int a, n;
 for (a=1; a<argc; a++) {
 n = atoi(argv[a]);
 if ( funct(n) )
 printf("%d - answer is yes\n", n);
 else
 printf("%d - answer is no\n", n);
 }
 return 0;
}
