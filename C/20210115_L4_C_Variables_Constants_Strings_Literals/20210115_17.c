#include <stdio.h>
#define CONST_PI (3.14159)

void circleRadiusArea(double radius){
    double radiusArea = CONST_PI * radius * radius;
    printf("Circle radius: %lf\n", radiusArea);
}
void elipseArea(double a, double b);

int main(void){
    circleRadiusArea(1);
    circleRadiusArea(1.5);
    circleRadiusArea(13);
    elipseArea(3, 4.5);
    elipseArea(5.6, 7);
    elipseArea(1, 2.5);
    return 0;
}

void elipseArea(double a, double b){
    double elipseArea = CONST_PI * a * b;
    printf("Elipse area: %lf\n", elipseArea);
}
