#include <stdio.h>
#include <stdlib.h>

typedef struct node_t node_t;

typedef struct node_t {
    int data;
    node_t *next;
} node_t;


extern node_t *start;

int push(int n);
int pop(int *n);