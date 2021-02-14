/*
Задача 7. Напишете функция, която прави същото, както в задача
6, но е рекурсивна.
*/

#include <stdio.h>

void printNumbers(int, int);

int main(void){
    int start = 1;
    int end = 30;
    printNumbers(start, end);
    return 0;
}

void printNumbers(int start, int end){
    if (start == end){
        printf("%d ", start);
        return;
    } else{
        printf("%d ", start);
        start++;
        printNumbers(start, end);
        return;
    }  
} 