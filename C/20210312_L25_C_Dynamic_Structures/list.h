#include <stdio.h>
#include <stdlib.h>

typedef struct t_node t_node;

typedef struct t_node {
    int m_nValue;
    t_node* m_pNext;
} t_node;


extern t_node *start;

void init();
int add(int);
int addAfter (int n, int k);
int addPrev(int n, int k);
int addEnd(int n);
int dellFirst(int *n);
void dellEnd(int *n);
t_node* dellElemReturnAfter(int *n, int k);
void printList();
void printAfter(t_node *curr);
void printCurr(t_node *curr);
void printListNthElemFromEnd(int elemNum);
t_node* search_iter(int k);
