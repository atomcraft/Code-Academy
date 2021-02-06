/*
Задача 6. Напишете отново функцията void our_strcat(char *s, char *t), която
разгледахме преди малко като използвате указатели, а не
инкрементиращите пrоменливи i, j.
*/

#include <stdio.h>

void our_strcat(char *s, char *t);

int main(void){
    char s[] = "Hello ";
    char t[] = "world";
     our_strcat(s, t);
    printf("Combined: %s", s);
    return 0;
}

void our_strcat(char *s, char *t){
    while (*s){
        s++;
    }
    while (*s++ = *t++)
    ;    
}