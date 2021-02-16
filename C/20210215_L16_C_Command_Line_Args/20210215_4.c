/*
Задача 4.
Дефинирайте пойнтер и опитайте да отпечатате стойността
му на конзолата (%р) с printf.
Какво се визуализира?
*/
#include <stdio.h>

int main(void){
    int a = 10;
    int *pA = &a;
    printf("Pointer address: %p\n", pA);
    return 0;
}