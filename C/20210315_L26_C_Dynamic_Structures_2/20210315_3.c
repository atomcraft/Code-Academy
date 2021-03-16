/*
Задача 3. Да се построи наредено двоично дърво за
търсене чрез последователно добавяне на следните
върхове:
а) 7, 14, 28, 35, 65, 12, 18, 42, 81, 64, 61, 4, 13
б) 12, 7, 14, 81, 42, 18, 61, 4, 64, 35, 13, 28, 65
в) 4, 7, 12, 13, 14, 18, 28, 35, 42, 61, 64, 65, 81
г) 81, 65, 64, 61, 42, 35, 28, 18, 14, 13, 12, 7, 4
д) 28, 64, 13, 42, 7, 81, 61, 4, 12, 65, 35, 18, 14
Да се сравнят получените дървета. Какви изводи могат
да се направят?
*/


#include "tree.h"
#define SIZE 13

treeNode_t *root = NULL;

void print2D(treeNode_t *root);
void print2DUtil(treeNode_t *root, int space) ;


int main(void){
    int i;
    int arrTree1[SIZE] = {7, 14, 28, 35, 65, 12, 18, 42, 81, 64, 61, 4, 13};
    for(i = 0; i < SIZE; i++)
        insert(arrTree1[i]);
    print2D(root);

    root = NULL;
    int arrTree2[SIZE] = {12, 7, 14, 81, 42, 18, 61, 4, 64, 35, 13, 28, 65};
    for(i = 0; i < SIZE; i++)
        insert(arrTree2[i]);
    print2D(root);
    root = NULL;

    int arrTree3[SIZE] = {4, 7, 12, 13, 14, 18, 28, 35, 42, 61, 64, 65, 81};
    for(i = 0; i < SIZE; i++)
        insert(arrTree3[i]);
    print2D(root);
    root = NULL;

    int arrTree4[SIZE] = {81, 65, 64, 61, 42, 35, 28, 18, 14, 13, 12, 7, 4};
    for(i = 0; i < SIZE; i++)
        insert(arrTree4[i]);
    print2D(root);
    root = NULL;

    int arrTree5[SIZE] = {28, 64, 13, 42, 7, 81, 61, 4, 12, 65, 35, 18, 14};
    for(i = 0; i < SIZE; i++)
        insert(arrTree5[i]);
    print2D(root);
    root = NULL;

    return 0;
}

void print2DUtil(treeNode_t *root, int space){ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += SIZE; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = SIZE; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 

// Wrapper over print2DUtil() 
void print2D(treeNode_t *root){ 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
} 