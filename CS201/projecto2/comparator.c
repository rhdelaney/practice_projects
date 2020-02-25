#include <stdio.h>
#include <stdlib.h>
#include "comparator.h"

int intComparator(void *v1, void *v2) {
    int x = getInteger(v1);
    int y = getInteger(v2);

    if (x > y) return 1;
    else if (x < y) return -1;
    else return 0;
}
int stringComparator(void *v1, void *v2) {
    char *x = getString(v1);
    char *y = getString(v2);

   return strcmp(x,y);
}

int realComparator(void *v1, void *v2) {
    double x = getReal(v1);
    double y = getReal(v2);

    if (x > y) return 1;
    else if (x < y) return -1;
    else return 0;
}
