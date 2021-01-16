#include <stdio.h>

int main(void){
    double numD = 0xBB;
    signed long long numSll = 0xBB;
    unsigned long long numUll = 0xBBu;
    printf("%lf\n", numD);
    printf("%lld\n", numSll);
    printf("%lld\n", numUll);
    return 0;
}