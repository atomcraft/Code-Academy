#include <stdio.h>

int main(){
    int num = 925;
    int indx = 4;
    num &= ~(1 << indx);
    indx += 1;
    num &= ~(1 << indx);
    indx += 1;
    num &= ~(1 << indx);
    indx += 1;
    num &= ~(1 << indx);
    indx += 1;
    num &= ~(1 << indx);
    indx += 1;
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