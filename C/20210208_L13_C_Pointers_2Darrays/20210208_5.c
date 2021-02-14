/*
Задача 5*. Напишете програма, която генерира “случайна разходка” из
елементите на двумерен масив от тип char с размер 10 х 10. Преди разходката
всички елементи на масива съдържат символа ‘.’ и след като елемента е
посетен в него се записва поредната буква от латинската азбука т.е. на първия
посетен елемент се записва буквата ‘А’, а нз последния буквата ‘Z’. Програмата
трябва да се разхожда от елемент на елемент в следната последователност:
от елемента, на който е в момента може да се премести един елемент на горе,
на долу, на ляво или на дясно. Не може да се премества на произволна
позиция. Преди всяко преместване проверете дали няма да излезете извън
масива и дали позицията вече не е заета от някоя буква т.е. елемента да е
посетен вече. Ако горните условия са изпълнени се преместете в желатана
посока. Ако всичките 4 дестинации са блокирани вашата програм трябва да
спре.
*/
#include <stdio.h>
#include <stdlib.h>

/*
Не работи правилно. Не ми стигна времето до 15:00, ще я оправя вечерта.
*/

int main(void){
    char c[10][10] = {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    char positionRow = 0;
    char positionCol = 0;
    char letter = 'A';
    for (int row = 0; row < 10; row++){
        /*int n = rand() % 4;*/
        for (int col = 0; col < 10; col++){
             if (letter >= 'Z'){
                letter = 'A';
            }
            int n = rand() % 4;
            c[row][col] = letter;
            letter = letter + 1;
            printf("%c ", c[row][col]);
            if (n == 1){ /* 1 - move up */
                positionRow = row - 1;
                if (c[positionRow][positionCol] < 0 || c[positionRow][positionCol] > 10 
                || c[positionRow][positionCol] != '.'){
                    printf("%c ", c[row][col]);
                    continue;
                }
                letter = letter + 1;
                c[positionRow][positionCol] = letter;
                printf("%c ", c[positionRow][positionCol]); 
                row++;
            } else if (n == 2){ /* 2 - move down */
                positionRow = row + 1;
                if (c[positionRow][positionCol] < 0 || c[positionRow][positionCol] > 10
                || c[positionRow][positionCol] != '.'){
                    printf("%c ", c[row][col]);
                    continue;
                }
                letter = letter + 1;  
                c[positionRow][positionCol] = letter + 1;
                printf("%c ", c[positionRow][positionCol]);
                row++;
            } else if (n == 3){ /* 3 - move left */ 
                positionCol = col - 1;
                if (c[positionRow][positionCol] < 0 || c[positionRow][positionCol] > 10
                || c[positionRow][positionCol] != '.'){
                    printf("%c ", c[row][col]);
                    continue;
                }
                letter = letter + 1;
                c[positionRow][positionCol] = letter;
                printf("%c ", c[positionRow][positionCol]);
                col++;
            } else if (n == 4){ /* 4 - move right */
                positionCol = col + 1;
                if (c[positionRow][positionCol] < 0 || c[positionRow][positionCol] > 10
                || c[positionRow][positionCol] != '.'){
                    printf("%c ", c[row][col]);
                    continue;
                }
                letter = letter + 1;
                c[positionRow][positionCol] = letter;
                printf("%c ", c[positionRow][positionCol]);
                col++;
            }    
            
        }
        if (positionRow < 0 || positionRow > 10){
            break;
        }
        if (letter >= 'Z'){
            letter = 'A';
        }
        printf("%c ", c[positionRow][positionCol]);
        printf("\n");
        positionRow = row;        
    }
    /*
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%c ", c[i][j]);
        }
        printf("\n");        
    }
    */
    return 0;   
}