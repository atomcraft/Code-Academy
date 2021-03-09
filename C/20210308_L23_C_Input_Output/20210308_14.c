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


int main(void){
    FILE *ifp = NULL;
    FILE *ofp = NULL;
    char *filename = "test4.txt";
    char *tempFileName = "test4_copy.txt";
    char ch = ' ';
    ifp = fopen (filename, "r");
    if(NULL == ifp){
        printf("Failed to open %s.\n",filename);
        return -1;
    }
    ofp = fopen (tempFileName, "wt");
    if(NULL == ofp){
        printf("Failed to open %s.\n",tempFileName);
        return -1;
    }
    while ((ch = fgetc(ifp) != EOF)){
        if (islower(ch)){
            ch = toupper(ch);
        }
        fputc(ch, ofp);
    }
    fclose(ifp);
    fclose(ofp);
    if(rename ("test_copy.txt", "test4.txt")){
        printf("Failed to rename file.\n");
    } else {
        printf("File renamed successfully.\n");
    }
    if (remove ("test_copy.txt")){
        printf("Failed to remove.\n");
    } else{
        printf("Remove successful.\n");
    }
    ifp = fopen (filename, "r");
    if(NULL == ifp){
        printf("Failed to open %s.\n",filename);
        return -1;
    }
    while ((ch = fgetc(ifp) != EOF)){
        printf("%c", ch);
    }
    fclose(ifp); 
    ifp = NULL;
    ofp = NULL;   
    return 0;
}
