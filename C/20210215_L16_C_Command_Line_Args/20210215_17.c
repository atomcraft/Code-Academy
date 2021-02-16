/*
Задача 17. Направете същото, както в задача 18., но преди да
копирате, нулирайте стойността на стринговете, в
които ще копирате, използвайки готовата функция
memset. Потърсете онлайн как работи тази функция и
какви аргументи приема.
https://www.tutorialspoint.com/c_standard_library/c_functi
on_memset.htm
*/

#include <stdio.h>
#include <string.h>

int main(void){
    char *string1 = "A string to be copied";
    char *string2 = "I am very good in strings coping!";
    char string3[strlen(string1) + 1];
    char string4[strlen(string2) + 1];
    memset(string4, '\0', strlen(string2) + 1);
    strncpy(string4, string2, strlen(string2) + 1);
    printf("String 4: %s\n", string4);
    memset(string3, '\0', strlen(string1) + 1);
    strncpy(string3, string1, strlen(string1) + 1);
    printf("String 3: %s\n", string3);
    return 0;
}