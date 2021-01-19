#include <stdio.h>

int main(void){
    int nA;
    printf("Enter a number for nA: ");
    scanf("%d", &nA);
    int nB = ( nA == 1 ? 2 : 0 );
    printf("A value is %d\n", nA);
    printf("B value is %d\n", nB);
    if (nA == nB){
         printf("A is equal to B.\n");
    } else{
        nA > nB ? printf("A is bigger than B.\n") : printf("B is bigger than A.\n");
    }   
    return 0;
}