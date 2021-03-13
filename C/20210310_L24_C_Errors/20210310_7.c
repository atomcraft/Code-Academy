/*
Задача 7.
Напишете програма, която обработва Ctrl+C
Ctrl+D, Ctrl+Z
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sleep(int);

void ctrlc_handlerZ(int iUnused){
    printf("\nCtrl + Z\n");
    exit(EXIT_FAILURE);
}

void ctrlc_handlerD(int iUnused){
    printf("\nCtrl + D\n");
    exit(EXIT_FAILURE);
}

void ctrlc_handlerC(int iUnused){
    printf("\nCtrl + C\n");
    exit(EXIT_FAILURE);
}

int main(void){
    signal(SIGTSTP, ctrlc_handlerZ);
    signal(SIGQUIT, ctrlc_handlerD);
    signal(SIGINT, ctrlc_handlerC);
    while (!0) sleep(1);
    return 0;
}