#include <stdio.h>
#define PI 3.14

float circleArea(float);

int main(void){
    float radius = 2.5;
    printf("The circle area is: %0.3f\n", circleArea(radius));
    return 0;
}

float circleArea(float r){
    return PI * (r * r);
}