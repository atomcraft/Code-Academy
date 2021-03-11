/*
Задача 7.
Напишете програма, която обработва Ctrl+C
Ctrl+D, Ctrl+Z
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sleep(int);

void ctrlc_handler(int iUnused){
    printf("\nCtrl + C\n");
    exit(EXIT_FAILURE);
}

int main(void){
    signal(SIGINT, ctrlc_handler);
    while (!0) sleep(1);
    return 0;
}