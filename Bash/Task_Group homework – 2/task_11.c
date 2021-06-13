#include <stdio.h>
#include <stdlib.h>

void readComment(int c, FILE *fp);
void insideComment(FILE *fp);
void printQuoted(int c, FILE *fp);

int main(int argc, char* argv[]){
    int c, d;
    char buffer[100];
    FILE *fp;

    if (argc == 2) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
        while ((c = fgetc(fp)) != EOF) {
            readComment(c, fp);
        } 
        fclose(fp);
    }
    return 0;    
}
/*Look for a commented text or quotation*/
void readComment(int c, FILE *fp){
    int d;
    if (c == '/'){
        if ((d = fgetc(fp)) == '*'){
            insideComment(fp);
        } else if (d == '/'){
            putchar(c);
            readComment(d, fp);
        } else{
            putchar(c);
            putchar(d);
        }        
    } else if (c == '\'' || c == '"'){
        printQuoted(c, fp);
    } else{
        putchar(c);
    }    
}
/*Found commented text, look for the closing parameter*/
void insideComment(FILE *fp){
    int c, d;
    c = fgetc(fp);
    d = fgetc(fp);
    while (c != '*' || d != '/'){
        c = d;
        d = fgetc(fp);
    }
}
/*Print the quoted text*/
void printQuoted(int c, FILE *fp){
    int d;
    putchar(c);
    while ((d = fgetc(fp)) != c){
        putchar(d);
        if (d == '\\'){
            putchar(fgetc(fp));
        }
    }
    putchar(d); 
}   
