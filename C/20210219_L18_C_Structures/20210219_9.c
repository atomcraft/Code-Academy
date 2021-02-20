/*
Задача 9. Направете функця add(), която събира две точки
*/
#include <stdio.h>

struct point{
    int x;
    int y;
};

struct point makepoint(int x, int y){
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

struct point add(struct point p1, struct point p2){
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

int main(void){
    struct point p1 = {10, 10};
    struct point p2 = {20, 20};
    struct point result = add(p1, p2);
    printf("%d\n", result.x);
    printf("%d\n", result.y);
    return 0;
}