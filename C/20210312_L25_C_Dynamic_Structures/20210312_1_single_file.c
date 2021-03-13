/*
Задача 1. Реализация на списък. Напишете програма, която добавя и
изтрива елемент от списък по позиция в списъка. Използвайте следния
елемент на динамичния списък:
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
int addAfter (int n, int k);
t_node* dellElemReturnAfter(int *n, int k);
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
    addAfter(55, 4);
    printList();
    int x = 0;
    dellElemReturnAfter(&x, 4);
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

int addAfter(int n, int k){
    t_node *q;
    t_node *p = start;
    while (p->m_nValue != k){
        p = p->m_pNext;
    }
    q = (t_node*)malloc(sizeof(t_node));
    if ((!q)) return -1;
    q->m_nValue = n;
    q->m_pNext = p->m_pNext;
    p->m_pNext = q;
    return 0;   
}

t_node* dellElemReturnAfter(int *n, int k){
    t_node *p = start;
    t_node *q;
    while(p->m_nValue != k){
        if(p->m_pNext == NULL){
            return NULL;
        } else{
            q = p;
            p = p->m_pNext;
        }
    }
    *n = p->m_nValue;
    q->m_pNext = p->m_pNext;
    free(p);
    return q->m_pNext;
}

void printList(){
    t_node *p = start;
    while(p != NULL){
        printf("%d, ", p->m_nValue);
        p = p->m_pNext;
    }
    printf("\n");
}
