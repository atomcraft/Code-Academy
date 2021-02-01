/*
Задача 6. Напишете функция, която изчислява произведението на
числата от 1 до 30.
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
    for (int i = start; i <= end; i++){
        printf("%d ", i);
    }
    
} 