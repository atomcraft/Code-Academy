/*
Задача 6. Напишете структура с потребителски тип key_t, която
съдържа символен низ и число.
*/
#include <stdio.h>

typedef struct key{ char *c; int i; } key_t;

int main(void){
    key_t user = {"Georgi", 25};
    printf("Name: %s\nAge: %d\n", user.c, user.i);
    return 0;
}