#include <stdio.h>
#include <math.h>

int add(int a, int b);
int powOfTwo(int num);
int sqroot (int num);

int main(void){
    int num1 = 0, num2 = 0;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    add(num2, num2);
    return 0;
}

int add(int a, int b){
    return a + b;
}
int powOfTwo(int num);
int sqroot (int num);
