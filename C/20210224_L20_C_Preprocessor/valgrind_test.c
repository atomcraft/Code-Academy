#include <stdio.h>
#include <stdlib.h>

void f(void){
    int* x = malloc(10 * sizeof(int));
     x[10] = 0;        /* problem 1: heap block overrun */
}                    /* problem 2: memory leak -- x not freed */

// void test();
// void test2();
// void test3();
// char *getString();
// void test4();


int main(void){
    f();
    // test();
    // test2();
    // test3();
    // test4();
    
    // char *p;

    /* Allocation #1 of 19 bytes */
    //p = (char *) malloc(19);
    
    /* Allocation #2 of 12 bytes */
    //p = (char *) malloc(12);
    //free(p);
    
    /* Allocation #3 of 16 bytes */
    //p = (char *) malloc(16);
    
    return 0;
}

// void test(){
//     const int NUM_HEIGHTS = 3;
//     int *heights = malloc(NUM_HEIGHTS);
//     for (int i = 0; i < NUM_HEIGHTS; i++){
//         heights[i] = i * i;
//         printf("%d: %d\n", i, heights[i]);
//     }
    
// }

// void test2(){
//     const int NUM_WEIGHTS = 5;
//     long long *weights = malloc(NUM_WEIGHTS * sizeof(weights));
//     for (int i = 0; i < NUM_WEIGHTS; i++){
//         weights[i] = 100 + i;
//         printf("%d: %lld\n", i, weights[i]);
//     }
//     free(weights);
//     weights[0] = 0;   
// }

// void test3(){
//     const int NUM_HEIGHTS = 5;
//     long long *heights = malloc(NUM_HEIGHTS * sizeof(*heights));
//     for (int i = 0; i < NUM_HEIGHTS; i++){
//         if ((heights = NULL)){ /* error here, == instead of =*/
//             heights = malloc(NUM_HEIGHTS * sizeof(*heights));
//         }        
//     }
//     free(heights):    
// }

// char *getString(){
//     char message[100] = "Hello world!";
//     char *ret = message;
//     return ret;
// }

// void test4(){
//     printf("String: %s\n", getString());
// }