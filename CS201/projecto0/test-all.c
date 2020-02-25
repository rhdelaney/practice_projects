#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include "sll.h"
#include "dll.h"
#include "integer.h"
#include "stack.h"
#include "queue.h"

/*
The items are [].
The items are [3,1,2].
The value 3 was removed.
The items are [1,2].
The first item is 1.
*/
static void showItems(sll *items)
   {
   printf("The items are ");
   displaySLL(stdout,items);
   printf(".\n");
   }

int main(void){
    clock_t start = clock();

printf("\nTESTING #22\n");
dll *a = newDLL(displayInteger);
insertDLL(a,0,newInteger(83));
insertDLL(a,0,newInteger(86));
insertDLL(a,0,newInteger(77));
insertDLL(a,0,newInteger(15));
insertDLL(a,0,newInteger(93));
insertDLL(a,0,newInteger(35));
insertDLL(a,0,newInteger(86));
for (int i = 0; i < 9993; ++i)
{
insertDLL(a,0,newInteger(i));
}
for (int i = 0; i < 10000; ++i)
 {
    insertDLL(a,sizeDLL(a),newInteger(i));
 } 
 for (int i = 0; i < 19980; ++i)
 {
  removeDLL(a,0);
 } 
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
removeDLL(a,0);
displayDLL(stdout,a);

    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTime elapsed in ms: %f", elapsed);
    
clock_t strt = clock();

printf("\n\nTESTING #24\n");
stack *b = newStack(displayInteger);
    push(b,newInteger(86));
    pop(b);
    push(b,newInteger(35));
    push(b,newInteger(92));
    pop(b);
    push(b,newInteger(27));
    push(b,newInteger(59));
    push(b,newInteger(26));
    pop(b);
    push(b,newInteger(36));
    push(b,newInteger(68));
    pop(b);
    push(b,newInteger(30));
    push(b,newInteger(23));
    push(b,newInteger(35));
    push(b,newInteger(2));
    pop(b);
    push(b,newInteger(67));
    push(b,newInteger(56));
    push(b,newInteger(42));
    pop(b);
    pop(b);
    push(b,newInteger(37));
    push(b,newInteger(24));
    push(b,newInteger(70));
    push(b,newInteger(26));
    push(b,newInteger(80));
    push(b,newInteger(73));
    push(b,newInteger(70));
    push(b,newInteger(81));
    displayStack(stdout,b);

clock_t stp = clock();
double elps = (double)(stp - strt) * 1000.0 / CLOCKS_PER_SEC;
printf("\nTime elapsed in ms: %f", elps);

clock_t stt = clock();

printf("\n\nTESTING #25\n");
    stack *c = newStack(displayInteger);
    push(c,newInteger(86));
    pop(c);
    push(c,newInteger(35));
    push(c,newInteger(92));
    pop(c);
    push(c,newInteger(27));
    push(c,newInteger(59));
    push(c,newInteger(26));
    pop(c);
    push(c,newInteger(36));
    push(c,newInteger(68));
    pop(c);
    push(c,newInteger(30));
    push(c,newInteger(23));
    push(c,newInteger(35));
    push(c,newInteger(2));
    pop(c);
    push(c,newInteger(67));
    push(c,newInteger(56));
    push(c,newInteger(42));
    pop(c);
    pop(c);
    push(c,newInteger(37));
    push(c,newInteger(24));
    push(c,newInteger(70));
    push(c,newInteger(26));
    push(c,newInteger(80));
    push(c,newInteger(73));
    push(c,newInteger(70));
    push(c,newInteger(81));
    displayStack(stdout,c);
clock_t st = clock();
double elp = (double)(st - stt) * 1000.0 / CLOCKS_PER_SEC;
printf("\nTime elapsed in ms: %f", elp);
clock_t sr = clock();

printf("\n\nTESTING #26\n");
stack *d = newStack(displayInteger);
    push(d,newInteger(86));
    pop(d);
    push(d,newInteger(35));
    push(d,newInteger(92));
    pop(d);
    push(d,newInteger(27));
    push(d,newInteger(59));
    push(d,newInteger(26));
    pop(d);
    push(d,newInteger(36));
    push(d,newInteger(68));
    pop(d);
    push(d,newInteger(30));
    push(d,newInteger(23));
    push(d,newInteger(35));
    push(d,newInteger(2));
    pop(d);
    push(d,newInteger(67));
    push(d,newInteger(56));
    push(d,newInteger(42));
    pop(d);
    pop(d);
    push(d,newInteger(37));
    push(d,newInteger(24));
    push(d,newInteger(70));
    push(d,newInteger(26));
    push(d,newInteger(80));
    push(d,newInteger(73));
    push(d,newInteger(70));
    push(d,newInteger(81));
    displayStack(stdout,d);
clock_t s = clock();
double e = (double)(s - sr) * 1000.0 / CLOCKS_PER_SEC;
printf("\nTime elapsed in ms: %f", e);

clock_t srat = clock();

printf("\n\nTESTING #27\n");
stack *f = newStack(displayInteger);
    push(f,newInteger(86));
    pop(f);
    push(f,newInteger(35));
    push(f,newInteger(92));
    pop(f);
    push(f,newInteger(27));
    push(f,newInteger(59));
    push(f,newInteger(26));
    pop(f);
    push(f,newInteger(36));
    push(f,newInteger(68));
    pop(f);
    push(f,newInteger(30));
    push(f,newInteger(23));
    push(f,newInteger(35));
    push(f,newInteger(2));
    pop(f);
    push(f,newInteger(67));
    push(f,newInteger(56));
    push(f,newInteger(42));
    pop(f);
    pop(f);
    push(f,newInteger(37));
    push(f,newInteger(24));
    push(f,newInteger(70));
    push(f,newInteger(26));
    push(f,newInteger(80));
    push(f,newInteger(73));
    push(f,newInteger(70));
    push(f,newInteger(81));
    displayStack(stdout,f);
clock_t stat = clock();
double el = (double)(stat - srat) * 1000.0 / CLOCKS_PER_SEC;
printf("\nTime elapsed in ms: %f", el);

clock_t smol = clock();

printf("\n\nTESTING #29\n");
  stack *g = newStack(displayInteger);
  for (int i = 0; i < 30000; ++i)
  {
    /* code */push(g,newInteger(i));
  }
  for (int i = 0; i < 30000; ++i)
  {
    /* code */pop(g);
  }
  displayStack(stdout,g);
clock_t slow = clock();
double egg = (double)(slow - smol) * 1000.0 / CLOCKS_PER_SEC;
printf("\nTime elapsed in ms: %f\n", egg);

  return 0;
}