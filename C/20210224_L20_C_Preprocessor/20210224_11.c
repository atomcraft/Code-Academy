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
#define AVG2(x, y, result) for(int i = (x); i <= (y); i++) {result += 1;} result /= (y) - (x);
#define fPow(x, y, result) result = (x); for(int i = 0; i < (y); i++) {result *=(x);}
#define power2(x) (1 << (x)) 
#define toUpper(c) { toupper(c)}

#define DISP(f,x) (printf("sqrt (%g) = %g\n", (x), (f(x))))


int main(void){
    int x = 2;
    int y = 3;
    float result2;
    float result1;
    int result = AVG1(x, y);
    AVG2(1, 4, result1);
    fPow(3.0, 4.0, result2);
    printf("Power of y: %f\n", result2);
    printf("AVG2: %f\n", result1);
    char c = 'a';
    char toUpResult = toUpper(c);
    printf("ToUpper: %c\n", toUpResult);
    DISP(sqrt, 1024.0);
    return 0;



}