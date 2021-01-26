#include <stdio.h>
#define MAXIMUM 256
#define MAXLINE 80


int lineCount(char s[], int limit){
    int c, i;
    for (i = 0; i < limit -1 && ((c = getchar()) != EOF && c != '\n'); ++i){
        s[i] = c;
        if (c == '\n'){
            s[i] = c;
            ++i;
        }
    }
    s[i] = '\0';
    return i;     
}

int main(void){
    char s[MAXIMUM];
    int length = 0;
    while ((length = lineCount(s, MAXIMUM)) > 0){
        if (length > MAXLINE){
            printf("%s\n", s);
        }        
    }
    return 0;
}