#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "integer.h"
#include "scanner.h"
#include "queue.h"
#include "stack.h"
#include "readin.h"
#include "string.h"
#include "real.h"
#include "people.h"

void readIntegers(queue *q, FILE *fp) {
    int x = readInt(fp);
    while (!feof(fp)) {
        enqueue(q, newInteger(x));
        x = readInt(fp);
    }
    //enqueue(q, newInteger(x));
}

void readReals(queue *q, FILE *fp) {
	double x = readReal(fp);
    while (!feof(fp)) {
        enqueue(q, newReal(x));
        x = readReal(fp);
    }
    //enqueue(q, newReal(x));
}

void readStrings(queue *q, FILE *fp) {
	char *x = readString(fp);
    while (!feof(fp)) {
        enqueue(q, newString(x));
        x = readString(fp);
    }
    //enqueue(q, newString(x));
 }
 void readPeople(queue *q, FILE *fp) {
    char *name=readString(fp);
    int arr = readInt(fp);
    //void *dummy=readString(fp);
    int mech = readInt(fp);
    //dummy=readString(fp);
    int oil = readInt(fp);
    while (!feof(fp)) {
        enqueue(q, newPeople(name, arr, mech, oil));
        name = readString(fp);
        arr = readInt(fp);
        //dummy=readString(fp);
        mech = readInt(fp);
        //dummy=readString(fp);
        oil = readInt(fp);
    }
    enqueue(q, newPeople(name, arr, mech,oil));
    //dummy=NULL;
}