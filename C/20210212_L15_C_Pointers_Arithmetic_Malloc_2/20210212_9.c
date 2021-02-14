/*
Задача 9.
Разширяване на заделена памет с realloc
Напишете програма, която пита потребителя колко
памет иска и заделя съответния блок памет. След
това попитайте потребителя за нов размер и
използвайте функция, която прави това.
*/

#include <stdio.h>
#include <stdlib.h>

void memReAllocate(int *s, unsigned size);

int main(void){
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
    memReAllocate(piValue, uSize);
    // piValue = realloc(piValue, uSize * sizeof(int));
    // if(NULL == piValue){
    //     printf("Reallocation memory error!\n");
    //     exit(2);
    // }
    printf("Addresses of reallocated memory: %p\n", piValue);
    free(piValue);
    return 0;
}
void memReAllocate(int *s, unsigned size){
    s = realloc(s, (size * size / 2) * sizeof(int));
    if(NULL == s){
        printf("Reallocation memory error!\n");
        exit(2);
    }
}