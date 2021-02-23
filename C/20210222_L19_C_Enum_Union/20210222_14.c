/*
Задача 14.
Напишете тип за дата, използвайки битови полета. Направете
функция, която извежда дата, използвайки новия тип. Направете
функция, която валидира датата.
*/

#include <stdio.h>
#include <string.h>

struct tagTMyTime{
    int hours : 4;
    int minutes : 4;
    int seconds: 4;
};

struct tagTMyTime makeTime(int hours, int minutes, int seconds);
void printTime(struct tagTMyTime *time);

int main(void){
    struct tagTMyTime t1=makeTime(15,12,33);
    printf("Time 1: \n");
    printTime(&t1);
    return 0;
}

struct tagTMyTime makeTime(int hours, int minutes, int seconds){
    minutes += seconds / 60;
    hours += minutes / 60;
    minutes = minutes % 60;
    seconds = seconds % 60;
    struct tagTMyTime time={hours, minutes, seconds};
    return time;
}

void printTime(struct tagTMyTime *time){
    printf("Hours: %d\n",time->hours);
    printf("Minutes: %d\n",time->minutes);
    printf("Seconds: %d\n",time->seconds);
}