/*
Задача 16.
Направете същото, както в задача 17, но използвайки
готовата функция strcpy. Потърсете онлайн как работи
тази функция и какви аргументи приема.
https://www.tutorialspoint.com/c_standard_library/c_function_strcpy.h
tm
*/

#include <stdio.h>
#include <string.h>

int main(void){
    char *string1 = "A string to be copied";
    char *string2 = "I am very good in strings coping!";
    char string3[strlen(string1) + 1];
    char string4[strlen(string2) + 1];
    strncpy(string4, string2, strlen(string2) + 1);
    printf("String 4: %s\n", string4);
    strncpy(string3, string1, strlen(string1) + 1);
    printf("String 3: %s\n", string3);
    return 0;
}