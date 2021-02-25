/*
Задача 5. Напишете заглавен файл с декларации на функции и
сложете гардове. Този начин намалява времето за компилиране на
големи проекти.
*/
#include <stdio.h>
#include "myheader.h"

int main(void){
    #if !defined(MYHEADER)
    #define MYHEADER myheader.h
    void f(){ printf("Result: %d\n", (3+3)); }
    #endif
    f();

    return 0;
}

