#include <stdio.h>

void readComment(int c);
void insideComment(void);
void printQuoted(int c);

int main(void){
    int c, d;
    while ((c = getchar()) != EOF){
        readComment(c);
    }
    return 0;    
}
/*Look for a commented text or quotation*/
void readComment(int c){
    int d;
    if (c == '/'){
        if ((d = getchar()) == '*'){
            insideComment();
        } else if (d == '/'){
            putchar(c);
            readComment(d);
        } else{
            putchar(c);
            putchar(d);
        }        
    } else if (c == '\'' || c == '"'){
        printQuoted(c);
    } else{
        putchar(c);
    }    
}
/*Found commented text, look for the closing parameter*/
void insideComment(void){
    int c, d;
    c = getchar();
    d = getchar();
    while (c != '*' || d != '/'){
        c = d;
        d = getchar();
    }
}
/*Print the quoted text*/
void printQuoted(int c){
    int d;
    putchar(c);
    while ((d = getchar()) != c){
        putchar(d);
        if (d == '\\'){
            putchar(getchar());
        }
    }
    putchar(d);    
}
