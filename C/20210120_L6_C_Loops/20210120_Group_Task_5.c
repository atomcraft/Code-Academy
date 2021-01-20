#include <stdio.h>
#include <string.h>
#define str_size 100

int countWords (char words[]){
    int counter = 0;
    int i = 0;
    while (words[i] != '\0'){
        if (words[i] == ' ' || words[i] == '\n' || words[i] == '\t'){
            counter++;
        }
        i++;
    }
    return counter;   
}

int main(void){
    // char words[] = "Hello World Words Count! Check";
    printf("Enter a string of words: ");
    char words[str_size];
    fgets(words, sizeof words, stdin);
    printf("The string contains %d words.\n", countWords(words));
    return 0;
}