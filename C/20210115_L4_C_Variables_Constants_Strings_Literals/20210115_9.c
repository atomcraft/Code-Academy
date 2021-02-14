#include <stdio.h>

int main(void){
    char s[] = "Hi";
    int counter = 0;
    for (int i = 0; i < sizeof(s) / sizeof(char); i++){
        if (s[i] == '\0'){
            break;
        }
        
        printf("%c ", s[i]);
        counter++;
    }
    printf("\n%d", counter);
}