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
int writeToFile(int count,struct myStruct *data, const char *fileName);

int main(void){
    struct myStruct myStructArr[20];
    struct myStruct my1 = {1, "yes", 3.3};
    myStructArr[0] = my1;
    writeToFile(0, &my1, "file.csv");
}

int writeToFile(int count,struct myStruct *data, const char *fileName){
    FILE *f = fopen(fileName, "w");
    if (f == NULL) 
          return -1;
    while (count-- > 0) 
    {
          fprintf(f, "%d,%c,%fl", data->m_int, data->m_char, data->m_double);
          ++data;
    }
    fclose(f);
    return 0;
}