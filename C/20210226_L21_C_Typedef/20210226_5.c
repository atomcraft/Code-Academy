/*
Задача 5 Дефинирайте потребителски тип
към масив. Инициализирайте масива, изведете на
конзолата.
*/

#include <stdio.h>

typedef int t_IntArr[3];

int main(void){
    t_IntArr arr = {1, 2, 3};
    for (int i = 0, n = sizeof(arr) / sizeof(arr[0]); i < 3; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;    
}