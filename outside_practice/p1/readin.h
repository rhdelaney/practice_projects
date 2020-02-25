#include <stdio.h>

#ifndef __READIN_INCLUDED__
#define __READIN_INCLUDED__

typedef void (*Reader)(queue*,FILE*);


void readIntegers(queue *q, FILE *fp);
void readReals(queue *q, FILE *fp);
void readStrings(queue *q, FILE *fp);
void readPeople(queue *q, FILE *fp);

#endif