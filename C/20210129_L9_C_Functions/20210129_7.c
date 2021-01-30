#include <stdio.h>

float triangleArea(float a, float b){
    return (0.5) * (a * b);
}

float rectangleArea(float iTriangleArea){
    return iTriangleArea + iTriangleArea;
}

int main(void){
    float a = 0.0F;
    float b = 0.0F;
    printf("Enter side A of the right angle triangle: ");
    scanf("%f", &a);
    printf("Enter side B of the right angle triangle: ");
    scanf("%f", &b);
    float areaTriangle = triangleArea(a, b);
    printf("The area of the triangle is: %0.1f\n", areaTriangle);
    printf("On the basis of the triangle area,"
           " the area of the rectangele is: %0.1f\n", rectangleArea(areaTriangle));
    return 0;
}
