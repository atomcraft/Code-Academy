#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    // long arrNum[3];
    // arrNum[0] = 1;
    // arrNum[1] = 2;
    // arrNum[2] = 3;
    // int size = sizeof(arrNum);
    // printf("%d", size);
    // int arrNum1[3];
    // int i = 0;
    // char c;
    // while (i < 4)
    // {
    //     c = getchar();
    //    arrNum1[i] = c;
    //    i++;
    // }
    // printf("Size of ArrNum1: %d\n", sizeof(arrNum1));
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%c\n", arrNum1[i]);
    // }
    char *s = "HI!";
    for (int i = 0, n = strlen(s); i < n; i++){
        printf("%c\n", s[i]);
    }
    printf("%d\n", strlen(s)); 
    char *t = malloc(strlen(s) + 1);
    printf("%d\n", strlen(t));
    for (int i = 0, n = strlen(s); i <= n; i++){
        t[i] = s[i];
    }
    for (int i = 0, n = strlen(t); i < n; i++){
        printf("%c\n", t[i]);
    } 
    printf("%d\n", strlen(t));
    free(t);   

    return 0;
}