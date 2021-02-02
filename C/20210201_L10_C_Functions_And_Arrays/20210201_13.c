
/*
Задача 13 напишете функцията void lower(char s[]), която
преобразува главните букви в малки.
*/

#include <stdio.h>

void lower(char s[]);

int main(void){
    char s[] = "HELLO WORLD!";
    lower(s);
    return 0;
}

void lower( char s[]){
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] + 'a' - 'A';
        }        
    }
    printf("Lowered string: %s", s);   
}