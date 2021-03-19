#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//gcc -g -Wall -pthread thr.c -lpthread -o thr
void *thr0() {
int i = 0;
while (i<10000){
printf("0");
i++;
}
return NULL;
}

void *thr1() {
int i;
while (i < 10000){
printf("1");
i++;
}
return NULL;
}

int main(void) {
pthread_t threads[2];

size_t stack_size;
int s;
pthread_attr_t attr;
s = pthread_attr_init(&attr);
if (s != 0)
printf("pthread_attr_init");

pthread_attr_getstacksize(&attr, &stack_size);
printf("Old stack size-> %ld\n", stack_size); 

s = pthread_attr_setstacksize(&attr, 320000034);
if (s != 0)
printf("pthread_attr_setstacksize");
pthread_attr_getstacksize(&attr, &stack_size);
printf("New stack size-> %ld\n", stack_size); 

pthread_create(&threads[0], &attr, thr0, NULL);
pthread_attr_destroy(&attr);

pthread_create(&threads[1], NULL, thr1, NULL);
pthread_join(threads[0], NULL);
pthread_join(threads[1], NULL);

return 0;
}