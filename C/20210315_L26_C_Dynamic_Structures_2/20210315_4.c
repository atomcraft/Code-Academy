/*
Задача 4. Да се изтрият в този ред върховете 1, 7, 12 и
14 от дървото на
1, 3, 5, 6, 10, 8, 7, 13, 11, 12, 14
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
    printf("\n");
    int n = 1;
    del(n);
    printf("\n");
    n = 7;
    del(n);
    printf("\n");
    n = 12;
    del(n);
    printf("\n");
    n = 14;
    del(n);
    printf("\n");
    free(root);
    root = NULL;

    return 0;
}
