/*
Задача 6. Напишете функция с прототип my_swap(а, b), която разменя
стойностите на две цели числа без да използва спомагателна променлива
(например: *a = *a + *b; *b = *a - *b; *a = *a - *b). 
*/

#include <stdio.h>

void my_swap(int *, int *);

int main(void){
    int a = 3;
    int b = 13;
    int *aP = &a;
    int *bP = &b;
    my_swap(aP, bP);
    printf("Value of a: %d\n", a);
    printf("Value of b: %d\n", b);
    return 0;
}

void my_swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}