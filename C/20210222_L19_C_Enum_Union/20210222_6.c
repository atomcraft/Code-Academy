/*
Задача 6.
Опишете времето в структура: часове:минути:секунди като структура tagTMyTime.
Използвайки тази структура, дефинирайте следните функции: добавяне на секунди,
добавяне на минути. Добавяне на часове към дадена променлива от тип struct
tagTMyTime. Напишете следните функции: връщане на броя секунди за дадена
променлива от въведения тип и обратна функция от секундите да се генерира
променлива tagTMyTime. Напишете две функции, които изваждат и събират две
променливи от тип struct tagMyTime и връщат променлива от същия тип.
Използвайте тези функции, за да се уверите, че работят коректно.
*/

#include <stdio.h>
#include <string.h>

struct tagTMyTime{
    int hours;
    int minutes;
    int seconds;
};

int getSeconds(struct tagTMyTime *time);
void addTime(struct tagTMyTime *time, int hours, int minutes, int seconds);
struct tagTMyTime makeTime(int hours, int minutes, int seconds);
struct tagTMyTime sumTime(struct tagTMyTime *t1, struct tagTMyTime *t2);
struct tagTMyTime minTime(struct tagTMyTime *t1, struct tagTMyTime *t2);
void printTime(struct tagTMyTime *time);

int main(void){
    struct tagTMyTime t1=makeTime(15,12,33);
    printf("Time 1: \n");
    printTime(&t1);
    struct tagTMyTime t2=makeTime(10,36,3);
    printf("Time 2: \n");
    printTime(&t2);
    printf("Time 1 secs: %d\n",getSeconds(&t1));
    struct tagTMyTime t3=sumTime(&t1,&t2);
    printf("Time 3: \n");
    printTime(&t3);
    struct tagTMyTime t4=minTime(&t1,&t2);
    printf("Time 4: \n");
    printTime(&t4);
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

void addTime(struct tagTMyTime *time, int hours, int minutes, int seconds){
    hours += time->hours;
    minutes += time->minutes;
    seconds += time->seconds;
    minutes += seconds / 60;
    hours += minutes / 60;
    minutes = minutes % 60;
    seconds = seconds % 60;
    time->hours = hours;
    time->minutes = minutes;
    time->seconds = seconds;
}

int getSeconds(struct tagTMyTime *time){
    return time->seconds;
}

struct tagTMyTime sumTime(struct tagTMyTime *t1, struct tagTMyTime *t2){
    int hours = t1->hours;
    int minutes = t1->minutes;
    int seconds = t1->seconds;
    hours += t2->hours;
    minutes += t2->minutes;
    seconds += t2->seconds;
    minutes += seconds / 60;
    hours += minutes / 60;
    minutes = minutes % 60;
    seconds = seconds % 60;
    return makeTime(hours,minutes,seconds);
}

struct tagTMyTime minTime(struct tagTMyTime *t1, struct tagTMyTime *t2){
    int hours = t1->hours;
    int minutes = t1->minutes;
    int seconds = t1->seconds;
    hours -= t2->hours;
    minutes -= t2->minutes;
    seconds -= t2->seconds;
    if(seconds < 0){
        minutes--;
        seconds += 60;
    }
    if(minutes < 0){
        hours--;
        minutes += 60;
    }
    if(hours < 0){
        printf("Inavalid hours");
        struct tagTMyTime time;
        return time;
    }
    return makeTime(hours, minutes, seconds);
}

void printTime(struct tagTMyTime *time){
    printf("Hours: %d\n",time->hours);
    printf("Minutes: %d\n",time->minutes);
    printf("Seconds: %d\n",time->seconds);
}