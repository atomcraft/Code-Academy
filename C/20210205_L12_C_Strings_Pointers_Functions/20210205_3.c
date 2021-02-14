/*
Задача 6.Опитайте да го направите сами:
Указатели и масиви, функции
Ето я версията, която използва указатели:
*/

#include <stdio.h>

void our_strcpy(char *s, char *t);

int main(void){
    char t[] = "Hi!";
    char s[8];
    our_strcpy(s, t);

    printf("String t: %s", t);
    return 0;
}

void our_strcpy(char *s, char *t){
while(*s++ = *t++)
;
}

