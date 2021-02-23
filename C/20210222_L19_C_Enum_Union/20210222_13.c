/*
Задача 13.
Направете обединение с членове unsigned short и char. Ограничете
използваните битове до 6. Инициализирайте и изведете на
конзолата.
union <tagUnion> {
Ctype m_bitField : N;
};
*/

#include <stdio.h>

union myUnion{
    unsigned short int m_IntBit : 6;
    char m_CharBit : 6;
};

int main(void){
    union myUnion myU;
    myU.m_IntBit = 7;
    myU.m_CharBit = 'c';
    printf("IntBit: %d, CharBit: %c\n", myU.m_IntBit, myU.m_CharBit);
    printf("Size of myStruct: %d\n", sizeof(myU));
    return 0;
}


