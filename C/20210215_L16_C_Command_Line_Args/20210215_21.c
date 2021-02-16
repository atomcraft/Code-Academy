/*
Задача 21. Напишете функция, която сортира лексикографски масив от
символи (char[]) използвайки qsort.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b){
    return (*(char*)a - *(char*)b);
}

int main(void){
    char v[] = {'c', 'z', 'k', 'l', 'o', 'd', 'a'};
    qsort(v, 7, sizeof(char), cmpfunc);
    for (int i = 0; i < 7; i++){
        printf("%c ", v[i]);
    }
    printf("\n");
    return 0;    
}