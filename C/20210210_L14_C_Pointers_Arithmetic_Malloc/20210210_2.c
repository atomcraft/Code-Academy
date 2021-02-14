/*
Задача 2. Напишете програма, която чете съобщение, след което го
принтира в обратен ред:
Enter a message: I am Miro.
Reversal is : .oriM ma I
Използвайте getchar() за да вземете символите от конзолата, запазете ги в
масив от чарове, прекратете четенето до достигане на \n. Използвайте
пойнтер, който да сочи към текущата позиция на масива. Чрез него
принтирайте масива в обратен ред.
*/

#include <stdio.h>
#define SIZE 1000

int main(void){
    char c;
    char arr[SIZE];
    char *p = arr;
    int i = 0;
    printf("Enter a message: ");
    while ((c = getchar()) != '\n'){
        arr[i] = c;
        i++;
        p = p + 1;
    }

    printf("Reversal is: ");
    while (i > 0){
        --p;
        putchar(*p);
        i--;
    }
    return 0;    
}