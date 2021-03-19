#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct context_t{
    int resource;
    pthread_mutex_t producer, consumer;
} context_t;

void *producer(void *_ctx){
    context_t *ctx = (context_t *)_ctx;
    while (1){
        pthread_mutex_lock(&ctx->producer);
        ctx->resource++;
        printf("prod %d\n", ctx->resource);
        pthread_mutex_unlock(&ctx->consumer);
    }
    return NULL;
}

void *consumer(void *_ctx){
    context_t *ctx = (context_t *)_ctx;
    while (1){
        pthread_mutex_lock(&ctx->consumer);
        printf("cons %d\n", ctx->resource);
        pthread_mutex_unlock(&ctx->producer);
    }
    return NULL;
}

int main(void){
    pthread_t prod, cons;
    context_t ctx = {
        0,
        PTHREAD_MUTEX_INITIALIZER,
        PTHREAD_MUTEX_INITIALIZER
    };
    pthread_mutex_lock(&ctx.consumer);
    pthread_create(&prod, NULL, producer, &ctx);
    pthread_create(&cons, NULL, consumer, &ctx);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    return 0;
}