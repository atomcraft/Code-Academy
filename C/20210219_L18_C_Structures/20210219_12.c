/*
Задача 12. Напишете функция, която изчислява разстоянието между две
точки в равнината. Нека функцията да приема два параметъра, които са
структури ТPoint с два члена X и Y координати.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

struct TPoint{
    int x;
    int y;
};

struct TPoint makePoint(int x,int y);
float calcDis(struct TPoint *p1,struct TPoint *p2);

int main(void){
    struct TPoint p1=makePoint(2,3);
    struct TPoint p2=makePoint(5,7);
    printf("%.3f",calcDis(&p1, &p2));
    return 0;
}

struct TPoint makePoint(int x,int y){
    struct TPoint point={x,y};
    return point;
}

float calcDis(struct TPoint *p1, struct TPoint *p2){
    int disX,disY;
    int x1,x2,y1,y2;
    if(p1->x < p2->x){
        x1=p1->x;
        x2=p2->x;
    }else{
        x1=p2->x;
        x2=p1->x;
    }
    if(p1->y<p2->y){
        y1=p1->y;
        y2=p2->y;
    }else{
        y1=p2->y;
        y2=p1->y;
    }
    disX=x2-x1;
    disY=y2-y1;
    float result = sqrt((disX*disX)+(disY*disY));
    return result;
}

