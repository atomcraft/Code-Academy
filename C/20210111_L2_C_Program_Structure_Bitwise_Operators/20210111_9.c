#include <stdio.h>

int main(){
    int num = 2037;
    int indx = 3;
    num &= ~(1 << indx);
    indx += 1;
    num &= ~(1 << indx);
    indx += 1;
    num &= ~(1 << indx);
    indx += 1;
    num &= ~(1 << indx);
    indx += 1;
    num &= ~(1 << indx);
    printf("%d", num);
    return 0;
}