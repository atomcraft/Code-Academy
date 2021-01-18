#include <stdio.h>

int main(void){
    int nA;
    printf("Enter a number for nA: ");
    scanf("%d", &nA);
    int nB = ( nA == 1 ? 2 : 0 );
    printf("A value is %d\n", nA);
    printf("B value is %d\n", nB);
    nA > nB ? printf("A is bigger than B.") : printf("B is bigger than A.");
    
    return 0;
}