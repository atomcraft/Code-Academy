#include <stdio.h>

int vzemiBitna(int num, int indx);

int main(){
    int num = 15;
    int indx = 3;
    printf("%d", vzemiBitna(num, indx));
    return 0;

}
int vzemiBitna(int num, int indx){
    int result = (num >> indx) & 1;
    return result;

}