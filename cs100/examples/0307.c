#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

void printPoint(struct point *);

int main( ) {
    struct point *p;
    p = malloc( sizeof(struct point) );
    int a, b;
    printf("Enter the x and y coordinates of a point : ");
    scanf("%d %d", &a, &b);
    p->x = a;  // p.x = a;
    p->y = b;
    printf("The point is : ");
    printPoint(p);
    printf("\n");
    return 0;
}

void printPoint(struct point *q) {
    printf("<%d,%d>", q->x, q->y);
    return;
}
