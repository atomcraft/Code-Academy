#include <stdio.h>

int main(){
    int count = 0;
    int num = 985;
    while (num !=0)
    {
        num = (num & (num << 1));
        count++;
    }
    printf("%d", count);   
    return 0;    
}