#include <stdio.h>

int main(){
    int x = 3;
    int y = 5;
   
    int rez = x & y;
    printf("%d\n", rez);
    
    int rez = x | y;
    printf("%d\n", rez);
   
    int rez = x ^ y;
    printf("%d", rez);

    return 0;
}