/*
Задача 4.
Заделяне и освобождаване на памет - malloc, free. Заделете
динамично памет за масив и попълнете елементите
*/

#include <stdio.h>
#include <stdlib.h>

void createArr();
void memAllocate(int n);

extern int* piValue = NULL;

int main(void){
    createArr();
    free(piValue);  
    return 0;
}

void createArr(){
    unsigned uSize = 0;
    printf("Enter size: ");
    scanf("%u", &uSize);
    memAllocate(uSize);
    unsigned uIdx = 0;
    for (; uIdx < uSize; uIdx++){
        printf("Enter element %d :", uIdx);
        scanf("%d", (piValue + uIdx));
    }
}

void memAllocate(int n){
    piValue = (int*) malloc(n * sizeof(int));
    if(NULL == piValue){
        printf("Allocation memory error!\n");
        exit(1);
    }
}
