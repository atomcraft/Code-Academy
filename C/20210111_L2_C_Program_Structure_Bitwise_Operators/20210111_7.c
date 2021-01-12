#include <stdio.h>

int nullifyAllEvenBits(int num, int indx);

int main(){
    int num = 5461;
        
    /*
    Solution with a for cycle and if:
    for(int i = 0; i <= 32, i+=2){
        if(i % 2 == 0){
            num &= ~(1 << i);
        }
    }
    printf("%d", num);
    */
    int indx = 0;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    indx +=2;
    num = nullifyAllEvenBits(num, indx);
    printf("%d", num);
    
    return 0;

}
int nullifyAllEvenBits(int num, int indx){
    return num &= ~(1 << indx);
}