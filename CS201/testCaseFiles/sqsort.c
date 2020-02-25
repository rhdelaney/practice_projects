#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include "sll.h"
#include "dll.h"
#include "integer.h"
#include "stack.h"
#include "queue.h"
#include "scanner.h"
#include "comparator.h"
#include "real.h"
#include "string.h"
//-d decimal -> integer
//-r real -> double
//-s string ->char
typedef struct sm{
    queue *qinput;
    queue *qoutput;
    stack *s;
} sm;

Sort(SortManager *sm, Comparator comp)
sm is a structure with:
queue *qinput, queue *qoutput, stack *s

int main(int argc, char const *argv[]){
    if(argc==3){
        if(argv[1]=='-d'){

        }
        else if(argv[1]=='-r'){

        }
        else if(argv[1]=='-s'){

        }
        else{
            exit(-1);
        }
    }
    else if(argc==2){

    }
    else if(argc==1){
        if(argv[1]==)
    }
    else{
        exit(-1);
    }
  return 0;
}