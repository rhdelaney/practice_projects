#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

int main(int argc, char *argv[]){
        int row=atoi(argv[1]);
        int cols=atoi(argv[2]);
        FILE *fp=fopen("Data2", "r");
        int **m= allocate(sizeof(int *) * row);
        int i;
        int j;
        for(i=0;i<row;i++){
                m[i]= allocate(sizeof(int )*cols);
        }
        int sum=0;
        for(i=0;i<row;i++){
                for(j=0;j<cols;j++){
                        m[i][j]=readInt(fp);
                        if(i==(row-1)){
                                sum+=m[i][j];
                        }
                }
        }
        printf("The sum of the numbers on the last row is %d\n", sum);
        fclose(fp);
        return 0;
}
