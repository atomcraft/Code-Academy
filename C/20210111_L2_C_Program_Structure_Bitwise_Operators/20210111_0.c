#include <stdio.h>

int addDigit(int a, int b);

int main(void){
    int a, b;
    a = 7;
    b = 8;
    printf("%d", addDigit(a,b));
    return 0;
}
int addDigit(int a, int b){
    int rez = a + b;
    return rez;
}