/*
Задача 5. а) Направете поле 15 на 15, като принтирате тирета в конзолата.
b) Направете точка а(3, 4), като на това място принтирате @
c) Направете точка b(7, 10), като на това място принтирате @
d) Попълнете правоъгълника с @
*/
#include <stdio.h>

struct point{
    int x;
    int y;
}a, b;

int main(void){
    char field[15][15];
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            field[i][j] = '-';
        }
        printf("\n");         
    }
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            printf("%c ", field[i][j]);
        }
        
    }
    printf("\n");
    struct point a = {3, 4};
    struct point b = {7, 10};

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if ((i == a.x && j == a.y) || (i == b.x && j == b.y)){
                field[i][j] = '@';
            } 
            else{
                field[i][j] = '-';
            }            
        }
    }
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            printf("%c ", field[i][j]);
        }
        printf("\n");        
    }
    printf("\n");

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if ((i >= a.x && i <= b.x) && (j >= a.y && j <= b.y)){
                field[i][j] = '@';
            } 
            else{
                field[i][j] = '-';
            }            
        }
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
