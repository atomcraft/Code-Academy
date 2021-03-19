#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thr0(void *_arg){
    while (1) printf("0");
    return NULL;
}

void *thr1(void *arg){
    while (1) printf("1");
    return NULL;
}

int main(void){
    pthread_t threads[2];
    pthread_create(&threads[0], NULL, thr0, NULL);
    pthread_create(&threads[1], NULL, thr1, NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    return 0;
}