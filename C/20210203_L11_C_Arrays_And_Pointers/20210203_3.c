/*
Задача 3.Напишете функцията int linSearch(int a[], int l, int d),
която получава като първи аргумент началото на масив а, втория
аргумент е дължината на масива, а третия аргумент е числото,
което търсим. Претърсете масива елемент по елемент и ако
някой елемент съвпада с търсеното число върнете позицията на
която се намира този елемент. В противен случай върнете – 1.
*/

#include <stdio.h>

int linSearch(int a[], int l, int d){
    for (int i = 0; i < l; i++){
        if (a[i] == d){
            return i;
        } else{
            return -1;
        }        
    }   
}

int main(void){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int l = sizeof(a)/sizeof(a[0]);
    int d = 5;
    int pos = linSearch(a, l, d);
    if (pos < 0){
        printf("Not found!");
    } else{
        printf("Found on position %d\n", pos);
    }    
    return 0;
}