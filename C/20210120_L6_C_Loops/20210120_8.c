#include <stdio.h>

int main(void){
    unsigned int nTick = 0;
    for (;;){
        sleep(1);
        printf("tick %d\n", ++nTick);
        nTick %= 60;
        if (nTick == 48){
            break;
        }        
    }
    return 0;    
}