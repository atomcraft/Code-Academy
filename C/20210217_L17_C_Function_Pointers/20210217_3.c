/*
Задача.3. Направете масив от указатели към функции по
следния начин:
void add(){...}
void fun2(){...}
void fun3(){...}
void (*func_ptr[3])() = {fun1, fun2, fun3};
Направете меню, с което да питате потребителя коя от
горните функции иска да използва – събиране, изваждане,
умножение и деление. След това попитайте за числата, които
да участват в тази операция, и извикайте функцията, която да
извърши желаната операция.
*/

#include <stdio.h>
#include <stdlib.h>

int fnPlus(int nA, int nB) { return(nA + nB); }

int fnMinus(int nA, int nB) { return(nA - nB); }

int fnMultiply(int nA, int nB) { return(nA * nB); }

int fnDivide(int nA, int nB) { return(nA / nB); }

int main(void){
    int answer, num1, num2 = 0;
    int (*funcPtr[4])() = {fnPlus, fnMinus, fnMultiply, fnDivide};
    printf("Enter: \n"
    "1 for addition\n"
    "2 for substraction\n"
    "3 for multiplication\n"
    "4 for division\n");
    scanf("%d", &answer);
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    switch (answer){
    case 1:
        printf("Addition result: %d\n", funcPtr[0](num1, num2));
        break;
    case 2:
        printf("Addition result: %d\n", funcPtr[1](num1, num2));
        break;
    case 3:
        printf("Addition result: %d\n", funcPtr[2](num1, num2));
        break;
    case 4:
        printf("Addition result: %d\n", funcPtr[3](num1, num2));
        break;
    default:
        printf("Invalid operation.\n");
        break;
    }
    return 0;
}