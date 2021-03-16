/*
Задача 5. Да се напише рекурсивен вариант на
функцията за обхождане на двоично дърво.
*/

#include "tree.h"
#define SIZE 13

treeNode_t *root = NULL;

int main(void){
    int i;
    int arrTree1[SIZE] = {1, 3, 5, 6, 10, 8, 7, 13, 11, 12, 14};
    for(i = 0; i < SIZE; i++)
        insert(arrTree1[i]);
    preorder(root);
    free(root);
    root = NULL;

    return 0;
}

/*
void preorder(treeNode_t *n){
    if(n){
        printf("%d\t", n->data);
        preorder(n->left);
        preorder(n->right);
    }
}
*/
