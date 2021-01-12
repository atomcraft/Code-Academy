#include <stdio.h>

int main(){
    int num = 15;
    int posOfOnes = 0;
    for (int i = 0; i < sizeof(int); i++)
    {
        if ((num & 1) ==1){
            printf("2 ^ %d\n", i);
        }
        num >>=1;        
    }
    return 0;

}