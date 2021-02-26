/*
Задача 4 Дефинирайте функция, която събира
две променливи и приема и изпълнява предефиниран
указател, като стойност.
*/

#include <stdio.h>

typedef int* t_Int;

void add(t_Int ptr){
    printf("Sum = %d\n", (*ptr + 5));
}

typedef void (*t_Add)(t_Int);
t_Add ptrAdd = NULL;

int main(void){
    int x = 5;
    t_Int pI = &x;
    printf("Value of pointer pI: %d\n", *pI);
    add(pI);
    int y = 10;
    t_Int pY = &y;
    ptrAdd = &add;
    ptrAdd(pY);

    return 0;
}