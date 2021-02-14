#include <stdio.h>

int checkNumSign(int num){
    if (num >= 0){
        return 1;
    }else{
        return 0;
    }  
}

int main(void){
    int num = 0;
    printf("Enter a positive of negative number: ");
    scanf("%d", &num);
    printf(checkNumSign(num) ? "Positive number" : "Negative number");
    return 0;
}