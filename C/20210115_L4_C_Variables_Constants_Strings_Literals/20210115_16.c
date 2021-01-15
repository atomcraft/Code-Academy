#include <stdio.h>
#define CONST_PI (3.14159)

void circleRadiusArea(double radius){
    double radiusArea = CONST_PI * radius * radius;
    printf("%lf\n", radiusArea);
}

int main(void){
    circleRadiusArea(1);
    circleRadiusArea(1.5);
    circleRadiusArea(13);
    return 0;
}
