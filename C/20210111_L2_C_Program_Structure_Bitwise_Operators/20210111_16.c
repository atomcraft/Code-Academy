//Task from Slack
#include <stdio.h>

int add (int num1, int num2){
    int x, y;
    do
    {
        x = num1 & num2;
        y = num1 ^ num2;
        num1 = x << 1;
        num2 = y;
    } while (x);
    return y;   
}

int main (){
    printf("%d", add(8, 4));
    return 0;
}