#include <stdio.h>

void xorShift(int a){
    a ^= a << 13;
    printf("a: %d\n", a);
    a ^= a >> 17;
    printf("a: %d\n", a);
    a ^= a << 5;
    printf("a: %d\n", a); 

}

void xorShiftLongLong(long long int b){
    b ^= b << 13;
    printf("long long a: %d\n", b);
    b ^= b >> 17;
    printf("long long a: %d\n", b);
    b ^= b << 5;
    printf("long long a: %d\n", b);

}

int main(void){
    int a = 1;
    xorShift(a);
    long long int b = 5;
    xorShiftLongLong(b);
    return 0;
}