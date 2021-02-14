#include <stdio.h>

void decToBin(unsigned int num){
    printf("Binary value is: ");
    unsigned int iCheck = 31;
    for (unsigned int i = 1 << iCheck; i > 0; i = i >> 1){
       	(num & i) ? printf("1") : printf("0");
    }
    return;
}

int main(void){
    unsigned int num = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    decToBin(num);
    return 0;
}
