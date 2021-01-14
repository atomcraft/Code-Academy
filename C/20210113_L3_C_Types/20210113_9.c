#include <stdio.h>
#include <float.h>

int main(){
    float a = 4.9876543;
    long double b = 7.123456789012345678890;
    long double c = 18398458438583853.28;
    long double d = 18398458438583853.39875937284928422;

    printf("%f\n", a);
    printf("\n%1.21Lf\n", b);
    printf("\n%0.2Lf\n", c);
    printf("\n%0.17Lf\n", d);
    printf("\n%Le\n", c); // exponential format
    printf("\n%Le\n", d); // exponential format
    return 0;
}