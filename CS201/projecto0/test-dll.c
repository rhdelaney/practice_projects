#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "dll.h"
#include "integer.h"


static void showItems(dll *items){
  printf("The items are ");
  displayDLL(stdout,items);
  printf(".\n");
}

int main(){ //int argc,char **argv
  dll *items = newDLL(displayInteger);
  dll *donkey = newDLL(displayInteger);
  insertDLL(donkey,0,newInteger(100));
  insertDLL(donkey,1,newInteger(101));
  insertDLL(donkey,2,newInteger(102));
  insertDLL(donkey,3,newInteger(103));

  //main statement
  //printf("But definitely not here right?\n");
  printf("\n \n");
  printf("\n-------------------------------------------------------------- \n \n");
  printf("DLL testing main.c! \n");
  printf("This will test all functions multiple times as well as adding and removing from a unioned list. \n");
  printf("\n-------------------------------------------------------------- \n \n");
  printf("Adding elements now: \n \n");
  //for loops for adding first 10 numbers
  for( int i = 0; i<5; i++){
    printf("Adding: %d",i);
    printf(" to the head \n");
    insertDLL(items,0,newInteger(i));               //insert 0-4 items at head
  }
  printf("\n");
  for( int i = 5; i < 10; i++) {
    insertDLL(items,sizeDLL(items),newInteger(i));      //insert at back
    printf("Adding: %d",i);
    printf(" to the tail \n");
  }
  printf("\n-------------------------------------------------------------- \n \n");
           
  printf("\n");
  printf("The line below should be [4,3,2,1,0,5,6,7,8,9] \n");
  showItems(items);
  printf(" \n");
  printf("\n-------------------------------------------------------------- \n \n");

  //adding at random index
  printf("Adding 11,12,13,14 at index 1,4,7,8 respectively: \n");
  printf("\n");
           
  insertDLL(items,1,newInteger(11));                   //insert at one after head
  insertDLL(items,4,newInteger(12));                   //insert at 4
  insertDLL(items,7,newInteger(13));                   //insert at 7
  insertDLL(items,8,newInteger(14));                   //insert at 8
  // verifying data was input right
  printf("The line below should should look like [4,11,3,2,12,1,0,13,14,5,6,7,8,9] \n");
  showItems(items);
  printf("\n-------------------------------------------------------------- \n \n");
//removing data at head and tail
  printf("Removing head twice, then tail twice, then index 3,5,5,1 and then head and tail again: \n");
  printf("\n");
           
  showItems(items);
  printf(" \n");
           
  printf("The value ");
  displayInteger(stdout,removeDLL(items,0));          //remove from front
  printf(" was removed.\n");
           
  printf("\n");

  showItems(items);
  int x = getInteger((integer *) getDLL(items,0));    //get the first item
  printf("The first item is %d.\n",x);
 
 printf("The value ");
 displayInteger(stdout,removeDLL(items,0));          //remove from front
 printf(" was removed.\n");

 printf("\n");

 showItems(items);
 x = getInteger((integer *) getDLL(items,0));    //get the first item
 printf("The first item is %d.\n",x);
 
 printf("The value ");
 displayInteger(stdout,removeDLL(items,sizeDLL(items)-1));  //remove from tail
 printf(" was removed.\n");
 printf("\n");

 showItems(items);
 x = getInteger((integer *) getDLL(items,sizeDLL(items)-1)); //get the last item
 printf("The last item is %d.\n",x);
 
 printf("The value ");
 displayInteger(stdout,removeDLL(items,sizeDLL(items)-1));  //remove from tail
 printf(" was removed.\n");
 printf("\n");

 showItems(items);
 x = getInteger((integer *) getDLL(items,sizeDLL(items)-1)); //get the last item
 printf("The last item is %d.\n",x);
 printf(" \n");
 printf("Now removing index 3,5,5,1 and head and tail: \n \n");
 
 //removing data at 3,5,5
 showItems(items);
 
 printf("The value ");
 displayInteger(stdout,removeDLL(items,3));  //remove from 3
 printf(" was removed.\n");
 printf("\n");

 showItems(items);
 x = getInteger((integer *) getDLL(items,3)); //get the last item
 printf("The 3rd index is now %d.\n",x);
 
 printf("The value ");
 displayInteger(stdout,removeDLL(items,5));  //remove from 3
 printf(" was removed.\n");
 printf("\n");

 showItems(items);
 x = getInteger((integer *) getDLL(items,5)); //get the last item
 printf("The 5th index is now %d.\n",x);
 
 printf("The value ");
 displayInteger(stdout,removeDLL(items,5));  //remove from 3
 printf(" was removed.\n");
 printf("\n");

 showItems(items);
 x = getInteger((integer *) getDLL(items,5)); //get the last item
 printf("The 5th index is now %d.\n",x);
 
 printf("The value ");
 displayInteger(stdout,removeDLL(items,1));  //remove from 3
 printf(" was removed.\n");
 printf("\n");

 showItems(items);
 x = getInteger((integer *) getDLL(items,1)); //get the last item
 printf("The 1st index is now %d.\n",x);
 
 printf("The value ");
 displayInteger(stdout,removeDLL(items,0));          //remove from front
 printf(" was removed.\n");
 
 printf("\n");

 showItems(items);
 x = getInteger((integer *) getDLL(items,0));    //get the first item
 printf("The first item is %d.\n",x);
 
 printf("The value ");
 displayInteger(stdout,removeDLL(items,sizeDLL(items)-1));  //remove from tail
 printf(" was removed.\n");
 
 printf("\n");

 showItems(items);
 x = getInteger((integer *) getDLL(items,sizeDLL(items)-1)); //get the last item
 printf("The last item is %d.\n",x);
 
 printf("The final list should be [12,0,13,6] \n");
 
 //unioning
 printf("\n-------------------------------------------------------------- \n \n");
 printf("Unioning the last list([12,0,13,6] with a new list([100,101,102,103]): \n \n");
 printf("Recipient: \n");
 showItems(items);
 printf("Donor: \n");
 showItems(donkey);
 
 unionDLL(items, donkey);
 printf("New list: \n");
 showItems(items);
 
 printf("\n-------------------------------------------------------------- \n \n");
 printf("Now removing head, index 1,3,3 and tail: \n \n");
 printf("The list below should be [12,0,13,6,100,101,102,103] \n");
 showItems(items);
 printf("\n");

 printf("The value ");
 displayInteger(stdout,removeDLL(items,0));          //remove from front
 printf(" was removed.\n");
 
 printf("\n");

 showItems(items);
 x = getInteger((integer *) getDLL(items,0));    //get the first item
 printf("The first item is %d.\n",x);
 
 printf("The value ");
 displayInteger(stdout,removeDLL(items,1));          //remove from 1
 printf(" was removed.\n");
 
 printf("\n");

 showItems(items);
 x = getInteger((integer *) getDLL(items,1));    //get the 1st item
 printf("The 1st index is %d.\n",x);
           
  printf("The value ");
  displayInteger(stdout,removeDLL(items,3));          //remove from 3
  printf(" was removed.\n");
           
  printf("\n");

  showItems(items);
  x = getInteger((integer *) getDLL(items,3));    //get the 3rd item
  printf("The 3rd index is %d.\n",x);
           
  printf("The value ");
  displayInteger(stdout,removeDLL(items,3));          //remove from 5
  printf(" was removed.\n");
  printf("\n");

  showItems(items);
  x = getInteger((integer *) getDLL(items,3));    //get the 5th item
  printf("The 5th index is %d.\n",x);
           
  printf("The value ");
  displayInteger(stdout,removeDLL(items,sizeDLL(items)-1));  //remove from tail
  printf(" was removed.\n");
  printf("\n");

  showItems(items);
  x = getInteger((integer *) getDLL(items,sizeDLL(items)-1)); //get the last item
  printf("The last item is %d.\n",x);
  printf("\n");
  showItems(items);

  return 0;
}      
