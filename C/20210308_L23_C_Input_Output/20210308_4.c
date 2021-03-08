/*
Задача 4.
Прочетете стринг от създадения файл.
char *fgets(char * str, int nchars, FILE *stream)
 първият параметър е стринг, вторият параметър е брой символи, който
искаме да прочетем, освен ако не стигне терминиращия символ за край
на реда \n или \0 първо, третият е пойнтер към файла;
*/

#include <stdio.h>

int main(void){
    FILE *fp;
    char str[60];
    fp = fopen("test1.txt", "rt");
    if(fp == NULL){
        perror ("Error opening file");
        return(-1);
    }
    if(fgets(str,60,fp) != NULL){
        printf("%s\n",str);
    }
    fclose(fp);
    fp = NULL;
    return 0;
}