#include <stdio.h>

int isLetter(char c){
    int isLetter = c >= 48 && c <= 57;
    return isLetter;  

}

int main(void){
    printf("Enter a character: ");
    char c = getchar();
    printf(isLetter(c) == 1 ? "Character is a number." : "Character is a letter.");
    return 0;

}