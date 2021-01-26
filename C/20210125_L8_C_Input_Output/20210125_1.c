#include <stdio.h>

int main(void){
    char c;
    c = getchar();
    int counter = 0;
    while (c != EOF){
        // putchar(c);
        if (c == '\n'){
            counter--;
        }
        
        counter++;
        c = getchar();
    }
    printf("The number of entered characters is %d.\n", counter);
    return 0;    
}