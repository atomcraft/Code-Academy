/*
Задача 7. Напишете масив от структури наречен kaytab[ ], като
използвате тази, дефинирана в горното упражнение - потребителски тип
key_t, която съдържа символен низ и число. Инициализирайте масива с
всички ключови думи на С.
*/
#include <stdio.h>

typedef struct key{ char *c; int i; } key_t;

key_t keytab[];

int main(void){
    key_t user = {"Georgi", 25};
    printf("Name: %s\nAge: %d\n", user.c, user.i);
    return 0;
}