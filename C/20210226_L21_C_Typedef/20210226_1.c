/*
Задача 1. Дефинирайте структура като
потребителски тип. Инициализирайте членовете на
структурата, използвайки новия потребителски тип.
Отпечатайте.
*/

#include <stdio.h>

typedef struct user{ char *name; int age; } user_t;

int main(void){
    user_t u1 = {.name = "Georgi", .age = 25};
    printf("Name: %s\n", u1.name);
    printf("Age: %d\n", u1.age);
    return 0;
}