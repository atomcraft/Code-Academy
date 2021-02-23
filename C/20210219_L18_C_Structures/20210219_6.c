/*
Задача 6. Направете по подобен начин триъгълник:
*/
#include <stdio.h>

struct point{
    int x;
    int y;
}a, b;

int main(void){
    char field[15][15];
    char symbol = '@';
    struct point a = {3, 4};
    struct point b = {7, 10};
    int indx = 0;
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            field[i][j] = '-';
        }         
    }
    for (int i =0; i <= 15; i++){
        for (int j = 0; j <= i; j++){
            if ((i >= a.x && i <= b.x) && (j >= a.y && j <= b.y)){
                field[i][j] = symbol;
            }         
        }
        indx++;
    }
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            printf("%c ", field[i][j]);
        }
        printf("\n");        
    }
    printf("\n");
    return 0;
}