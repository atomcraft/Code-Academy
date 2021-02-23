#include <stdio.h>

enum bool{false, true};

int main(void){
    enum bool b = true;
    switch (b){
        case true:
        printf("true\n");
        break;
    case false:
        printf("False\n");
        break;
    }
    return 0;
}