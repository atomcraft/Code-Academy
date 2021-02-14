/*
Задача 10. Напишете функцията strncat(s, t, n), която добавя
(конкатенира) n символа от стринга t в края на стринга s.
*/

#include <stdio.h>
#include <string.h>

int main(void){
    char t[] = "world";
    char s[] = "Hello ";
    int n = 3;
    strncat(s, t, n);
    printf("%s", s);
    return 0;
}
