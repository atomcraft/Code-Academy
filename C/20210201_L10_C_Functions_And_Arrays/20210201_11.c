/*
Задача 11 напишете функция void squeeze(char s[], int c), която
премахва символа с от низа s[]
*/

#include<stdio.h>
#include <string.h>

void squeeze(char s[], int c);

int main(void){
    char s[] = "Hello world!";
    int c = 'l';
    squeeze(s, c);
    printf("New string: %s", s);
    return 0;
}

void squeeze(char s[], int c){
    int i, j;
    for (i = 0; s[i] != '\0'; i++){
        if (s[i] != c){
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}