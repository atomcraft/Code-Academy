/*
Задача 2.
Създайте test.txt файл в избрана от вас директория. Сложете
някакви данни в него на латиница- име, поздрав, брой. Отворете
файла за редактиране. Внимавайте за мястото, къде поставяте
файла. Трябва да е там, където е сорс файлът.
*/

#include <stdio.h>

int main(void){
    /*FILE *fopen(const char *restrict name, const char *restrict mode);*/
    FILE *pfile = NULL;
    char *filename = "test.txt";
    pfile = fopen (filename, "wt");
    if(pfile == NULL){
        printf("Failed to open %s.\n",filename);
    }  

    int rename (const char *oldname, const char *newname);
    if(rename ("test.txt", "test_copy.txt")){
        printf("Failed to rename file.\n");
    } else {
        printf("File renamed successfully.\n");
    }
    if (remove ("test_copy.txt")){
        printf("Failed to remove.\n");
    } else{
        printf("Remove successful.\n");
    }    
    fclose (pfile);
    pfile = NULL;
    return 0;
}