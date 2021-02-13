/*
Задача 12.
Използвайки предишното упражнение, изведете участниците
подредени по азбучен ред.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void participantsEntry();
void participantsDisplay();
void namesSort(int );
void memAllocate(char *s);
void memReAllocate(char *s);

const char buffer = 64;
int number[100]; 
int age[100];
char *firstName = NULL;
char *fNameArr;
char *lNameArr;
char *lastName = NULL;
char answer;

int main(void){
    memAllocate(fNameArr);
    memAllocate(lNameArr);
    participantsEntry();
    int sizeArr = sizeof(fNameArr) / sizeof(fNameArr[0]);
    namesSort(sizeArr);
    participantsDisplay();
    return 0;
}

void participantsEntry(){
    int i = 0;
    do
    {
        printf("Enter the first name of the participant: ");
        scanf("%d", firstName);
        fNameArr[i] = *firstName;
        if (buffer < strlen(fNameArr)){
            memReAllocate(fNameArr);
        }
        memAllocate(lastName);
        printf("Enter the last name of the participant: ");
        scanf("%d", lastName);
        lNameArr[i] = *lastName;
        if (buffer < strlen(lNameArr)){
            memReAllocate(lNameArr);
        }
        printf("Enter the age of the participant: ");
        scanf("%d", &age[i]);
        printf("Enter the number of the participant: ");
        scanf("%s", &number[i]);
        getchar();
        printf("Would you like to enter another participant? Answer with y for yes.");
        scanf("%c", &answer);
        i++;       
    } while (tolower(answer) == 'y');

}

void participantsDisplay(){
    for (int i = 0, n = strlen(fNameArr); i < n; i++){
        printf("First name of the participant: %s", fNameArr[i]);
        printf("Second name of the participant: %s", lNameArr[i]);
        printf("Number of the participant: %d", number[i]);
        printf("Age of the participant: %d", age[i]);
    }
}

void memAllocate(char *s){
    s = (char*) malloc(buffer * sizeof(char));
    if(NULL == s){
        printf("Allocation memory error!\n");
        exit(1);
    }
}

void memReAllocate(char *s){
    s = realloc(s, (2 * buffer) * sizeof(char));
    if(NULL == s){
        printf("Reallocation memory error!\n");
        exit(2);
    }
}

void namesSort(int size){
    int i, j;
    for(i = 0; i <= size; i++){
        for(j = i + 1; j <= size; j++){
            if(strcmp(fNameArr[i],fNameArr[j])>0){
                char *temp;
                strcpy(temp,fNameArr[i]);
                strcpy(fNameArr[i],fNameArr[j]);
                strcpy(fNameArr[j],temp);
            }
            if(strcmp(lNameArr[i],lNameArr[j])>0){
                char *temp1;
                strcpy(temp1,lNameArr[i]);
                strcpy(lNameArr[i],lNameArr[j]);
                strcpy(lNameArr[j],temp1);
            }
        }
    }
    
}