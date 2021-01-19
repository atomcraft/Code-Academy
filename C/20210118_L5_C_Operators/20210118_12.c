#include <stdio.h>

int main(){
    int nX;
    printf("Enter a number: ");
    scanf("%d", &nX);
    int nY = 20;
    if (nX == nY){
        printf("%d and %d are equal\n", nX, nY);        
    } else{
        printf("%d and %d are not equal\n", nX, nY);
            if (nX > nY){
                printf("%d is greater than %d\n", nX, nY);
            } else{
                printf("%d is less than %d\n", nX, nY);
            }
    }
    return 0;  
}