#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "dll.h"
#include "integer.h"
#include "stack.h"

static void showItems(stack *items){
  printf("The items are ");
  displayStack(stdout,items);
  printf(".\n");
}

int main(){ //int argc,char **argv
    
    //this is going to create two stacks
    
    printf("Creating stacks: \n");
    stack *stack1 = newStack(displayInteger);
    stack *stack2 = newStack(displayInteger);
    printf("Finished! \n");
    // pushing 10 numbers into each
    printf("Filling the 2 stacks with 0-9 and 10\n");
    for( int i = 0; i < 10; i++) {
        push(stack1, newInteger(i));
        push(stack2, newInteger(i + 10));
    }
    printf("--------------------------------------------------- \n");
    printf("Below is stack1 and stack 2 respectively, \n");
    printf("They should appear as [9,8,7,6,5,4,3,2,1,0] and [19,18,17,16,15,14,13,12,11,10] \n");
    showItems(stack1);
    showItems(stack2);
    
    // at this point both stack are filled with 10 numbers each. Time to remove from them and peek.
    printf("The size of stack1 is: %d", sizeStack(stack1));
    printf(" \n");
    printf("The size of stack2 is: %d", sizeStack(stack2));
    printf(" \n");

    printf("--------------------------------------------------- \n");
    //printf("PeekStack1: %d", peekStack(stack1));
    //printf("PeekStack2: %d", peekStack(stack2));
    printf("Poping from both stacks: \n");
    for( int i = 0; i < 5; i++) {
        pop(stack1);
    }
    showItems(stack1);
    showItems(stack2);
    
    return 0;
}