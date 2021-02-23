#include <stdio.h>

union tagUTest{
    int m_iNum;
    float m_fRate;
    union tagUTest* puniNext;
}; /* sizeof(union tagUTest) -> 4 Bytes, pointer tagUTest* is 8 Bytes, thus
the whole union is 8 Bytes*/

int main(void){
    union tagUTest uniVar = { 0 };
    union tagUTest* puniVal = &uniVar;
    uniVar.m_iNum = 13;
    puniVal->m_fRate = 6.78; /* достъп с указател */
    printf("Size of tagUTest: %d\n", sizeof(uniVar));
    return 0;
}

