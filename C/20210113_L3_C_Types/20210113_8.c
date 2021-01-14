#include <stdio.h>

int main(){
    char x = 8;
    x= x - 2;
    x = x + 6;
    x = x -10 + 2; // x = 4; from left to right, first x(12) - 10, then 2 + 2
    printf("%d", x);

    return 0;
}