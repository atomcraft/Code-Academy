/*
Задача 10.
Използвайки горните две задачи като база, обединете
обединението и описателя в една структура. Напишете функция,
която извежда съдържанието на новата структура.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum eMyType{VALUE_INT, VALUE_STR};

union tagMyUnion{
    int m_nValue;
    char m_String[64];
};

struct tagMyStruct{
    enum eMyType m_type;
    union tagMyUnion m_var;
};

void printValue(struct tagMyStruct* pValue){
    if (VALUE_INT == pValue->m_type){
        printf("int: %d\n", pValue->m_var.m_nValue);
    } else if (VALUE_STR == pValue->m_type){
        printf("str: %s\n", pValue->m_var.m_String);
    }    
}

int main(void){
    struct tagMyStruct value = {VALUE_INT, 12345};
    printValue(&value);
    value.m_type = VALUE_STR;
    strcpy(value.m_var.m_String, "test test");
    printValue(&value);
    return 0;
}
