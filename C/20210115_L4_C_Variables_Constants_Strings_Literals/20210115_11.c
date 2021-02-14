#include <stdio.h>

int main(void){
    char str[] = "Hello";
    char rts[sizeof(str)];
    rts[0] = str[4];
    rts[1] = str[3];
    rts[2] = str[2];
    rts[3] = str[1];
    rts[4] = str[0];
    printf("%s", rts);
    return 0;
}