/*
Задача 9. Изведете резултата от деленето на две цели
числа от тип int като double с преобразуване и без такова
*/

#include<stdio.h>

int main(void){
    int iValue = 47;
    int iDiv = 3;
    double dfRes = 0.0;
    double dfRes1 = 0.0;
    dfRes1 = iValue / iDiv;
    dfRes = (double) iValue / iDiv;
    printf("Value of dfRes1of: %lf, V/D: %lf\n", 
    dfRes1, iValue/iDiv);
    printf("Value of dfResof: %lf, V/D: %lf\n",
    dfRes, iValue/iDiv);

    short int siValue = 13;
    int* pValue = (int*)&siValue;
    *pValue = 31;
    printf("%d, %ld", siValue, *pValue);

    char chValue = 'x';
    double* pdValue = (double*)&chValue;
    *pdValue = 0.0;
    printf("%c, %f", chValue, *pdValue);
    free(pValue);
    free(pdValue);

    return 0;
}