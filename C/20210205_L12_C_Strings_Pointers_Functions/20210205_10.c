/*
Задача 9. Напишете функцията strncpy(s, t, n), която копира най -
много n символа от t в s .
*/

#include <stdio.h>
#include <string.h>

void my_strncpy(char *s, char *t, int n);

int main(void){
    char t[] = "Hello!";
    char s[16];
    int n = 3;
    my_strncpy(s, t, n);

    printf("String t: %s", s);
    return 0;
}

void my_strncpy(char *s, char *t, int n){
    while (*t && n-- > 0)
        *s++ = *t++;
    while (n-- > 0)
        *s++ = '\0';  
}