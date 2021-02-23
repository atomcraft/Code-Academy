#include <stdio.h>

struct tagTest{
    char m_chValue;
    unsigned short m_usValue;
    double m_dValue;
}__attribute__((packed));

int main(void){
    struct tagTest test = {'A', 62525, 33.3};
    printf("Size of char in struct: %d\n", sizeof(test.m_chValue));
    printf("Size of u_short in struct: %d\n", sizeof(test.m_usValue));
    printf("Size of double in struct: %d\n", sizeof(test.m_dValue));
    printf("Size of struct tagTest: %d\n", sizeof(test));
    return 0;
}