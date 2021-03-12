/*
Задача 2.
Напишете програма, която проверява дали всички отворени къдрави скоби {, (, [ за затворени ] ),},
Хвърлете грешка при липса на затварящи скоби и реда на който са
*/
#include <stdio.h>
#include <string.h>

char st[20];
int top = -1;

void psh(char a);
char pop();

int main(void){
    char a[20],t;
    int i,f = 1;
    scanf("%s",a);
    for(i = 0;i < strlen(a); i++){
        if(a[i] == '(' || a[i] == '{' || a[i] == '['){
            psh(a[i]);
        }
        if(a[i] == ')' || a[i] == '}' || a[i] == ']'){
            if(top == -1)
            f = 0;
            else{
                t = pop();
                if(a[i] == ')' && (t == '[' || t == '{'))
                f = 0;
                if(a[i] == '}' && (t == '(' || t == '['))
                f = 0;
                if(a[i] == ']' && (t == '{' || t == '('))
                f = 0;
            }
        }
    }
    if(top >= 0)
    f = 0;
    if(f == 0)
    printf("Unbalanced\n");
    else
    printf("Balanced\n");

    return 0;
}

void psh(char a){
    st[++top] = a;
} 

char pop(){
    return st[top--];
}

