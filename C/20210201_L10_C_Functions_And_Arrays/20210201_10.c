
/*
Задача 10. Напишете функция void itob(int n, char s[], int b), която
преобразува цяло число n в низ s базиран на основа b.
Например itob( n, s[], 16) представя числото n като шеснадесетично число в
стринга s[].
*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void){
    char s[MAXLINE];
    int n = 2024;
    int base = 16;
    itob(n, s, base);
    return 0;
}

void itob(int n, char s[], int b){
    int i, j, sign;
    if ((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do
    {
        j = n % b;
        s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
    } while ((n /= b) > 0);
    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
    printf("Number in hexadecimal: %s", s);   
}

void reverse(char s[]){
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}