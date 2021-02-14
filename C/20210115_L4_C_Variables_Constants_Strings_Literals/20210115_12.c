#include <stdio.h>

int main(void){
    char str[] = "Hello";
    str[2] = 'x';
    str[3] = 'x';
    printf("%s", str);
    return 0;
}