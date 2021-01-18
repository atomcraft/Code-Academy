#include <stdio.h>

void runningLight(int num[], int length){
    
    for (int i = 0; i < length; i++){
        printf("%d\n", num[i]);
        int bit = (num[i] >> i) & 1;
        printf("%d \n", bit);
        if (bit == 1){
            printf("*");
            
        }
        printf("\n");
        printf(" ");
        
    }
    

}

int main(void){
    int num[] = { 1, 2, 3, 4};
    int length = sizeof(num) / sizeof(num[0]);
    // printf("%d\n", length);
    runningLight(num, length);
    return 0;
}