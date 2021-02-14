#include <stdio.h>

int main(void){
    char c = 0; 
    int nl = 0;
    while ((c == getchar()) != EOF){
        if (c == '\n'){
            nl++;
        }
    }
    printf("The number of new lines entered is %d.", nl);
    return 0;   

}