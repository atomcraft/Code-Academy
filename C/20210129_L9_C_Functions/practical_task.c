#include <stdio.h>
#define ARRAY_SIZE 12

int oddSum(int *x);
int evenSum(int *x);
int fillBarcodeArr(int *x);

int main(void){
    int barcode[ARRAY_SIZE];
    int i, checkDigit, odd, even, totalSum;
    if(fillBarcodeArr(barcode)){
        printf("\nYou entered the code: ");
        for(i=0; i<ARRAY_SIZE; i++){
            printf("%d ", barcode[i]);
        }
    } else{
        printf("Failed to read\n");
    }

    odd = oddSum(barcode);
    printf("\nSum of odds is: %d\n", odd);
    even = evenSum(barcode);
    printf("Sum of even is: %d\n", even);
    totalSum = odd + even;
    printf("Calculate total is: %d\n", totalSum);
    totalSum = totalSum - 1;
    totalSum = totalSum % 10;
    checkDigit = 9 - totalSum;
    printf("Check digit is: %d\n", checkDigit);

    if(checkDigit == barcode[ARRAY_SIZE - 1]) {
        printf("Barcode is VALID\n");
    } else {
        printf("Barcode is INVALID\n");
    }

    return 0;
}

int oddSum(int *x) {
    int sum_odd = (x[0] + x[2] + x[4] + x[6] + x[8] + x[10])*3;
    return sum_odd;
}

int evenSum(int *x) {
    int sum_even = (x[1] + x[3] + x[5] + x[7] + x[9] /*+ x[11]*/);
    return sum_even;
}

int fillBarcodeArr(int *x){
    int i;
    printf("Enter a barcode number to check,"
           " each number separated with space ("
           "ex. 0 1 3 8 0 0 1 5 1 7 3 5) :  \n"); /* enter like 0 1 3 8 0 0 1 5 1 7 3 5 */
    for(i=0; i<ARRAY_SIZE; i++){
        if(scanf("%d", &x[i]) != 1){
            return 0;
        }
    }
    return 1;
}