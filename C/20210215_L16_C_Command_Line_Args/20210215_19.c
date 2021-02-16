/*
Задача 19. Дефинирайте стринг: „Baba, kaka, mama” заменете „а“
със „о“
*/
#include <stdio.h>
#include <string.h>

int main(void){
    char *s = "aba, kaka, mama";
    int len = strlen(s) + 1;
    char newString[len];
    for (int i = 0; i < len; i++){
        if (s[i] == 'a'){
            newString[i] = 'o';
            continue;
        }else{
            newString[i] = s[i];
        }
    }
    printf("New string: %s\n", newString);
    return 0;    
}