/*
Задача 2. Добавете към горния код функции за умножение
и деление.
*/

#include <stdio.h>
#include <stdlib.h>

int fnPlus(int nA, int nB) { return(nA + nB); }

int fnMinus(int nA, int nB) { return(nA - nB); }

int fnMultiply(int nA, int nB) { return(nA * nB); }

int fnDivide(int nA, int nB) { return(nA / nB); }

int main(int argc, char* argv[]) {
    int ( * pfCalc ) ( int, int ) = NULL;
    if (argc < 4){printf("\nUsage: %s + or - or x or / arg1 arg2\n", argv[0]);}
    else if ('-' == argv[1][0]) { pfCalc = fnMinus; }
    else if ('+' == argv[1][0]) { pfCalc = fnPlus; }
    else if ('x' == argv[1][0]) { pfCalc = fnMultiply; }
    else if ('/' == argv[1][0]) { pfCalc = fnDivide; }
    (NULL == pfCalc) ? 0 : printf("\nResult: %d\n",
    (*pfCalc)(atoi(argv[2]), atoi(argv[3])));
    return 0;
}