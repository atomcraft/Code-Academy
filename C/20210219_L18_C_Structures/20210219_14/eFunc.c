#include "employee.h"
#include <stdio.h>
#include <stdlib.h>

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