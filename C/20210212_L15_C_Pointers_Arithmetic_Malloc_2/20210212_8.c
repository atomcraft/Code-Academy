/*
Задача 8.
Заделяне на памет от стека с alloca.
Заделете памет в стека (няма нужда от free())
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
    piValues = (int*) alloca(uNumOfElem * sizeof(int));
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
    return 0;    
}