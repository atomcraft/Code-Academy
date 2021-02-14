#include <stdio.h>
#include <unistd.h>

unsigned int sleep(unsigned int seconds);

void runningLight(int num[]){
    int index = 0;
    int rem = 0;
    int space = 0;

    while (num[index] > 0){
        int temp = num[index];
        rem = temp % 2;
        for (int i = 0; i <= rem; i++){
            if (rem == 1){
                for (int j = 0; j < space; j++){
                     printf(" ");
                }        
                printf("*");
                printf("\n");
                space++;
                sleep(5);
            }           
        }        
        temp /= 2;
        index++;
    }
}

int main(void){
    int num[] = { 1, 2, 3, 4};
    runningLight(num);
    return 0;
}