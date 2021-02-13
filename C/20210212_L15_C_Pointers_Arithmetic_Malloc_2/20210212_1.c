/*
Задача 1. Да се направи програма, която заделя динамичен масив с брой елементи
зададени от потребителя. За всеки елемент от масива се очаква потребителят да въведе
цяло и число и след това се изчислява сумата на всички елементи от масива.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    unsigned uIdx = 0;
    unsigned uNumOfElem = 0;
    int* piValues = NULL;
    int iSum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &uNumOfElem);
    piValues = (int*) malloc(uNumOfElem * sizeof(int));
    if(piValues == NULL){
        printf("Not enough memory");
        exit(1);
    }
    for (; uIdx < uNumOfElem; uIdx++){
        printf("Enter element %d :", uIdx);
        scanf("%d", (piValues + uIdx));
        iSum += *(piValues + uIdx);
    }
    printf("\nThe sum of the elements is: %d", iSum);
    free(piValues);
    return 0;    
}