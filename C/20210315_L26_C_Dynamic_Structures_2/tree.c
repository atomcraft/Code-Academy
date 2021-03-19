#include "tree.h"

int del(int n){
    treeNode_t *current = search(n);
    treeNode_t *parent = current;
    if(current->right == NULL && current->left != NULL){
        printf("del =%d\n", current->left->data);
        current = current->left;
        sleep(100000);
        free(current);
        parent->left = NULL;
    }else if(current->right != NULL  && current->left == NULL){
        printf("del =%d\n", current->right->data);
        current = current->right;
        free(current);
        parent->right = NULL;
    }
}
treeNode_t *insert(int d){
    treeNode_t *tmp = (treeNode_t *)malloc(sizeof(treeNode_t));
    treeNode_t *current= NULL;
    treeNode_t *parent = NULL;
    tmp->data = d;
    tmp->right = tmp->left = NULL;
    if(NULL == root){
        root = tmp;
    }else{
        current = root;
        while(1){
            parent = current;
            if(d < parent->data){
                current = current->left;
                if(current == NULL){
                    parent->left = tmp;
                    return tmp;
                }
            }else{
                current = current->right;
                if(current == NULL){
                    parent->right = tmp;
                    return tmp;
                }
            }
        }
    }
}
treeNode_t *search(int d){
    treeNode_t *current = root;
    printf("Visiting elements: ");
    while (current->data != d){
        if(current != NULL)
            printf("%d ", current->data);
        if(current->data > d)
            current = current->left;
        else
            current = current->right;
        if(current == NULL)
            return NULL;
    }
    return current;
}
void preorder(treeNode_t *n){
    if(n){
        printf("%d\t", n->data);
        preorder(n->left);
        preorder(n->right);
    }
}
int add(int n, treeNode_t *t){
    if(NULL == t){
        t = (treeNode_t*)malloc(sizeof(treeNode_t));
        t->data = n;
        t->left = t->right = NULL;
    }else if(t->data > n){
            add(n,t->right);
        }else if(t->data < n){
            add(n, t->left);
        }else
            fprintf(stderr, "The element is already in the tree\n");
}

treeNode_t *search_iter(treeNode_t *t, int n){
    while ((t != NULL)&&(t->data != n)){
        if(t->data < n)
            t = t->right;
        else
            t = t->left;
    }
    return t;
}

treeNode_t *search_rec(treeNode_t *t, int n){
    if(t != NULL)
        if(t->data < n)
            t = search_rec(t->right, n);
        else if(t->data > n)
            t = search_rec(t->left, n);
    return t;
}
void printCurr(treeNode_t *curr){
    treeNode_t *p = curr;
    printf("curr - %d", p->data);
}
void printRight(treeNode_t *t){
    treeNode_t *p = t;
    while(p != NULL){
        printf("%d\t", p->data);
        p = p->right;
    }
}

void insertKey(int key, treeNode_t **t){
    if( *t ==NULL ){
        *t = (treeNode_t *) malloc( sizeof(treeNode_t));
        if ( *t != NULL ){
            (*t)->data = key;
            /* initialize the children to null */
            (*t)->left = NULL;
            (*t)->right = NULL; 
        } else{
            printf("Error allocating memory.\n");
            exit(-1);
        }              
    } else if(key < (*t)->data){
        insertKey( key, &(*t)->left );
    } else if(key > (*t)->data){
        insertKey( key, &(*t)->right );
    }
}