/*
Задача 12 напишете функцията int any(char s1[], char s2[]), която
връща първата позиция в низа s1, където се появява някой от
символите в низа s2 (Стандартната библиотечна функция strpbrk
извършва тази функция)
*/

#include <stdio.h>

int any(char s1[], char s2[]);

int main(void){
    char s1[] = "Hello World!";
    char s2[] = "123!";
    int position = any(s1, s2);
    if (position != -1){
        printf("The first position of common char in s1 and s2 is: %d\n", position);
    } else
    {
        printf("There is no common character between s1 and s2.");
    }    
    return 0;
}

int any(char s1[], char s2[]){
    for (int i = 0; s1[i] != '\0'; i++){
        for (int j = s2[j]; s2[j] != '\0'; j++){
            if (s2[j] == s1[i]){
                return i;
            }                  
        }        
    }
    return -1;    
}