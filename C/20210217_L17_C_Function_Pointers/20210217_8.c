/*
Задача 8.
Напишете програма, която да представя Реда на Фибоначи в масив.
Ред на Фибоначи: Всяко число е равно на сумата на двете преди него.
Първите 2 са 0 и 1. 
*/

#include<stdio.h>

int main(void){
    int n,k;
    long int aray[20];

    printf("Enter the number range:\n");
    scanf("%d",&n);
    aray[0]=-1;
    aray[1]=1;
    printf("\n FIBONACCI SERIES: \n");
    for(k=2;k<=n+1;k++){
        aray[k]=aray[k-1]+aray[k-2];
        printf(" %ld",aray[k]);
    }
    printf("\n");
  return 0;
}