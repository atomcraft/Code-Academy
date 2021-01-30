#include <stdio.h>
#include "f.h"


int main(void){
    int a = 1, b = 2;
    int rez = add(a, b);
    printf("Add function result: %d", rez);
    a = incr(a);
    printf("\nIncr function result: %d\n", a);
    return 0;
}