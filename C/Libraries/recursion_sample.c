#include <stdio.h>
#include <stdlib.h>

void recursive(int num){
    if (num == 5){
        printf("Number = %d\nEnd ofrecursion\n", num);
        exit(0);
    }
    printf("Number = %d\n", num);
    num++;
    recursive(num);    
}

int main(void) {
    recursive(1);
    return 0;
}