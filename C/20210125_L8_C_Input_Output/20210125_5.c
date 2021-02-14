#include <stdio.h>

int main(void){
    int c = 0;
    while ((c = getchar()) != '?'){
        if (c >= 'a' && c <= 'z'){
            putchar(c);
            
        }
        
        if (c >= 'A' && c <= 'Z'){
            putchar(c);
        }                
    }
    return 0;    
}