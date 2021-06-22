/*а) Направете поле 15 на 15, като принтирате тирета в конзолата.
b) Направете точка а(3, 4), като на това място принтирате @
c) Направете точка b(7, 10), като на това място принтирате @
d) Попълнете правоъгълника с @*/

#include <stdio.h>
#include <stdlib.h>
#define IS_POINT_A_INSIDE_MATRIX (a.x >= 0 && a.x <= 15 && a.y >= 0 && a.y <= 15)
#define IS_POINT_B_INSIDE_MATRIX (b.x >= 0 && b.x <= 15 && b.y >= 0 && b.y <= 15)

struct point {
    int x;
    int y;
};

int main(int argc, char* argv[]){
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            printf("-");
        }
        printf("\n");
    }

    printf("\n");
    
    struct point a = {atoi(argv[1]), atoi(argv[2])};
    struct point b = {atoi(argv[3]), atoi(argv[4])};

    if (!IS_POINT_A_INSIDE_MATRIX) {
        printf("Error: Point a is outside the matrix!\n");
        return 1;
    }
    if (!IS_POINT_B_INSIDE_MATRIX) {
        printf("Error: Point b is outside the matrix!\n");
        return 2;
    }

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if ((i == a.x && j == a.y) || (i == b.x && j == b.y)){
                printf("@");
            }
            else {
                printf("-");
            }
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if ((i >= a.x && i <= b.x) && (j >= a.y && j <= b.y)){
                printf("@");
            }
            else {
                printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}
