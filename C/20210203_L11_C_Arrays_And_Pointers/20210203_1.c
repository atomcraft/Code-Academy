/*
Задача 1 декларирайте три масива с три елемента:
Първият от тип char
Вторият от тип int
Третият от тип double
Отпечатайте размерите на масивите използвайки
оператора sizeof(arr);
*/

#include <stdio.h>

int main(void){
    char c[3];
    int x[3];
    double y[3];
    printf("Size of char array: %d\n", sizeof(c));
    printf("Size of int array: %d\n", sizeof(x));
    printf("Size of double array: %d\n", sizeof(y));
    return 0;
}