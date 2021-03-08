/*
Задача 3.
Създайте test1.txt файл в избрана от вас директория. Сложете някакви
данни в него на латиница - име, поздрав, брой. Отворете за четене.
Използвайте fgetc() , която взема само един char от файла. Направете
while цикъл, за да изпишете всички символи, проверявайте за край на
файл с EOF. Проверявайте дали файловият пойнтер не е NULL, ако е
NULL, изпишете грешка.
*/
#include <stdio.h>

int main(void){
    FILE *fp;
    int c;
    fp = fopen("test1.txt","rt");
    if(fp == NULL){
        perror ("Error in opening file");
        return (-1);
    }
    while ((c = fgetc(fp)) != EOF){
        printf("%c", c);
    }
    fclose(fp);
    fp = NULL;
    return 0;
}