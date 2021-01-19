#include <stdio.h>

int main(void){
    /* !(A && B) = !A||!B
       !(A || B) = !A && !B
    */
    int a = 1;
    int b = 2;
    int first = !(a && b);
    int second = !a || !b;
    first == second ? printf("equal\n") : printf("not equal\n");
    int third = !(a || b);
    int fourth = !a && !b;
    third == fourth ? printf("equal\n") : printf("not equal\n");
    return 0;
}