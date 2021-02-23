/*
Задача 9.
Напишете функция, която преобразува число в низ и обратното,
като използва описанието от предишната задача.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union tagMyUnion{
    int m_nValue;
    char m_String[64];
};

enum eMyType{INT_TO_STR, STR_TO_INT};

union tagMyUnion convertUni( union tagMyUnion* pUni, enum eMyType type){
    union tagMyUnion ret;
    if (INT_TO_STR == type){
        sprintf(ret.m_String, "00%d", pUni->m_nValue);
    } else if (STR_TO_INT == type){
        ret.m_nValue = atoi(pUni->m_String);
    }
    return ret;    
}

int main(void){
    union tagMyUnion myUni, converted;
    strcpy(myUni.m_String, "0088");
    converted = convertUni(&myUni, STR_TO_INT);
    printf("Original: %s, converted: %d\n", myUni.m_String, converted.m_nValue);
    myUni.m_nValue = 12345;
    converted = convertUni(&myUni, INT_TO_STR);
    printf("Original: %d, converted: %s\n", myUni.m_nValue, converted.m_String);
    return 0;
}
