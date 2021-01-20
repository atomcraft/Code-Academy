#include <stdio.h>

int main(void){
    printf("Enter value for a: ");
    int a = 0;
    scanf("%d", &a);
    printf("Enter value for b: ");
    int b = 0;
    scanf("%d", &b);
    // int n = 5;
    int sum = 0;
    if (a > b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    while (b >= a){
        sum += a;
        a++;
    }
    printf("%d", sum);
    return 0;    
}