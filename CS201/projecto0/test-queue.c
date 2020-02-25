#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "sll.h"
#include "integer.h"
#include "queue.h"

static void showItems(queue *items)
{
    printf("The items are ");
    displayQueue(stdout,items);
    printf(".\n");
}

int main(){ //int argc,char **argv
    
    //this is going to create two stacks
    printf("Creating queues: \n");
    queue *stack1 = newQueue(displayInteger);
    queue *stack2 = newQueue(displayInteger);
    printf("Finished! \n");
    // pushing 10 numbers into each
    printf("Filling the 2 stacks with 0-9 and 10\n");
    for( int i = 0; i < 10; i++) {
        enqueue(stack1, newInteger(i));
        enqueue(stack2, newInteger(i + 10));
    }
    printf("--------------------------------------------------- \n");
    printf("Below is stack1 and stack 2 respectively, \n");
    printf("They should appear as [0,1,2,3,4,5,6,7,8,9] and [10,11,12,13,14,15,16,17,18,19] \n");
    showItems(stack1);
    showItems(stack2);
    
    // at this point both stack are filled with 10 numbers each. Time to remove from them and peek.
    printf("The size of stack1 is: %d", sizeQueue(stack1));
    printf(" \n");
    printf("The size of stack2 is: %d", sizeQueue(stack2));
    printf(" \n");
    
    printf("--------------------------------------------------- \n");
    //printf("PeekStack1: %d", peekStack(stack1));
    //printf("PeekStack2: %d", peekStack(stack2));
    printf("Dequeue from both queues: \n");
    for( int i = 0; i < 5; i++) {
        dequeue(stack1);
        dequeue(stack2);
    }
    showItems(stack1);
    showItems(stack2);
    
    return 0;
}
