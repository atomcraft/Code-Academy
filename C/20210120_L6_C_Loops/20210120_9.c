#include <stdio.h>

int main(void){
    int nValue = 123;
    int nMod3 = nValue % 3;
    if (0 == nMod3){
        printf("%d is divided by 3\n", nValue);
    } else{
        printf("%d is not divided by 3\n", nValue);
    }
    return 0;   
}