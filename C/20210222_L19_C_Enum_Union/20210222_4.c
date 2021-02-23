/*
Задача 4.
Дефинирайте структура “date” с членове ден, месец, година. Създайте
променлива към структурата “contractdate”. По колко начина можете да
я дефинирате?
Задайте стойност на членовете на структурата по три различни начина.
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
}