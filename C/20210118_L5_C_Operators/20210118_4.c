#include <stdio.h>

int main(void){
    int x = 10;
    int y = 10;
    int true;
    true = x && y & x << 1;
    printf("True = %d\n", true);
    true = x && y ^ x << 1;
    printf("True = %d\n", true);
    return 0;
}