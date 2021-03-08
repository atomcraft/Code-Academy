/*
Задача 10.
Намерете позицията си във файла.
long ftell(FILE *pfile);
Функцията приема указател към файла като параметър и връща long
int, който отговаря на позицията във файла.
Дефинирате променлива
long fpos = ftell(pfile)
Променливата съхранява текущата ви позицията в байтове от
началото на файла и вие можете да се върнете на нея по всяко
време.
*/
#include <stdio.h>

int main(void){
    FILE *fp;
    int len;
    fp = fopen("test2.txt", "r");
    if(fp == NULL){
      perror("Error opening file");
      return(-1);
    }
    fgetc(fp);
    printf("Position: %ld\n", fp);
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fclose(fp);
    printf("File size: %d bytes\n", len);
    return 0;
}