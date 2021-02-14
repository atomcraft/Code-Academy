#include <stdio.h>

int main(){
    int a = 5;
    int x = a++ + a;
    printf("%d\n", x);
    int b = -1;
    int y = a && b;
    printf("%d", y);
    return 0;
}