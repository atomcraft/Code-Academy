#include <stdio.h>

int main(void){
    double numD = 0xBB;
    signed long long numSll = 0xBB;
    unsigned long long numUll = 0xBB;
    printf("%f\n", numD);
    printf("%lld\n", numSll);
    printf("%llu\n", numUll);
    return 0;
}