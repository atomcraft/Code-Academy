#include <stdio.h>

int main(void){
    int c = 0;
    int flag = 1;
    while ((c = getchar()) != EOF){
        if (c == ' ' || c =='\t'){
            if ((flag == 1 && c == ' ') || (flag == 1 && c == '\t')){
                continue;
            }
            flag = 1;            
        }        
        else{
            flag = 0;
        }

        /*if (c == '('){
            putchar(c);
        } else{
            putchar( c);
        }
        */
       putchar(c);       

    }
    return 0;
}
