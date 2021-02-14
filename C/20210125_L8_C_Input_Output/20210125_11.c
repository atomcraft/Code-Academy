#include <stdio.h>
#include <string.h>

void reverse(char s[]){
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--){
        char temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
    printf("Reversed string: %s\n", s);   

}

int main (void){
    char s[] = "Hello World";
    reverse(s);
    return 0;
}