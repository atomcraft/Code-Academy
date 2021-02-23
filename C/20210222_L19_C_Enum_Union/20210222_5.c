/*
Задача 5.
Направете масив от 10 структури от задача 4. Задайте стойност на 10 -те дати, по избор.
*/

#include <stdio.h>

struct date{
    int day;
    int month;
    int year;
};

int main(void){
    struct date date1 = {21,2,2020};
    struct date date2;
    date2.day = 21;
    date2.month = 2;
    date2.year = 2020;
    struct date date3 = {.day = 21, .month = 2, .year = 2020};
    struct date array[10]; /* define array */
    array[0].day = 22; /* set member value */
    array[0].month = 2;
    array[0].year = 2020;
    struct date array2[10]= { {1,3,2019}, {3,4,2020}}; /* define and init array members */
    struct date array3[10] = { [1] = {3,4,2020} }; /* define and init array members */
    struct date array4[10] = {[1].month = 4,[1].year = 2020}; /* define and init array members */
    return 0;
}