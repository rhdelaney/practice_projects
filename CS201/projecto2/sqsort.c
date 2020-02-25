#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "integer.h"
#include "queue.h"
#include "stack.h"
#include "comparator.h"
#include "readin.h"
#include "real.h"
#include "string.h"

typedef void (*Printer)(FILE*,void*);

Comparator comp;
Reader read;
Printer print;
FILE *fp;

void sqsort(queue *inputq, Comparator c, Printer p) {
     queue *outputq = newQueue(p);
     //queue *tempq=newQueue(p);
     stack *s = newStack(p);
     void *temp = NULL;
     void *anotha1 = NULL;
     int passes = 0;
    while (1) {
        void *lastQ = NULL;
        int sorted = 1;
        queue *tempq = inputq;
        int changes = 0;
        while (sizeQueue(inputq) > 0) {  // while inputQueue != 0
            //tempq=inputq;
            if (sizeStack(s) > 0 && c(peekStack(s),peekQueue(inputq)) > 0) {
                temp = pop(s);
                if (lastQ != NULL) {
                    if (c(temp, lastQ) > 0) {
                        sorted = 0;
                    }
                }
                enqueue(outputq,temp);
                lastQ = temp;
                changes++;
                //printf("first juan\n");
                continue;
            }
            anotha1 = dequeue(inputq);
            if (sizeQueue(inputq) == 0 || c(anotha1,peekQueue(inputq)) >= 0) {
                if (lastQ != NULL) {
                    if (c(anotha1,lastQ) > 0) {
                        sorted = 0;
                    }
                }
                enqueue(outputq,anotha1);
                lastQ = anotha1;
                changes++;
            }
            else {
                push(s,anotha1);
                changes++;
            }

        }
/*        if(sizeStack(s)==0 && sorted==1){
            if(tempq==outputq){
                //printf("breaking here?\n");
                break;
            }
            else if(passes==0){
                displayQueue(stdout, outputq);
                printf("\n");
            }
            break;
        }*/
            while (sizeStack(s) > 0) { enqueue(outputq,pop(s));}
            displayQueue(stdout,outputq);
            printf("\n");
            tempq = inputq;
            inputq = outputq;
            outputq = tempq;
        if (sizeStack(s) == 0 && sorted == 1) {
            if (tempq == outputq){
                //printf("breaking here?\n");
                break;
            }
            else if (passes == 0) {
                displayQueue(stdout, outputq);
                printf("\n");
            }
            break;
        }
        passes++;
    }
}

int main( int argc, char *argv[]) {
    if (argc == 2) {
        fp = stdin;
        switch(argv[1][1]) {
            case 'd':
                print = displayInteger;
                read = readIntegers;
                comp = intComparator;
                break;
            case 'r':
                comp = realComparator;
                read = readReals;
                print = displayReal;
                break;
            case 's':
                comp = stringComparator;
                read = readStrings;
                print = displayString;
                break;
            case 'v':
                printf("Raychel Delaney\n");
                exit(1);
            default:
                printf("Unknown value '%c' , valid flags are -d, -r, -s, and -v",argv[1][1]);
                exit(1);
            }
        }
    if (argc == 3) {
        fp = fopen(argv[2], "r");
        switch(argv[1][1]) {
            case 'd':
                print = displayInteger;
                read = readIntegers;
                comp = intComparator;
                break;
            case 'r':
                comp = realComparator;
                read = readReals;
                print = displayReal;
                break;
            case 's':
                comp = stringComparator;
                read = readStrings;
                print = displayString;
                break;
            case 'v':
                printf("Raychel Delaney\n");
                exit(1);
            default:
                printf("Unknown value '%c' , valid flags are -d, -r, -s, and -v",argv[1][1]);
                exit(1);
            }
        }
    queue *input = newQueue(print);
    //stack *stack = newStack(print);
    //queue *output = newQueue(print);
    read(input, fp);
    displayQueue(stdout, input);
    printf("\n");
    sqsort(input, comp, print);
    //displayQueue(stdout,input);
    //printf("\n");
    return 0;
}
