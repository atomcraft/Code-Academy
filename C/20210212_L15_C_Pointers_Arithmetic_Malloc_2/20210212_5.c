/*

*/

#include <stdio.h>
#include <stdlib.h>

void createArr();
void memAllocate(int n);
void memReAllocate(int n);

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
    printf("\nEnter the new size: ");
    scanf("%u", &uSize);
    memReAllocate(uSize);
    uIdx = 0;
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

void memReAllocate(int n){
    piValue = realloc(piValue, n * sizeof(int));
    if(NULL == piValue){
        printf("Reallocation memory error!\n");
        exit(2);
    }

}