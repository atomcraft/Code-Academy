/*
Задача 8.
Дефинирайте и инициализирайте променлива и пойнтер
към нея. Отпечатайте адреса на пойнтера с %p с printf.
*/
#include <stdio.h>

int main(void){
    int a = 34;
    int *pA = &a;
    printf("Pointer address: %p\n", pA);
    return 0;
}