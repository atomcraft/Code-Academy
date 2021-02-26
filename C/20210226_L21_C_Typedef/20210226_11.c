/*Задача 11. тайпдефната структура node, съдържаща един член от
тип инт и един пойнтер към тип самата структура. Заделете динамично
памет за тази структура с malloc по описания по-горе начин.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node* node_t;
struct node{
    int i;
    node_t *nodePtr;
};

int main(void){
    struct node* nodeStr = malloc(sizeof(*nodeStr));
    printf("Size of node: %d\n", sizeof(nodeStr));
    node_t nPtr = (node_t)malloc(nPtr);
    printf("Size of node_t: %d\n", sizeof(nPtr));
    free(nodeStr);
    free(nPtr);

    return 0;


}