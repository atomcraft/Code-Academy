/*
Задача 11.
Направете същото ползвайки fgetpos().
int fgetpos(FILE *pfile, fpos_t *position);
Първият параметър е указател към файла, вторият параметър е
указател към стандартен параметър дефиниран в stdio.h
Типа fpos_t може да запише всяка позиция във файла.
Функцията връща 0 при успех и различно от 0 при грешка.
Дефинирайте променлива за fpos_t.
*/

#include <stdio.h>

int main(void){
    FILE *fp;
    fpos_t position;
    fp = fopen("test2.txt", "w+");
    if(fp == NULL){
      perror("Error opening file");
      return(-1);
    }
    fputs("Change!", fp);;
    fgetpos(fp, &position);
    printf("Position: %ld\n", position);
    fclose(fp);
    return 0;
}