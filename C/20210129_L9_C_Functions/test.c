#include <stdio.h>

int main(void){
    int outcome = 0 ? 1 : 2;
    printf("0 ? %d", outcome);
    int nValue = 1;
    printf("%d", nValue--);
    return 0;
}