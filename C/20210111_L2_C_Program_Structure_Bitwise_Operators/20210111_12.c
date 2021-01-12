#include <stdio.h>

int main (){
    int num = 10;
    for (int i = 3; i < 32; i+=3) {
        num |= (1 << i);
    }
    printf("%d", num);
    return 0;    
}