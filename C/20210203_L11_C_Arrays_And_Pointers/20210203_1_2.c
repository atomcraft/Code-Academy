/*
Задача 1.2 принтирайте последния елемент от
декларираните по горе масиви:
Първият от тип char
Вторият от тип int
Третият от тип double
*/

#include <stdio.h>

int main(void){
    char c[3] = { 'a', 'b', 'c'};
    int x[3] = { 1, 2, 3};
    double y[3] = { 1.1, 2.2, 3.3};
    printf("1st element of char array: %c\n", c[0]);
    printf("2nd element of int array: %d\n", x[1]);
    printf("3rd element of double array: %lf\n", y[2]);
    return 0;
}