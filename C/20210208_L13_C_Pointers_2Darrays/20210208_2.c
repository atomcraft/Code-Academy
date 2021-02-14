/*
Задача 2. Дефинирайте и инициализирайте двумерен масив с по 5
елемента (5 x 5). След като сте готови, направете въвеждане на данните в
масива, като четете от потребителя със scanf.
*/

#include <stdio.h>

int main(void){
    int arr[5][5] = {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
        };
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("Enter element %d of row %d : ", j, i);
            scanf("%d", &arr[i][j]);
        }        
    }

    for (int i = 0; i < 5; i++){
        printf("Array %d\n", i);
        for (int j = 0; j < 5; j++){
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }
    return 0;   
}