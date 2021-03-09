/*
Задача 6.
Отворете и прочетете съдържанието от файл с fscanf.
int fscanf(FILE *stream, const char *format,....)
Има същите формати, както scanf.
Първият аргумент е пойнтер към файла, от който ще четем.
Вторият аргумент е формата- Стрингът може да има следните параметриспейс, неспейс, спецификатори;
*/
#include <stdio.h>

int main(void){
    FILE *fp;
    char str[60];
    fp = fopen("test.txt", "rt");
    if (NULL == fp){
        perror("Failed to open file");
        return(-1);
    }
    if (fgets(str, 60, fp) != NULL){
        printf("%s", str);
    }
    fclose(fp);
    return 0;  
    
}