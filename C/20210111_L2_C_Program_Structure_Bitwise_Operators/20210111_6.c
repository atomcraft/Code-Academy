#include <stdio.h>

int main (){
    int num = 14;
    int indx = 2;
    int result = num ^ ( 1 << indx);
    printf("%d", result);
    return 0;
}