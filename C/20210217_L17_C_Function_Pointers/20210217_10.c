/*
Задача 10.
Да намерим простите числа до 1000 и да ги сложим в масив.
Да напишем функция, която да ни казва дали дадено число от 0 - до 1000
е просто.
Просто число е се нарича всяко естествено число, по-голямо от 1,
което има точно два естествени делителя – 1 и самото себе си.
Например 5 е просто, защото се дели единствено на 1 и 5, докато 6 не
е, защото се дели освен на 1 и 6, и на 2 и 3
*/

#include <stdio.h>

int main(void){
    int count = 0;
    int num = 1000;
    int arrNum[1000];
    for (int i = 1; i <= num; i++){
        for (int j = 1; i <= i; j++){
            if (i % j == 0){
                count += 1;
            }
        }
        if (count == 2){
            printf(i);
        }
    }
    return 0;    
}