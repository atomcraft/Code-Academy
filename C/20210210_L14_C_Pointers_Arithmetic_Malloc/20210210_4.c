/*
Задача 4.
Напишете програма, която да генерира случайна парола от 6 букви
докато user-а я хареса.
Вариант 1: може да използвате цикли while/for + стрингове
Вариант 2: използвайте функция
Указания:
1. Генерирайте парола
2. Проверете дали потребителя е харесва
3. Повторете докато потребителя си хареса паролата
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    int i;
    char pass[6];
    char answer;
    do{
        printf("Press enter to get a six-character password\n");
        getchar();

        for (i = 0; i < 2; i++){
            char capLetter = 'A' + (rand() % 26);
            pass[i] = capLetter;
            char letter = 'a' + (rand() % 26);
            pass[i + 2] = letter;
            capLetter = 'A' + (rand() % 26);
            pass[i + 3] = capLetter;
            printf("%c%c%c", pass[i], pass[i + 2], pass[i + 3]);
        }
        printf("\n\nDo you like your password? Answer with y for yes and n for no\n");
        answer = getchar();
        if (tolower(answer) == 'y'){
            printf("Your password has been generated.");
        }
    } while(tolower(answer) != 'y');
    return 0;    
}