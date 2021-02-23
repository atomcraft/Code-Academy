/*
Задача 12.
Напишете програма, която използва битови полета. Битовите полета да
са членове на структура и да са от следните типове: unsigned int и char.
Задайте им размер short int 3 бита, char 6 бита. struct <tagStruct> {
Ctype m_bitField : N;
CType2 m_bitField2 : M;
};
Дефинирайте променлива на структурата и инициализирайте ги със
стойност 7 и съответно ‘c’.
Разпечатайте елементите. Разпечатайте и големината на структурата.
Добавете още членове от съществуващите типове и разпечатайте
големината на структурата отново. Пренаредете ги като
последователност, да са char, char, short int, short int. Как се променя
големината на структурата?
Опитайте същото с препроцесор #pragma pack(1)
*/
#include <stdio.h>

struct myStruct{
    unsigned short int m_IntBit : 3;
    char m_CharBit : 6;
};

int main(void){
    struct myStruct myS = {7, 'c'};
    printf("IntBit: %d, CharBit: %c\n", myS.m_IntBit, myS.m_CharBit);
    printf("Size of myStruct: %d\n", sizeof(myS));
    return 0;
}
