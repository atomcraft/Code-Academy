/*
Задача 7.
Напишете обединение от три стойности: цяло число, число с
плаваща запетая и низ. Инициализирайте отделните членове и ги
изведете на екрана.
*/

#include <stdio.h>

union tagUTest{
    int m_iNum;
    float m_fRate;
    char m_String[32];
};

int main(void){
    union tagUTest uniVar = { 13 };
    printf("Memory size: %d\n", sizeof(uniVar));
    printf("iNum: %d, m_fRate: %f, String: %s\n", uniVar.m_iNum, uniVar.m_fRate, uniVar.m_String);
    return 0;
}


