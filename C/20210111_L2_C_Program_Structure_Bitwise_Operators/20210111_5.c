#include <stdio.h>

int obarniBitNa(int num, int indx);

int main(){
    int num = 14;
    int indx = 2;
    printf("%d", obarniBitNa(num, indx));
    return 0;
}
int obarniBitNa(int num, int indx){
    int result = num ^ (1 << indx);   
    return result;
}