#include <stdio.h>

int main(void){
    int nA;
    printf("Enter a number: ");
    scanf("%d", &nA);
    int nB = 20;
    int nX = 20;
    int nY = 30;
    if (nA > nB && nA != 0){
        printf("&& Operator : Both conditions are true\n");
    }
    if (nX > nY || nY != 20) {
        printf("|| Operator : Only one condition is true\n");
    }
    if (! (nA > nB && nB !=0 ) ) {
        printf(" ! Operator : Both conditions are true\n");
    } else {
        printf("Both conditions are true.\n");
    }
    return 0;
}