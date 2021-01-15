#include <stdio.h>

void test (void){
    static int num = 0;
    num += 1;
    printf("%d", num);  
   
}

int main(void){
    test();
    test();
    test();
    return 0;
}