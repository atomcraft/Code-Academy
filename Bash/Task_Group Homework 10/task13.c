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
#include <unistd.h>

 
int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Error: Please provide file name.\n");
        return 1;
    }
    if (argc > 2) {
        printf("Error: Passed more than one file names.\n");
        return 2;
    }
    char *file = argv[1];
    FILE *fp;
    int counter = 0;  
    char c;

    if( access(file, F_OK) != 0 ) {
        printf("Error: File %s does not exist.\n", file);
        return 3;
    } 
    
    if ((fp = fopen(file, "r")) == NULL){
        printf("Error: Could not open file %s.\n", file);
        return 4;
    }
    
    

    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n'){
            counter += 1;
        }

    if(fclose(fp) != 0) {
        printf("Error: File %s not closed successully.\n", *file);
        return 5;
    }
    printf(" The lines in the file are : %d \n", counter);
    return 0;
}
