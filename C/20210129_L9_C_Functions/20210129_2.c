#include <stdio.h>
#define PI 3.14

double circleArea(double);
double area(void){
    double r = 0.0L;
    printf("Enter a radius: \n");
    scanf("%lf", &r);
    return r;
}

int main(void){
    double r = area();;
    printf("The area is: %lf\n", circleArea(r));
    return 0;
}

double circleArea(double r){
    return PI * (r * r);
}