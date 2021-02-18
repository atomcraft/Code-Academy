/*
Задача 5.
Намерете стойностите в интервала 1-5, включително, в двумерен масив
[5] [5] пълен със случайни числа в интервала 0-10, включително.
Използвайте функция, която да пълни числата със случайни.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randFill(){
    return rand() % 10;
}

int main(void){
    srand((unsigned)time(0));
    int arr[5][5];
    int size = 5;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            int n = randFill();
            arr[i][j] = n;
            if (arr[i][j] == 1 || arr[i][j] == 2 ||
            arr[i][j] == 3 || arr[i][j] == 4 ||
            arr[i][j] == 5){
                printf("Row: %d , Col: %d, number: %d\n", i, j, arr[i][j]);
            }              
        }        
    }
    return 0;  
}