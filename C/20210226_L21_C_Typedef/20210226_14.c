/*
Задача 14 Напишете програма, в която се въвеждат пореден
номер, име, фамилия, възраст на участници в маратон.
Изискването е, за името и фамилията, да не се използват
масиви с фиксирана дължина. След като въвеждането завърши,
изведете списък с участниците.
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int counter = 0;

typedef struct {
    int pNumber; 
    int pAge;
    char *pFirstName;
    char *pLastName;
} participant;

participant *arrParticipants = NULL;

void participantsEntry();
void participantsDisplay();

int main(void){
    arrParticipants = (participant *) malloc(sizeof(participant));
    if (arrParticipants == NULL) {
        printf("Allocation error.");
        exit(1);
    }
    participantsEntry();
    participantsDisplay();
    return 0;
}

void participantsEntry(){
    char answer;
    char firstName[20];
    char lastName[20];
    do
    {
        arrParticipants = (participant *) realloc(arrParticipants, sizeof(participant) * (counter+1));
        participant *currentParticipant = arrParticipants + counter;
        printf("Enter the first name of the participant: ");
        scanf("%s", &firstName);
        currentParticipant->pFirstName = (char*) malloc(strlen(firstName) + 1);
        if(NULL == currentParticipant->pFirstName){
            printf("Allocation memory error!\n");
            exit(1);
        }
        strcpy(currentParticipant->pFirstName, firstName);
        printf("Enter the last name of the participant: ");
        scanf("%s", &lastName);
        currentParticipant->pLastName = (char*) malloc(strlen(lastName) + 1);
        if(NULL == currentParticipant->pLastName){
            printf("Allocation memory error!\n");
            exit(1);
        }
        strcpy(currentParticipant->pLastName, lastName);
        printf("Enter the age of the participant: ");
        scanf("%d", &currentParticipant->pAge);
        printf("Enter the number of the participant: ");
        scanf("%d", &currentParticipant->pNumber);
        getchar();
        printf("Would you like to enter another participant? Answer with y for yes.");
        scanf("%c", &answer);
        counter++;
    } while (tolower(answer) == 'y');
}

void participantsDisplay(){
    for (int i = 0; i < counter; i++){
        printf("First name of the participant: %s\n", (arrParticipants + i)->pFirstName);
        free((arrParticipants + i)->pFirstName);
        printf("Second name of the participant: %s\n", (arrParticipants + i)->pLastName);
        free((arrParticipants + i)->pLastName);
        printf("Number of the participant: %d\n", (arrParticipants + i)->pNumber);
        printf("Age of the participant: %d\n", (arrParticipants + i)->pAge);
    }
    free(arrParticipants);
}
