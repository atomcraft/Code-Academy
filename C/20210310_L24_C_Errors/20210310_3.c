/*
Задача 3.
Напишете програма за отпечатване на файловете добавени след а.ехе ,
като започнете всеки нов на нова страница със заглавие и номере на всяка
страница за всеки файл
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXBOT 3
#define MAXHDR 5
#define MAXLINE 100
#define MAXPAGE 66

void filePrint(FILE *fp, char *fname);
int heading(char *fname, int pageNum);

int main(int argc, char *argv[]){
    FILE *fp;
    if (argc == 1){
        filePrint(stdin, " ");
    } else{
        while (--argc > 0){
            fp = fopen(*++argv, "r");
            if ((fp == NULL)){
                fprintf(stderr, "print: can't open %s\n", *argv);
                exit(1);
            } else{
                filePrint(fp, *argv);
                fclose(fp);
            }            
        }
    }
    return 0;  
}

void filePrint(FILE *fp, char *fname){
    int lineNum, pageNum = 1;
    char line[MAXLINE];
    lineNum = heading(fname, pageNum++);
    while (fgets(line, MAXLINE, fp) != NULL){
        if (lineNum == 1){
            fprintf(stdout, "\f");
            lineNum = heading(fname, pageNum++);
        }
        fputs(line, stdout);
        if (++lineNum > MAXPAGE - MAXBOT){
            lineNum = 1;
        }
        fprintf(stdout, "\f");
    }
}

int heading(char *fname, int pageNum){
    int ln = 3;
    fprintf(stdout, "\n\n");
    fprintf(stdout, "%s page %d\n", fname, pageNum);
    while (ln++ < MAXHDR){
        fprintf(stdout, "\n");
        return ln;
    }
}