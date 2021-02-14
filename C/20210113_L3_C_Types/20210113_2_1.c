#include <stdio.h>

void bin(unsigned n) 
{ 
	unsigned i; 
	for (i = 1 << 7; i > 0; i = i >> 1 ) 
		(n & i)? printf("1"): printf("0"); 
	printf("\n");
}


int main(){
    char x = 255;
    char y = 10;
    bin(x);
    bin(y);
    

    char r = x+y;
    printf("%d", r);
    return 0;    
}