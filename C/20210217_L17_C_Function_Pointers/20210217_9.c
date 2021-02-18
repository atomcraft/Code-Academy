/*
Задача 9.
Напишете по 2 тройни цикъла (един и същи код) за масивите.
Хайде да го изнесем във функция.
*/

#include <stdio.h>

void printArrNum(int *arrNum);
void printArrChar(char *arrChar);
void printArrDouble(double *arrDouble);


int main(void){
    int arrNum[] = {1, 2, 3, 4, 5};
    char arrChar[] = {'a', 'b', 'c', 'd', 'f'};
    double arrDouble[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    printArrNum(arrNum);
    printf("\n");
    printArrChar(arrChar);
    printf("\n");
    printArrDouble(arrDouble);
    printf("\n");    
    return 0;
}

void printArrNum(int *arrNum){
    for (int i = 0; i < 5; i++){
        printf("%d ", arrNum[i]);
    }
}

void printArrChar(char *arrChar){
    for (int i = 0; i < 5; i++){
        printf("%c ", arrChar[i]);
    }
}

void printArrDouble(double *arrDouble){
    for (int i = 0; i < 5; i++){
        printf("%lf ", arrDouble[i]);
    }
}