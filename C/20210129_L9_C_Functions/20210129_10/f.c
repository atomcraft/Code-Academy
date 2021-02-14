/*#include <stdio.h>*/
#include "f.h"
#include <math.h>

int leastCommMultiple( int a, int b){
    int num1, num2, lcm, temp, gcd;
    num1 = a;
    num2 = b;
    while (num2 != 0) {
        temp = num2;
 	    num2 = num1 % num2;
 	    num1 = temp;
    }
    gcd = num1; /*Greatest common divider - gcd*/
    /*printf("\nGCD of %d and %d = %d \n", a, b, gcd);*/
    
    lcm = (a * b) / gcd; /*Least common multiple - lcm*/
    /*printf("\nLCM of %d and %d = %d\n", a, b, lcm);*/
    return lcm;

}
/*Returns the absolute value of the number, can work with int as well*/
float absoluteValue(float num){
    if (num < 0){
        num = -num;
    }
    return num;    
}

float sqRoot(float num){
    if (num < 0){
        return -1;
    } else{
        return sqrt(num);
    }    
}