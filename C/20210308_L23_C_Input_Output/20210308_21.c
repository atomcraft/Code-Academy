/*
Задача 21:

Напишете стандартната програма за Linux wc, която приема име на
файл като аргумент от командния ред и изкарва на стандартния изход
стринга "Брой думи: ", последван от броя думи във файла. Програмата да
приема три вида аргументи:
 -c - който да изкарва "Брой символи: "
 -l - който да изкарва "Брой редове: "
 -w - който е за брой думи(тоест стандартното поведение на
програмата)
Ако един два или три от тези аргументи са подадени да не се взема
предвид стандартното поведение.
 Примери:
 > wc f1 // изкарва броя думи
 > wc -с f1 // изкарва броя символи
 > wc -l f1 // изкарва само броя редове
 > wc -c -w f1 // изкарва броя символи и броя думи във f1
 */
#include <stdio.h>
#define MaxLine 200  

char Line[MaxLine];  /* one line from the file */
int NChars = 0,  /* number of characters seen so far */
    NWords = 0,  /* number of words seen so far */
    NLines = 0,  /* number of lines seen so far */
    LineLength;  /* length of the current line */ 

void PrintLine(){
    int i;
    for (i = 0; i < LineLength; i++){
        printf("%c",Line[i]);
    }
    printf("\n");
}

int WordCount(){
    int i, NBlanks = 0;
    for (i = 0; i < LineLength; i++){
        if (Line[i] == ' ') NBlanks++;
        if (LineLength > 1) return NBlanks+1;
        else return 0;
    }  
 }

int ReadLine(){
    char c;  int i;
    if (scanf("%c",&c) == -1) return 0;
    Line[0] = c;
    if (c == '\n') return 1;
    for (i = 1; ; i++){
        scanf("%c",&c);
        Line[i] = c;
        if (c == '\n') return i+1;
    }
}

void UpdateCounts(){
    NChars += LineLength;
    NWords += WordCount();
    NLines++;
}
 
int main(int argc, char* argv[]){
    while (1){
        LineLength = ReadLine();
        if (LineLength == 0) break;
        UpdateCounts();
    }
    if (argc < 2){
        printf("The number of words is: %d\n", NWords);
    } else if (*(argv + 1) == "-c"){
        printf("The number of symbols is: %d\n", NChars);
    } else if (*(argv + 1) == "-l"){
        printf("The number of lines is: %d\n", NLines);
    } else if (*(argv + 1) == "-c" && *(argv + 2) == "-w"){
        printf("The number of symbols is: %d, and words is: %d\n", NChars, NWords);
    } 
    
    /*printf("%d %d %d\n",NChars,NWords,NLines);*/
    return 0;
}