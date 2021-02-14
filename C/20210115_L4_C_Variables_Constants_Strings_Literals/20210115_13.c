#include <stdio.h>

int main(void){
    char str[] = "HELLO";
    str[0] = 'h';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    printf("%s", str);
    return 0;
}