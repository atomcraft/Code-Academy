/*
Задача 11.
Напишете програма, която да генерира парола с малки букви (i),
специални символи (j), големи букви (k) и цифри (l), ама разбъркано.
Използвайте функции. 

Насоки:
1. Въвежда се дължина на паролата, колко символа от нея са малки
букви (a..z), големи букви( A..Z ), колко са цифрите (0..9), колко
специални символи (@#$%!^&*).
2. Използва се генератор на случайни числа за символите и тяхната
позиция

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 1000

void passGenerator(char *pass, int passLen, int numLowCapLet, int numUpCapLet,
int numNumb, int numSymb);

int main(void){
    srand((unsigned int)(time(NULL)));
    int i, passLen, numLowCapLet, numUpCapLet, numNumb, numSymb;
    char pass[MAX];
    printf("Enter the password length: ");
    scanf("%d", &passLen);
    printf("Enter the number of low capital letters: ");
    scanf("%d", &numLowCapLet);
    printf("Enter the number of upper capital letters: ");
    scanf("%d", &numUpCapLet);
    printf("Enter the number of numbers: ");
    scanf("%d", &numNumb);
    printf("Enter the number of symbols: ");
    scanf("%d", &numSymb);
    passGenerator(pass, passLen, numLowCapLet, numUpCapLet, 
    numNumb, numSymb);
    return 0;
}

void passGenerator(char *pass, int passLen, int numLowCapLet, int numUpCapLet,
int numNumb, int numSymb){
    int i;
    int lettersNum = 26;
    int maxNum = 9;
    int maxSymbols = 15;
    for (i = 0; i < passLen / 4; i++){
        pass[i] = rand() % maxNum;
        char capLetter = 'A' + (rand() % lettersNum);
        pass[i + 2] = capLetter;
        char letter = 'a' + (rand() % lettersNum);
        pass[i + 3] = letter;
        char symbol = '!' + (rand() % maxSymbols);
        pass[i + 4] = symbol;
        printf("%d%c%c%c", pass[i], pass[i + 2], pass[i + 3], pass[i + 4]);
    }
    printf("\n\n");

}