#include <stdio.h>
#include <stdlib.h>

int nullPos(unsigned int);

int main(int argc, char const *argv[]){
    unsigned int rez = nullPos(atoi(argv[1]));
    printf("%d\n", rez);
    int expected_rez = atoi(argv[2]);
    if (rez != expected_rez){
        printf("err\n");
        return 1;
    }
    return 0;
}
 
int nullPos(unsigned int x){
    unsigned int mask = 248;
    mask = ~mask;
    unsigned int y = x & mask;
    return y;
}
