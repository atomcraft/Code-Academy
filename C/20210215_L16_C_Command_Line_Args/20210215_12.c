/*
Задача 12
Напишете програма, която дефинира масив [10][10][10],
пълни го със случайни числа и смята средното аритметично,
само с един цикъл.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int arr[10][10][10];
    int size = 10;
    int sum = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            for (int k = 0; k < size; k++){
                int n = rand() % 10;
                arr[i][j][k] = n;
                sum += n;
            }            
        }        
    }
    int avg = sum / 10;
    printf("Average: %d\n", avg);
    return 0;  
}