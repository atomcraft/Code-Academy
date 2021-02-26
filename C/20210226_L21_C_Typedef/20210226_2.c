/*
Задача 2 Създайте нов потребителски тип
към тип long long int. Използвайте го във функцията
printf, отпечатайте размера.
*/
#include <stdio.h>

typedef long long int t_Long;

int main(void){
    printf("Size of t_Long: %ld\n", sizeof(t_Long));
    return 0;
}

