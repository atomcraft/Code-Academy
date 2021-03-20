#include <stdio.h>

void LEtoBE(unsigned int *t){
    *t = (*t >> 24) | (*t << 24) | 
    ((*t << 8) & 0x00ff0000u) |
    ((*t >> 8) & 0x0000ff00u);
    return;
}

int main(void){
    unsigned int cell = 0x12345678u;
    printf("%x\n", cell);
    LEtoBE(&cell);
    printf("%x\n", cell);
    return 0;
}