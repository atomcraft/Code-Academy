#include <math.h>
#include "f.h"
/*#include <stdio.h>*/

double sqRoot (double num){
    double num1 = pow2(num);
    /*printf("\n %lf", num1);*/
    return sqrt(num1);
}

double pow2(double num){
    double num1 = addToItself(num);
    /*printf("\n %lf", num1);*/
    return num1 * num1;

}

double addToItself(double num){
    return num + num;
}