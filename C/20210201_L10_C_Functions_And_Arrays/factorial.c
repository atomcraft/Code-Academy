#include <stdio.h>

unsigned Factorial (unsigned uValue);

int main(void){
    unsigned int nValue = 10;
    printf("Factorial of %d is: %d\n", nValue, Factorial(nValue));
    return 0;
}

unsigned Factorial (unsigned uValue){
    // if (uValue < 2){
    //     return 1;
    // } else{
        printf("%d\n", uValue);
        return uValue * Factorial(uValue - 1);
    // }    
}