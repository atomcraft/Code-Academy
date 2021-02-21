/*
Задача 13. Представете служителите във фирма в структура с членове:
пореден номер, име, презиме, фамилия, позиция, трудов стаж в години,
заплата в лева, указател към структурата, описващ неговия началник.
Напишете програма, която въвежда 10 служителя, които се съхраняват в
масив от описаните структури. Въвеждането на служителите може да стане
на два паса, първо въвеждане на всички данни без указателя към
началника и на втори пас, указване на всеки служител кой е неговият
началник.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct experience{
    int years;
    int months;
};

struct employee{
    int id;
    char *name;
    char *middleName;
    char *lastName;
    char *job;
    struct experience experience;
    int pay;
    struct employee *manager;
};

struct experience makeExperience(int years, int months);
struct employee makeEmployee(int id, char *name, char *middleName,
char *lastName, char *job, struct experience experience, int pay);
void fillEmployeeArray(struct employee arr[], int size);
void printEmployees(struct employee arr[], int size);

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

struct experience makeExperience(int years, int months){
    years+=months / 12;
    months=months % 12;
    struct experience experience = {years,months};
    return experience;
}

struct employee makeEmployee(int id, char *name, char *middleName,
char *lastName, char *job, struct experience experience, int pay){
    struct employee employee = {id, name, middleName, lastName, job,
    experience, pay, NULL};
    return employee;
}

void fillEmployeeArray(struct employee arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i] = makeEmployee(rand()%1000,"Todor", "Ivanov"," Todorov",
        "Manager", makeExperience(rand()%10,(rand()%12)+1),rand()%3000+1000);
    }
}


void printEmployees(struct employee arr[], int size){
    for(int i = 0; i < size; i++){
        printf("Id: %d\n",arr[i].id);
        printf("First name: %s\n",arr[i].name);
        printf("Middle name: %s\n",arr[i].middleName);
        printf("Last name: %s\n",arr[i].lastName);
        printf("Job: %s\n",arr[i].job);
        printf("Experience: %d yers %d months\n",arr[i].experience.years,
        arr[i].experience.months);
        printf("Pay: %d\n",arr[i].pay);
        printf("Manager id: %d\n",arr[i].manager->id);
        printf("\n\n");
    }
}