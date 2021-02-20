/*
Задача 7. Направете функция struct point makepoint(int x, int y), която
създава две точки.
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

int main(void){
    struct point p1 = makepoint(10, 10);
    struct point p2 = makepoint(20, 20);
    return 0;
}
