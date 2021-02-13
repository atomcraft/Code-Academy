/*
Задача 13.
Ако x е реално число, а y — естествено, то степен се
дефинира по следния начин: x на степен y = x.x. ... .x (y пъти)
Когато y < 0, то x на y = 1 / x -y . Валидни са свойствата (x 0):
x y = x y-1 .x x y = x y+1/x x y1+y2 = x y1 .x y2 x y1 .y2 = (x y1 )
y2
Тривиалната реализация за пресмятане на x y е чрез
извършване на y последователни умножения.
*/
#include <stdio.h>

float power(int x, int y);

int main(void){
    int num1 = 0;
    int num2 = 0;
    printf("Please neter the 1st number: ");
    scanf("%d", &num1);
    printf("Please neter the 1st number: ");
    scanf("%d", &num2);
    float result = power(num1, num2);
    printf("The power of num1 and num2 is: %.1f", result);
    return 0;
}

float power(x,y){
    float p=1.00;
    float xx = (float)x;
    int i;
    if (y<0){
        y=-1*y;
        xx=1/xx;
    }
    for (i=1;i<=y;i++){
        p=p*xx;
    }
    return p;
}
