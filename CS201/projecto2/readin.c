#include <stdio.h>
#include <stdlib.h>
#include "integer.h"
#include "scanner.h"
#include "queue.h"
#include "stack.h"
#include "readin.h"
#include "string.h"
#include "real.h"

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