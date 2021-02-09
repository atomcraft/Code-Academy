/*
7. Напишете един глобален масив, който съдържа на всяка позиция броя на
дните от месеца. Направете функция, която на която се подават като
аргументи година, месец и ден. На база на това функцията трябва да върне
поредния ден от годината. Например 1 март е 60 тия ден от годината.
*/

#include <stdio.h>

static char daysMonth[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30}
};

int dayOfYear(int year, int month, int day);

int main(void){
    int year = 1960;
    int month = 5;
    int day = 27;
    int dayNum = dayOfYear(year, month, day);
    printf("The number of the day in the year is %d", dayNum);
    return 0;
}

int dayOfYear(int year, int month, int day){
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 0; i < month; i++){
        day += daysMonth[leap][i];
    }
    return day;    
}