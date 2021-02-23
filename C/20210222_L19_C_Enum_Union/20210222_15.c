/*
Задача 15.
Дефинирайте структура с 4 полета (int. char[10], double, enum),
направете масив от 20 структури и ги попълнете. Изведете масива
от структури на стандартния изход в CSV формат (
https://en.wikipedia.org/wiki/Comma-separated_values ). Пример:
prog1 > structs20.cvs
*/
#include <stdio.h>

struct myStruct{
    int m_int;
    char m_char[10];
    double m_double;
    enum m_enum;
};

enum eMyType{VALUE_INT, VALUE_STR};

int main(void){
    struct myStruct myStructArr[20];
    struct myStruct my1 = {1, "yes", 3.3, VALUE_STR};
}