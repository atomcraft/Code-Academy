/*
Задача 3.
Направете едносвързан списък, съдържащ числата 1-14 и
принтирайте петия елемент от края му.
*/

#include "list.h"

t_node *start;

/* Compile together with list_func.c for the functions */

int main(void){
    int i;
    init();
    add(1);
    add(2);
    for (i = 3; i < 15; ++i){
        add(i);
    }
    printList();
    int elemNum = 5;
    printListNthElemFromEnd(elemNum);
    return 0;    
}
