/*
Задача 12.

Напишете макро GENERIC_MAX(type)
,което трябва да се експандне до следната функция
*/
#include <stdio.h>

#define GENERIC_MAX(type) \
type type##_max(type x, type y)\
{                              \
    return x > y ? x : y;      \
}                              \

GENERIC_MAX(float);

int main(void){
    float x = 3.1;
    float y = 3.2;
    float (*gPtr)(float, float);
    gPtr = float_max;
    printf("Result: %f\n", gPtr(x, y));
    return 0;

}