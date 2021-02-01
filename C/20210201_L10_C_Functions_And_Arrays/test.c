#include <stdio.h>

int main(void){
    int a = 5, b;
    int *p, *c;
    long t = 500000000L;
    long int *tPoint = &t;
    p = &a;
    b = *p;
    c = &p;
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("p: %p\n", p);
    printf("c: %p\n", c);
    printf("tPoint: %p\n", tPoint);
    return 0;
}