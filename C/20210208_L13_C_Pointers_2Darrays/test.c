#include <stdio.h>


int main(void){
    char c = 'A';

    for (int i = 0; i < 10; i++){
        printf("%c ", c);
        c = c +1;
    }
    return 0;   
}
