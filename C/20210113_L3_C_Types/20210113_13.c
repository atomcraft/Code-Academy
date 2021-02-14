#include <stdio.h>

int main(){
    char a;
    int b;
    long c;
    float d;
    double e;
    
    // a = 'a';
    // b = 102;
    // c = 50000;
    // d = 6;
    // e = -48.907;

    printf("Enter value of a: ");
    scanf("%c", &a);
    printf("%c\n", sizeof(a));
    printf("Enter value of b: ");
    scanf("%d", &b);
    printf("%d\n", sizeof(b));
    printf("Enter value of c: ");
    scanf("%ld", &c);
    printf("%ld\n", sizeof(c));
    printf("Enter value of d: ");
    scanf("%f", &d);
    printf("%0.1f\n", sizeof(d));
    printf("Enter value of e: ");
    scanf("%lf", &e);
    printf("%0.3f\n", sizeof(e));
}