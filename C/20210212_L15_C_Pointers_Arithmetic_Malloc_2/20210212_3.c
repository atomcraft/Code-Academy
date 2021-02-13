/*
Задача 3 Напишете функции, с помощта на които да реализирате динамичен
масив от елементи, чиято големина може да се променя по време на
изпълнение на програмата
*/
#include <stdio.h>
#include <stdlib.h>

void createArr();

int main(void){
    createArr();
    return 0;
}

void createArr(){
    int* piValue = NULL;
    unsigned uSize = 0;
    printf("\nEnter size: ");
    scanf("%u", &uSize);
    piValue = (int*) malloc(uSize * sizeof(int));
    if(NULL == piValue){
        printf("Allocation memory error!\n");
        exit(1);
    }
    printf("Addresses of allocated memory: %p\n", piValue);
    printf("\nEnter the new size: ");
    scanf("%u", &uSize);
    piValue = realloc(piValue, uSize * sizeof(int));
    if(NULL == piValue){
        printf("Reallocation memory error!\n");
        exit(2);
    }
    printf("Addresses of reallocated memory: %p\n", piValue);
    free(piValue);
}