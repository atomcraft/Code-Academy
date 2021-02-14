#include <stdio.h>

int main(void){
    int iCounter = 0;
    while (++ iCounter < 3){
        printf("Counter %d\n", iCounter);
        printf("++ Counter: %d\n", ++iCounter);
        printf("-- Counter: %d\n", --iCounter);
        printf("Counter ++: %d\n", iCounter++);
        printf("Counter --: %d\n", iCounter--);
    }
    return 0;    
}