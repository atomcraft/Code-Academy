#include <stdio.h>

int main(){
    int num = 15;
    for (int i = 1; i <= sizeof(int); i+=2) {
        int shift = 1 << i;
        num = num ^ shift;
    }
    printf("%d", num);
    return 0;
}