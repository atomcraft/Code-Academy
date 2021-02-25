/*
Задача 7. Напишете макрос, който прави идентификатор на низ
(стринг)
*/
#include <stdio.h>

#define MY_STR(x) #x

int main(void){
    int nValue = 0;
    printf(MY_STR(nValue));
    printf("\n");
    return 0;
} 