#include <stdio.h>

extern int g_Num = 0;

void test(void){
    g_Num +=1;
    printf("%d", g_Num);
}

int main(void){
    test();
    test();
    test();    
    return 0;
}