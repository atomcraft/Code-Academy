/*
Задача 8.
Решете задачата за генериране на 6 буквена парола с
пойнтери.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    int i;
    char pass[6];
    char *p = &pass[0];
    char answer;
    do{
        printf("Press enter to get a six-character password\n");
        getchar();

        for ( ; *p < 2; *p++){
            char capLetter = 'A' + (rand() % 26);
            *p = capLetter;
            char letter = 'a' + (rand() % 26);
            *(p + 2) = letter;
            capLetter = 'A' + (rand() % 26);
            *(p + 3) = capLetter;
            printf("%c%c%c", *p, *(p + 2), *(p + 3));
        }
        printf("\n\nDo you like your password? Answer with y for yes and n for no: ");
        answer = getchar();
        if (tolower(answer) == 'y'){
            printf("Your password has been generated.");
        }
    } while(tolower(answer) != 'y');
    return 0;    
}