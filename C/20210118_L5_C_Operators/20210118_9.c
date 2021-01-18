#include <stdio.h>
#include <string.h>

void printEntryLines(char input[]){
    while(strlen(input) >= 4 && input !=EOF){
        printf("%s", input);
    }
}

int main(void){
    printf("Enter input, longer than 80 symbols: ");
    char input[] = 0;
    scanf("%s", &input);
    printEntryLines(input);    
    return 0;
}