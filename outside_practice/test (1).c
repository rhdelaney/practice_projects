#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    a=3;

    double b=0.6;
    
    double c;
    c=a+b;
    printf("c=%lf\n", c);

    int d;
    d=a+b;
    printf("\td=%d\n", d);

    int e;
    e=ceil(a+b);
    printf("\te=%d\n", e);

    printf("3 or 4? %d\n", (int)(c+0.5));

    c -= 0.2;
    printf("3 or 4? %d\n", (int)(c+0.5));
    // printf("3 or 4? %d\n", (int)c+0.5);

    a *= 3+7; // a=a*(3+7); not a=a*3+7
    printf("a=%d\n", a);

    double f;
    f=sqrt(3*3+4*4);
    printf("f is %lf.\n", f);

    printf("14/5 is %d.\n", 14/5);
    printf("14%%5 is %d.\n", 14%5);

    printf("14/5 is %lf.\n", 14.0/5);
    printf("14/5 is %lf.\n", (double)14/5);

    printf("\"\'\\\'\"\n");
    printf("-\101\x61-\n");

    printf("-%c-\n", 'A');
    printf("-%c-\n", '8');
    printf("-%d-\n", 8);
    printf("-%s-\n", "8");

    printf("-%s-\n", "Alabama");


    return 0;
}
