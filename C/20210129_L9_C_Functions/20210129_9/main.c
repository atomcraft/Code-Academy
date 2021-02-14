#include <stdio.h>
#include "f.h"

int main(void){
    double num = 0.0L;
    printf("Enter a number: ");
    scanf("%lf", &num);
    double rez = sqRoot(num);
    printf("\nResult: %0.3lf\n", rez);
    return 0;
}
