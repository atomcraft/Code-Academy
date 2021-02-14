#include <stdio.h>

int main(void){
    int nA = 1;
    int nB = ( nA == 1 ? 2 : 0 );
    printf("A value is %d\n", nA);
    printf("B value is %d\n", nB);
    printf("Enter a new value of A: ");
    scanf("%d", &nA);
    printf("\nA value is %d\n", nA);
    printf("\nB value is %d\n", nB);
    nA > nB ? printf("A is bigger than B.") : printf("B is bigger than A.");
    
    return 0;
}