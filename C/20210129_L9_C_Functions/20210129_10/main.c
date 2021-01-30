#include <stdio.h>
#include "f.h"

int main(void){
    float fNumA = 0.0F;
    float fNumB = 0.0F;
    int iNum1 = 0;
    int iNum2 = 0;
    printf("Enter number 1: ");
    scanf("%d", &iNum1);
    printf("Enter number 2: ");
    scanf("%d", &iNum2);
    int lcmNum1Num2 = leastCommMultiple(iNum1, iNum2);
    printf("\nThe least common multiplier between num1 and num2 is: %d\n", lcmNum1Num2);
    printf("Enter a floating number: ");
    scanf("%f", &fNumA);
    float sqrtRzs = sqRoot(fNumA);
    if (sqrtRzs == -1){
        float absA = absoluteValue(fNumA);
        printf("Sqrt of the floating number: %f\n", sqRoot(absA));
    } else{
        printf("Sqrt of the floating number: %f\n", sqrtRzs);
    }
    return 0;
}
