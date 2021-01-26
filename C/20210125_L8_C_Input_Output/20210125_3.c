#include <stdio.h>

int main(void){
    int c, counter = 0;
    while (c != EOF){
        if (c == '\n' || c == ' ' || c == '\t'){
            counter++;
        }
        c = getchar();
    }
    printf("The number of new lines, spaces and tabs entered is %d.", counter);
    return 0;   

}