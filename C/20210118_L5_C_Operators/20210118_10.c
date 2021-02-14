#include <stdio.h>

int main(void){
    int nResult = 25;
    int nX = 4;
    printf("Result = %d\n", nResult);
    nResult += nX;
    printf("Result += %d -> %d\n", nX, nResult);
    nResult = 1;
    nResult <<= nX;
    printf("Result <<= %d -> %d\n", nX, nResult);
    //add another assignment ops;
    nResult *= nX;
    printf("Result *= %d -> %d\n", nX, nResult);
    nResult %= nX;
    printf("Result %%= %d -> %d\n", nX, nResult);
    return 0;
}