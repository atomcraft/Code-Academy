#include <stdio.h>

int main(){
    int num = 42;
    int position = 0;
    for (int i = 0; i <= 32; i++) {
        int bit = (num >> i) & 1;
        if (bit == 1) {
            position = i;
        }      
       
    }
    printf("%d", position);
    return 0;    
}