/*
Задача 12.
Изместете позицията си във файла 7 байта след началото, ползвайки fseek.
int fseek(FILE *pfile, long offset, int original);
Първият параметър е указател към файла, вторият и третият параметър
оказват къде точно искаме да отидем във файла.
Референтни точки с предварително дефинирани имена:
SEEK_SET- началото на файла
SEEK_CUR- текуща позиция
fseek(fp, -10L, SEEK_CUR); връща на зад от текупата 10 bytes.
SEEK_END- края на файла
fseek(fp,0L, SEEK_END);
При текстови файлове, вторият аргумент трябва да е стойността върната от
ftell()
За текстови файлови третият аргумент трябва да е SEEK_SET, за бинарни
файлове и просто число в байтове.
*/

#include <stdio.h>

int main (void){
    FILE *fp;
    fp = fopen("file1.txt","w+");
    if(NULL == fp){
      perror("Error opening file");
      return -1;
    }
    fputs("This is a test", fp);
    fseek( fp, 7, SEEK_SET );
    fputs(" Fseek Testing", fp);
    fclose(fp);
    fp = fopen("file1.txt","r");
    if(NULL == fp){
      perror("Error opening file");
      return -1;
    }
    int c;
    while(1){
        c = fgetc(fp);
        if(feof(fp)){
            break;
        }
        printf("%c", c);
    }
    fclose(fp);
    return 0;
}