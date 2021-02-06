#include <stdio.h>
#include <string.h>

void printStr(int *n);

int main(void){
    // int i[] = {1, 2, 3, 4, 5, 6};
    // printStr(i);
    char *pmessage = "now it is time";
    pmessage[1] = 'E';
    printf("%s", pmessage);
    return 0;
}

void printStr(int *n){
    for (int i = 0; n[i]; i++){
        printf("%d ", n[i]);
    }
}