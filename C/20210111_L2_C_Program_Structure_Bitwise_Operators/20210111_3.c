#include <stdio.h>

int iz4istiBitna(int num, int indx);

int main(){
    int num = 63;
    int indx = 4;
    printf("%d", iz4istiBitna(num, indx));
    return 0;   

}
int iz4istiBitna(int num, int indx){
    int shift = ~(1 << indx);
    int rez = num & shift;
    return rez;
}
