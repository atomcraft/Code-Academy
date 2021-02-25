/*
Задача 8.
Напишете функциите като макроси:
1. функция AVG, която смята средното аритметично на две подадени
като параметър числа.
1. функция AVG, която смята средното аритметично на числата от
определен диапазон.
1. Напишете функцията повдигане на степен, която повдига х на степен
у
1. Напишете функцията TOUPPER, която прави малкиата буква а в
голяма А
*/
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define AVG1(x, y) {(x + y) / 2}
#define AVG2(x, y) {\
             int sum = 0; \
             for ( ; x < y; y++)\
             {\
                sum += x; \
             }\
             printf("The average is: %d", sum / (y - x));\
             }
#define fPow(x, y) (pow(x, y))
#define power(x, y) (y << (x)) 
#define toUpper(c) { toupper(c)}

#define DISP(f,x) (printf("sqrt (%g) = %g\n", (x), (f(x))))


int main(void){
    int x = 2;
    int y = 3;
    int result = AVG1(x, y);
    double powResult = fPow(3.0, 4.0);
    printf("Power of y: %d\n", powResult);
    char c = 'a';
    char toUpResult = toUpper(c);
    printf("ToUpper: %c\n", toUpResult);
    DISP(sqrt, 1024.0);
    return 0;



}