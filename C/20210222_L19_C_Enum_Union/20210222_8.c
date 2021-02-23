/*
Задача 8.
Напишете обединение от число и низ, както и описател с изброим
тип за съдържанието на обединението. Напишете функция, която
получава указател към обединението и изброимия тип и извежда
съответно низ или число.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union tagMyUnion{
    int m_nValue;
    char m_String[64];
};

enum eMyType{MY_INT, MY_STR};

void printMyUnion( union tagMyUnion* pUni, enum eMyType type){
    if (MY_INT == type){
        printf("int: %d\n", pUni->m_nValue);
    } else if (MY_STR == type){
        printf("string: %s\n", pUni->m_String);
    }
}

int main(void){
    union tagMyUnion myUni;
    strcpy(myUni.m_String, "test test");
    printMyUnion(&myUni, MY_STR);

    myUni.m_nValue = 9000000;
    printMyUnion(&myUni, MY_INT);
    return 0;
}

