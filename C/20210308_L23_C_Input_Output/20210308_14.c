/*
Задача 14.
Напишете програма, която да обръща всички символи в
текстов файл, с главни букви запишете резултата в друг
временен файл. След това преименувайте новия файл
с името на оригиналния файл и изтрийте временното
име. Отпечатайте съдържанието на файл на
стандартния изход с главни букви.
*/

#include <stdio.h>
#include <ctype.h>

void fileCopy(FILE *ifp, FILE *ofp);

int main(void){
    FILE *ifp = NULL;
    FILE *ofp = NULL;
    char *filename = "test4.txt";
    char *tempFileName = "test_copy.txt";
    ifp = fopen (filename, "wt");
    if(NULL == ifp){
        printf("Failed to open %s.\n",filename);
        return -1;
    }
    ofp = fopen (tempFileName, "wt");
    if(NULL == ofp){
        printf("Failed to open %s.\n",tempFileName);
        return -1;
    }
    fileCopy(ifp, ofp);

    // int rename (const char *oldname, const char *newname);
    // if (remove ("test4.txt")){
    //     printf("Failed to remove.\n");
    // } else{
    //     printf("Remove successful.\n");
    // }
    // if(rename ("test_copy.txt", "test4.txt")){
    //     printf("Failed to rename file.\n");
    // } else {
    //     printf("File renamed successfully.\n");
    // }
    // if (remove ("test_copy.txt")){
    //     printf("Failed to remove.\n");
    // } else{
    //     printf("Remove successful.\n");
    // }
    fseek(ifp, 0, SEEK_SET);
    int c;
    while((c = fgetc(ifp) != EOF)){
        printf("%c", c);
    }  
    fclose(ifp);
    fclose(ofp);
    return 0;
}

void fileCopy(FILE *ifp, FILE *ofp){
    int c;
    while ((c = getc(ifp)) != EOF){
        putc(toupper(c), ofp);
    }    
}