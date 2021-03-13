/*
Задача 1. Реализация на списък. Напишете програма, която добавя и
изтрива елемент от списък по позиция в списъка. Използвайте следния
елемент на динамичния списък:
*/
#include "list.h"

/* Compile together with list_func.c for the functions */

t_node *start;


int main(void){
    int i;
    init();
    add(1);
    add(2);
    for (i = 3; i < 15; ++i){
        add(i);
    }
    printList();
    addAfter(55, 4);
    printList();
    int x = 0;
    dellElemReturnAfter(&x, 4);
    printList();
    return 0;    
}

