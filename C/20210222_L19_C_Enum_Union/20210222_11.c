/*
Задача 11.
Направете обединение с елементи тип int, int, char. Дайте
стойност на елементите един по един -7,10 и “c” и изведете
тези стойности на конзолата.
Инициализирайте и трите и изведете стойностите им на
конзолата
*/

#include <stdio.h>

union myUnion{
    char m_c;
    int m_iNum1;
    int m_iNum2;
}; 

int main(void){
    union myUnion uniVar;
    uniVar.m_c = 'c';
    uniVar.m_iNum1 = -7;
    uniVar.m_iNum2 = 10;
    printf("My Union Char: %c\n", uniVar.m_c);
    printf("My Union int Num1: %d\n", uniVar.m_iNum1);
    printf("My Union int Num2: %c\n", uniVar.m_iNum2);
    return 0;
}


