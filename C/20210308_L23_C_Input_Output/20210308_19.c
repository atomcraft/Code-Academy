/*
Задача 19:
 Напишете стандартната програма за Linux cat , която приема като
аргументи от командния ред имена на файлове и изкарва съдържанието
им на стандартния изход. Ако на програмата не са подадени никакви
аргументи, то тя да изкара съдържанието подадено от стандартния вход
на стандартния изход.
*/
#include <stdio.h>

void fileCopy(FILE *, FILE *);

int main(int argc, char *argv[]){
    FILE *fp = NULL;
    if (argc == 1){
        fileCopy(stdin, stdout);
    } else{
        while (--argc > 0){
            if ((fp = fopen(*++argv, "r")) == NULL){
                printf("cat: failed to open %s\n", *argv);
                return 1;
            } else{
                fileCopy(fp, stdout);
                fclose(fp);
            }            
        }        
    }
    return 0;    
}

void fileCopy(FILE *ifp, FILE *ofp){
    int c;
    while ((c = getc(ifp)) != EOF){
        putc(c, ofp);
    }    
}