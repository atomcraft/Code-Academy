#include <stdio.h>

void print_bytes(const char* pcVal, unsigned uSize){
    unsigned i;
    for (i = 0; i < uSize; i++){
        printf("%#02x ", (int)(pcVal[i] & 0xFF));
    }
    printf("\n");
    
}

int main(void){
    short sValue = 0xAABB;
    int nValue = 0xAABBCCDD;
    long long llValue = 0x1122334455667788;
    print_bytes((const char*) &sValue, sizeof(sValue));
    print_bytes((const char*) &nValue, sizeof(nValue));
    print_bytes((const char*) &llValue, sizeof(llValue));
    return 0; 
}