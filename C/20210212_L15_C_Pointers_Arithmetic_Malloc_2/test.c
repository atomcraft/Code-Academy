#include <stdio.h>
#include <stdlib.h>

int main(void){
    char *s;
    char c;
    char *p = s;
    s = (char *)malloc(16 * sizeof(char));
    printf("Enter a string: ");
    scanf("%s", s);
    // while ((c = getchar()) != '\n'){
    //     *s = c;
    //     s++;
    //  }
    //  *s = '\0';
    printf("\n");
    printf("You have entered: %s\n", s);
    // while (*s != '\0'){
    //     printf("\nYou have entered: %c", *s);
    //     s++;
    // }
    // printf("\n");   
    
    return 0;
}