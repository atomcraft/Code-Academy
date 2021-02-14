#include <stdio.h>

int vdigniBitNa(int num, int indx);

int main(){
    int num = 10;
    int indx = 2;
    printf("%d", vdigniBitNa(num, indx));
    return 0;
}
int vdigniBitNa(int num, int indx){
    int shift = 1 << indx;
    int result = num | shift;
    return result;
}
