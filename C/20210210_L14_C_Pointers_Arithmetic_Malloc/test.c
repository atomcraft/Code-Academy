#include <stdio.h>

void printX();

void main(void){
    // printX();
    char sz[] = "z";
    printf("%d", sizeof(sz));
    float arr[7] = { 0.0};
    printf("%f", arr[5]);
    // int arr1[2][2][2] = {{{8,7},{6,5},{4,3},{2,1}}};
    // printf("%d", arr1[1][0][1]);
    int *pi = NULL;
    char *pc = NULL;
    printf("\n");
    if (sizeof(pi) == sizeof(pc))
    {
        printf("1\n");
    }
    if (sizeof(pi) > sizeof(pc))
    {
        printf("2\n");
    }
    if (sizeof(pi) < sizeof(pc))
    {
        printf("3\n");
    }
    // long *pValue = NULL;
    // *pValue = 13;
    // printf("%p", pValue);
    printf("\n");
    char arrText[] = "ABCD";
    printf("%c ", *(arrText + 3));
    // int *pFun = &printX;
    // int x = 5;
    // int *pData = &x;
    // if (sizeof(pFun) == sizeof(pData))
    // {
    //     printf("\n1\n");
    // }
    // if (sizeof(pFun) > sizeof(pData))
    // {
    //     printf("2\n");
    // }
    // if (sizeof(pFun) < sizeof(pData))
    // {
    //     printf("3\n");
    // }

}

void printX(){
    
}