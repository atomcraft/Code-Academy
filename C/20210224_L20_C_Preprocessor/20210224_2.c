#include <stdio.h>
#define swap(t, x, y){ x = x + y; y = x - y; x = x - y; }
int main(void){
    int a = 1;
    int b = 5;
    printf("Initial a = %d and b = %d\n", a, b);
    swap(int, a, b);
    printf("Swaped, a = %d and b = %d\n", a, b);
    char c ='c';
    char z = 'z';
    swap(char, c, z);
    printf("Swaped, c = %c and z = %c\n", c, z);
    return 0;
}