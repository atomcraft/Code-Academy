/*
Задача 8. Направете структура struct rect, която съдържа в себе си две
точки. Създайте обект от тип тази структура наречен screen. Използвайте
функцията makepoint за да зададете начална точка на екрана (0, 0) и
крайна точка (15, 15). Запълнете пространството между тях с тирета.
*/
#include <stdio.h>

struct point{
    int x;
    int y;
};

struct rect{
    struct point p1;
    struct point p2;
};


struct point makepoint(int x, int y){
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int main(void){
    struct rect screen;
    screen.p1 = makepoint(0, 0);
    screen.p2 = makepoint(15, 15);
    for (int i = screen.p1.x; i < screen.p2.x; i++){
        for (int j = screen.p1.y; j < screen.p2.y; j++){
            printf("-");
        }
        printf("\n");        
    }
    return 0;
}