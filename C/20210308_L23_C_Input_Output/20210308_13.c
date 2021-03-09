/*
Задача 13.
Напишете програма, която да намери общия брой на
редовете в текстови файл.
Създайте файл, който съдържа няколко реда текст.
Внимавайте къде позиционирате файла.
Отворете файла. Използвайте променлива, която да
брои броя на редовете.
*/
#include <stdio.h>

#define FSIZE 100
 
int main()
{
    FILE *fp;
    int counter = 0;  
    char c; 
    fp = fopen("test3.txt", "r");
    if (NULL == fp){
        printf("Could not open file.\n");
        return -1;
    }
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n'){
            counter += 1;
        }            
    fclose(fp);
    printf(" The lines in the file are : %d \n", counter - 1);
    return 0;
}