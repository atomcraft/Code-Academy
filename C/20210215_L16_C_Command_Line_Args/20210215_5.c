/*
Задача 5.
Дефинирайте и инициализирайте int променлива = 34 и
пойнтер към нея.
Опитайте да ги разместите, като поредност (първо да е
пойнтерът, после променливата). - Не може.

Можете ли да умножите пойнтер по пойнтер?
При тази декларация колко пойнтера имаме:
int *p, k; - 1 pointer(*p)

*/
#include <stdio.h>

int main(void){
    int a = 34;
    int *pA = &a;
    printf("Pointer address: %p\n", pA);
    printf("Pointer value: %d\n", *pA);
    int b = 20;
    int *pB = &b;
    printf("Pointer multiplication: %p\n", (*pA) * (*pB));
    printf("Pointer multiplication value: %d\n", (*pA) * (*pB));
    return 0;

}