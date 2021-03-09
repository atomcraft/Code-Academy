/*
Задача 15.
Напишете програма, която печата съдържанието на файл в обратен
ред.
Използвайте fseek функцията, за да отидете накрая на файла.
Използвайте ftell функцията, за да намерите позицията на пойнтера.
Покажете на екран файла, обърнат в обратен ред.
*/

#include<stdio.h>

int main(void){
    FILE *fp;
    char ch, fname[30], newch[500];
    int i = 0, j, COUNT = 0;
    fp = fopen("test5.txt", "r");
    if(NULL == fp){
        printf("Failed to open fail.\n");
        return 1;
    }
    printf("\nThe original content is:\n\n");
    ch = getc(fp);
    while(ch != EOF){
        COUNT++;
        putchar(ch);
        newch[i] = ch;
        i++;
        ch = getc(fp);
    }
    printf("\n\n\n");
    printf("The content in reverse order is:\n\n");
    for(j = (COUNT-1); j >= 0; j--){
        ch = newch[j];
        printf("%c", ch);
    }
    printf("\n");
    fclose(fp);
    return 0;
}