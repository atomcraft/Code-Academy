#include <stdio.h>

int main (void){
    int i;
    char arrEscChar[]= {'\t', '\n', '\r', '\v', '\\', '\'', '\"', '\?', '\a', '\b', '\f'};
    for (int i = 0; i < sizeof(arrEscChar) / sizeof(char); i++){
        printf("Char: %c \n", arrEscChar[i]);
    }
    return 0;    
}
