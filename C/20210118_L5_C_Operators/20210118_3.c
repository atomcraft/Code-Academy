#include <stdio.h>

int main(void){
    int x = 10;
    int y = 10;
    int true, false;
    true = ++x + x || y;
    printf("True = %d\n", true);
    return 0;
    
}