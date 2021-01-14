#include <stdio.h>

void bin(unsigned n) 
{ 
	unsigned i; 
	for (i = 1 << 7; i > 0; i = i >> 1 ) 
		(n & i)? printf("1"): printf("0"); 
	printf("\n");
}


int main(){
    unsigned char z = 0;
    bin(z);
    printf("%d", z);
    signed char a = -10;
    printf("%d", a);
    bin(a);
    z = z + a;
    printf("%d\n", z);
    bin(z);
    return 0;
}