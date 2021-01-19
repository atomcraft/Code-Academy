#include <stdio.h>

int main(void){
    int iX = 13;
    int iY = 44;
    int iResult = 0;
    iResult = iX - iY;
    printf("%d - %d = %d \n", iX, iY, iResult);
    iResult = iY / iX;
    printf("%d / %d = %d \n", iY, iX, iResult);
    iResult = iY % iX;
    printf("%d / %d Remainder: %d \n", iY, iX, iResult);
    iResult = iY * iX;
    printf("%d * %d = %d \n", iY, iX, iResult);
    iResult = iX + iY;
    printf("%d + %d = %d \n", iX, iY, iResult);

    float fA = 1.5;
    float fB = 2.5;
    float fResult = 0.0;
    fResult = fA - fB;
    printf("%f - %f = %f \n", fA, fB, fResult);
    fResult = fB / fA;
    printf("%f / %f = %f \n", fB, fA, fResult);
    // fResult = fB % fA;
    // printf("%f / %f Remainder: %f \n", fB, fA, fResult);
    fResult = fB * fA;
    printf("%f * %f = %f \n", fB, fA, fResult);
    fResult = fA + fB;
    printf("%f + %f = %f \n", fA, fB, fResult);
    return 0;
}