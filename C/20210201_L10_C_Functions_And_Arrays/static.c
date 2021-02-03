#include <stdio.h>

void inc(void){
    static int a = 0;
    printf("%d\n", ++a);
    return;
}

int main(void){
    inc();
    inc();
    inc();
    int a = 100;
    printf("%d\n", a);
    return 0;
}