/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int getpagesize(void);

int main(void){
    const int x = getpagesize() + 1;
    //printf( "%d", x);
    int i, j;
    int *m=(int *)malloc(x*x*sizeof(int));
    int nextchar;
    printf("Matrix allocated\nPress enter to continue");
    while((nextchar=getchar())!='\n');
    //sprintf(commandBuffer, "top -b -n $d\n", getpid());
    //system(commandBuffer);

    for(i=0;i<x;i++){
    	for(j=0;j<x;j++){
    		*(m+i*x+j)=random()%10;
    	}
    }
    printf("Matrix filled\nPress enter to continue");
    while((nextchar=getchar())!='\n');
    
    free(m);
    
    printf("Matrix freed\nPress enter to continue");
    while((nextchar=getchar())!='\n');
    p->
    value=random();
    m[i][j]=p->value;
    free(p);
}*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main()
{
 //const char *commandBuffer = "top -b -n $d\n, getpid()";
 const int x = getpagesize() + 1;
 printf("%d\n", x-1);
 printf("%d\n", getpid());
    int *arr = (int *)malloc(x * x * sizeof(int));
    int pid = getpid();
    printf("%d", pid);

    char commandBuffer[80];

    sprintf(commandBuffer, "top -n %d\n", getpid());
    system(commandBuffer);
    int i, j; //count = 0;
    int *idxptr= (int *)arr;
    for (i = 0; i <  x; i++)
      for (j = 0; j < x; j++)
         *idxptr++ = random()%10;
    system(commandBuffer);
    //print loops to ensure that the array was filled
    //for (i = 0; i <  x; i++)
     // for (j = 0; j < x; j++)
      //   printf("%d ", *(arr + i*x + j));
   free(arr);
    system(commandBuffer);
   return 0;
}