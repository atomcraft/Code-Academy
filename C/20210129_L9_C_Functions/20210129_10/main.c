#include <stdio.h>
#include <math.h>

int leastCommMultiple( int a, int b);
float absoluteValue(float num);
float sqroot(float num);

int main(void){
    float a = 0.0F;
    float b = 0.0F;
    int num1 = 10;
    int num2 = 25;
    printf("Enter number A: ");
    scanf("%f", &a);
    printf("Enter number B: ");
    scanf("%f", &b);
    // float abs = absoluteValue(a);
    // printf("A: %f\n", abs);
    // printf("Sqrt of a: %f\n", sqroot(a));
    printf("\n");
    leastCommMultiple(num1, num2);
    printf("\n");
    float sqrtRzs = sqroot(a);
    if (sqrtRzs < 0){
        a = absoluteValue(a);
        printf("Sqrt of a: %f\n", sqroot(a));
    } else{
        printf("Sqrt of a: %f\n", sqrtRzs);
    }
    
    
    return 0;
}

int leastCommMultiple( int a, int b){
    int num1, num2, lcm, temp, gcd;
    num1 = a;
    num2 = b;
    while (num2 != 0) {
        temp = num2;
 	    num2 = num1 % num2;
 	    num1 = temp;
    }
    gcd = num1;
    printf("GCD of %d and %d = %d \n", a, b, gcd);
    
    lcm = (a * b) / gcd;
    printf("LCM of %d and %d = %d", a, b, lcm);
    return lcm;

}

float absoluteValue(float num){
    if (num < 0){
        num = -num;
    }
    return num;    
}

float sqroot(float num){
    if (num < 0){
        return -1;
    } else{
        num = absoluteValue(num);
        return sqrt(num);
    }    
}