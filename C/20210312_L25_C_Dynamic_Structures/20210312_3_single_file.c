/*
Задача 3.
Направете едносвързан списък, съдържащ числата 1-14 и
принтирайте петия елемент от края му.
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct t_node {
    int m_nValue;
    struct t_node* m_pNext;
} t_node;

t_node *start;

void init();
int add(int);
void printCurr(t_node *curr);
void printList();


int main(void){
    int i;
    init();
    add(1);
    add(2);
    for (i = 3; i < 15; ++i){
        add(i);
    }
    printList();
    return 0;    
}

void init(){
    start = NULL;
}

int add(int n){
    t_node *p = start;
    start = (t_node*)malloc(sizeof(t_node));
    if ((!start)) return -1;
    start->m_nValue = n;
    start->m_pNext = p;
    return 0;    
}

void printCurr(t_node *curr){
    t_node *p = curr;
    printf("\ncurr = %d\n", p->m_nValue);
}

void printList(){
    t_node *p = start;
    int counter = 0;
    t_node *temp = NULL;
    while(p != NULL){
        if (counter == 5){
            temp = p->m_pNext;
        }
        counter++;
        // printf("%d, ", p->m_nValue);
        p = p->m_pNext;
    }
    printf("%d, ", temp->m_nValue);
}
