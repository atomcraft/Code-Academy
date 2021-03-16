#include "list.h"

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

int addPrev(int n, int k){
    t_node *q;
    t_node *p = start;
    while(p->m_nValue != k)
    p = p->m_pNext;
    q = (t_node *)malloc(sizeof(t_node));
    q->m_pNext = p->m_pNext;
    q->m_nValue = p->m_nValue;
    p->m_pNext = q;
    p->m_nValue = n;
    return 0;
}

int addEnd(int n){
    t_node *p = start;
    t_node *q = (t_node *)malloc(sizeof(t_node));
    if(!q)return -1;
    while(p->m_pNext != NULL)
    p = p->m_pNext;
    p->m_pNext = q;
    q->m_nValue = n;
    q->m_pNext = NULL;
    return 0;
}

int dellFirst(int *n){
    t_node *p = start;
    if(start){
        *n = start->m_nValue;
        start = start->m_pNext;
        free(p);
        return 0;
    } else
    return 1;
}

void dellEnd(int *n){
    t_node *q;
    t_node *p = start;
    while(p->m_pNext != NULL){
        q = p;
        p = p->m_pNext;
    }
    *n = p->m_nValue;
    q->m_pNext = NULL;
    free(p);
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

void printAfter(t_node *curr){
    t_node *p = curr;
    while(p != NULL){
        printf("%d, ", p->m_nValue);
        p = p->m_pNext;
    }
    printf("\n");
}

void printCurr(t_node *curr){
    t_node *p = curr;
    printf("\ncurr = %d\n", p->m_nValue);
}

void printListNthElemFromEnd(int elemNum){
    t_node *p = start;
    int counter = 1;
    t_node *temp = NULL;
    temp = (t_node *)malloc(sizeof(t_node));
    while(p->m_pNext != NULL){
        p = p->m_pNext;
        counter++;
        if (counter == elemNum){
            // temp = p->m_pNext;
            temp = start;
        } else if (counter > 5){
            temp = temp->m_pNext;
        }
        free(temp);
        temp = NULL;
        // printf("%d, ", p->m_nValue);
        
    }
    printf("%d, ", temp->m_nValue);
}

t_node* search_iter(int k){
    t_node *p = start;
    while(p->m_nValue != k){
        if(p->m_pNext == NULL){
            return NULL;
        } else{
            p = p->m_pNext;
        }
    }
    return p;
}