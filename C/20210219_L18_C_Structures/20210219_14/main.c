/*
Задача 14. Използвайки предишното упражнение, опишете структурите и
прототипите на функциите в отделен заглавен файл с разширение *.h, a
телата на функциите в един или няколко *.c сорс файлове.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "employee.h"


int main(void){
    srand(time(NULL));

    struct employee employees[10];
    fillEmployeeArray(employees,10);
    employees[0].manager = &employees[9];
    for(int i = 1; i < 10;i++){
        employees[i].manager = &employees[i-1];
    }
    printEmployees(employees,10);
    return 0;
}

