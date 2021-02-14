/*
Задача 11.
Напишете програма, в която се въвеждат пореден номер,
име, фамилия, възраст на участници в маратон. Изискването
е за името и фамилията да не се използват масиви с
фиксирана дължина. След като въвеждането завърши,
изведете списък с участниците. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

void participantsEntry();
void participantsDisplay();

const char buffer = 16;
int pNumber[MAX]; 
int pAge[MAX];
char firstName[20];
char lastName[20];
char *pFirstName[MAX];
char *pLastName[MAX];
int counter = 0;

int main(void){
    participantsEntry();
    participantsDisplay();
    return 0;
}

void participantsEntry(){
    char c;
    char answer;
    do
    {
        printf("Enter the first name of the participant: ");
        scanf("%s", &firstName);
        pFirstName[counter] = (char*) malloc(strlen(firstName) + 1);
        if(NULL == pFirstName[counter]){
            printf("Allocation memory error!\n");
            exit(1);
        }
        strcpy(pFirstName[counter], firstName);
        printf("Enter the last name of the participant: ");
        scanf("%s", &lastName);
        pLastName[counter] = (char*) malloc(strlen(lastName) + 1);
        if(NULL == pLastName[counter]){
            printf("Allocation memory error!\n");
            exit(1);
        }
        strcpy(pLastName[counter], lastName);
        printf("Enter the age of the participant: ");
        scanf("%d", &pAge[counter]);
        printf("Enter the number of the participant: ");
        scanf("%d", &pNumber[counter]);
        getchar();
        printf("Would you like to enter another participant? Answer with y for yes.");
        scanf("%c", &answer);
        counter++;       
    } while (tolower(answer) == 'y');

}

void participantsDisplay(){
    for (int i = 0; i < counter; i++){
        printf("First name of the participant: %s\n", pFirstName[i]);
        free(pFirstName[i]);
        printf("Second name of the participant: %s\n", pLastName[i]);
        free(pLastName[i]);
        printf("Number of the participant: %d\n", pNumber[i]);
        printf("Age of the participant: %d\n", pAge[i]);
    }
}
