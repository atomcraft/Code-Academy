#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct treeNode_t treeNode_t;

typedef struct treeNode_t{
    int data;
    treeNode_t *left;
    treeNode_t *right;
    }treeNode_t;

extern treeNode_t *root;

int del(int n);

treeNode_t *insert(int d);

treeNode_t *search(int d);

void preorder(treeNode_t *n);

int add(int n, treeNode_t *t);

treeNode_t *search_iter(treeNode_t *t, int n);

treeNode_t *search_rec(treeNode_t *t, int n);

void printCurr(treeNode_t *curr);

void printRight(treeNode_t *t);

void insertKey(int key, treeNode_t **t);

