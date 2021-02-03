#include <stdio.h>

int main(void){
    // long arrNum[3];
    // arrNum[0] = 1;
    // arrNum[1] = 2;
    // arrNum[2] = 3;
    // int size = sizeof(arrNum);
    // printf("%d", size);
    int arrNum1[3];
    int i = 0;
    char c;
    while (i < 4)
    {
        c = getchar();
       arrNum1[i] = c;
       i++;
    }
    printf("Size of ArrNum1: %d\n", sizeof(arrNum1));
    for (int i = 0; i < 5; i++)
    {
        printf("%c\n", arrNum1[i]);
    }
    
    

    return 0;
}