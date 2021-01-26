#include <stdio.h>

int main(void){
    int c =0;

    while ((c = getchar()) != EOF){
        if (c >= 'a' && c <= 'z'){
            c = c - 32;
            putchar(c);              
        } else{
            putchar(c);
        }
        if (c == '\n'){
            putchar('\n');
        }
    }
    return 0;    
}