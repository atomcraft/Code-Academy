/*
Задача 1. Дефинирайте и инициализирайте едномерен масив с 5
елемента. След като сте готови, направете въвеждане на данните в
масива, като четете от потребителя със scanf.
*/

#include <stdio.h>

int main(void){
    int arr[5];
    for (int i = 0, n = sizeof(arr) / sizeof(arr[0]); i < n; i++){
        printf("Enter element %d : ", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0, n = sizeof(arr) / sizeof(arr[0]); i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;       
}