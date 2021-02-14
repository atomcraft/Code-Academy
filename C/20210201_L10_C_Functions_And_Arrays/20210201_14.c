
/*
Задача 14*. Напишете функция int getline(char s[],int lim), която чете ред в
s[] и връща дължината му
*/

#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
void copy(char to[], char from[]);

int main(void){
    int length;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max = 0;
    while ((length = getline(line, MAXLINE)) > 0){
        printf("%d, %s", length, line);
        if (length > max){
            max = length;
            copy(longest, line);
        }
    }
    if (max > 0){
        printf("%s", longest);
    }
    return 0;    
}

int getline(char s[], int lim){
    int i, c, j;
    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++){
        if (i < lim-2){
            s[j] = c;
            ++j;
        }       
    }
    if (c == '\n'){
        s[j] = c;
        ++j;
        ++i;
    }
    s[j] = c;
    return i;   
}

void copy(char to[], char from[]){
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0'){
        ++i;
    }
}


