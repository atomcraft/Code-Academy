#include <stdio.h>

int add (int a, int b){
    return (a + b) * 4;
}

int main(void){
    int a = 0;
    int b = 0;
    printf("Enter value for a: ");
    scanf("%d", &a);
    printf("Enter value for b: ");
    scanf("%d", &b);
    printf("The result of (a+b)*4 is: %d", add(a, b));
    return 0;
}