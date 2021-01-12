#include <stdio.h>

int main(){
    int num1 = 10;
    int num2 = 15;
    int counterDifBits = 0;
    for (int i = 0; i < sizeof(int); i++){
        int bitNum1 = (num1 >> i) & 1;
        int bitNum2 = (num2 >> i) & 1;

        if (bitNum1 != bitNum2){
            counterDifBits++;
        }        
    }
    printf("%d", counterDifBits);
    return 0;     
}