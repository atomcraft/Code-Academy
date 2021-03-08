/*
Задача 8.
Напишете стринг в текстов файл.
int fputs (const char *str, FILE *pfile);
Първият параметър е указател към стринга, който искаме да
запишем, вторият параметър е указател към файла, в който ще
пишем.
Функцията ще записва символи от стринга догато достигне
терминиращ символ \0, но не го пише в новия файл.
*/

#include <stdio.h>

int main(void){
    FILE *fp=NULL;
    fp = fopen("test.txt", "wt+");
    if(fp == NULL){
        printf("Failed to open file.\n");
    } else{
        fputs("This is my first string.\n",fp);
        fputs("I am happy to do this.\n",fp);
    }
    fclose(fp);
    return 0;
}