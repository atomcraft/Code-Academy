#include <stdio.h>
const char c_chNEW_LINE = '\n';
const unsigned c_uMAX_LOOP_COUNT = 1024 * 0xFFFF;
const double c_dfREAL_VALUE = 1.0L / 3.0;

int main(void){
    printf("Constant: c_uMAX_LOOP_COUNT = %d %c", c_uMAX_LOOP_COUNT, 
            c_chNEW_LINE);
    printf("Constant: c_dfREAL_VALUE = %lf %c", c_dfREAL_VALUE,
            c_chNEW_LINE);
    return 0;
}