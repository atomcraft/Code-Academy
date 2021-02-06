/*
Задача 13. Дефинирайте и инициализирайте двумерен масив с по 5
елемента (5 x 5). След като сте готови, направете въвеждане на данните в
масива, като четете от потребителя със scanf.
*/

#include <stdio.h>

int main(void){
    int arr[][5] = {{0,0,0,0,0},{0,0,0,0,0}};
    for (int i = 0, n = sizeof(arr) / sizeof(arr[0]); i < n; i++){
        for (int j = 0; j < n; j++){
            printf("Enter element %d of row %d : ", j, i);
            scanf("%d", &arr[i][j]);
        }        
    }

    for (int i = 0, n = sizeof(arr) / sizeof(arr[0]); i < n; i++){
        for (int j = 0; i < n; i++){
            printf("%d ", arr[i][j]);
        }
    }
    return 0;   
}