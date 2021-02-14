#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    char s[] = "I love you";
    if (argv[1] = "encrypt"){
        for (int i = 0, n = strlen(s); i < n; i++){
            printf("%c", s[i]);
        }
        
    }
    if (argv[1] = "decrypt"){
        int c[] = {74, 78, 80, 87, 70, 90, 80, 86};
        for (int i = 0, n = 8; i < n; i++){
            printf("%c", c[i]);
        }
        
    }
    return 0;
    
}