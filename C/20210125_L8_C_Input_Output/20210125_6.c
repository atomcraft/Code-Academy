#include <stdio.h>

int main(void){
    int c = 0;
    int totalCounter = 0;
    int numCounter = 0;
    int letterCounter = 0;
    /* assumed that input is only letters and numbers,
    no other characters. */
    while ((c = getchar()) != EOF){
        totalCounter++;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            letterCounter++;
        }
        if (c >= '0' && c <= '9'){
            continue;
        }              
    }
    numCounter = (totalCounter - letterCounter) -1;
    printf("The number of letters is: %d\n", letterCounter);
    printf("The number of numbers is: %d\n", numCounter);
    return 0;    
}