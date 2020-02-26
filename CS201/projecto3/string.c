#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "string.h"

string *newString(char *x) {
    string *p = malloc(sizeof(string));
    if (p == 0) {
        fprintf(stderr,"out of memory\n");
        exit(-1);
    }
    //p->value=malloc(sizeof(strlen(x)));
    //strcpy(p->value,x);
    p->value = x;
    return p;
}

char *getString(string *v) {
    return v->value;
}

char *setString(string *v,char *x) {
    /*string *old = malloc(sizeof(string));
    old->value=malloc(sizeof(v->value));
    strcpy(old->value,v->value);
    v->value = malloc(sizeof(strlen(x)));
    strcpy(v->value,x);
    return old->value;*/
    char *temp = v->value;
    v->value = x;
    return temp;
}

void displayString(FILE *fp,void *v) {
    fprintf(fp,"\"%s\"",getString((string *) v));
}

void freeString(string *v) {
    free(v);
}
