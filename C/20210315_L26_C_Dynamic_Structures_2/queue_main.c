#include "queue.h"

node_t *first = NULL;
node_t *last = NULL;

int main(void){
    int n = 5;
    while (n){
        printf("Enter a digit:\n");
        scanf("%d", &n);
        write(n);
    }
    while(read(&n))
    printf("%d", n);
    return 0;
}

