#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void){
    FILE *fp = NULL;
    fp = fopen("unexisting.txt", "r");
    if( NULL == fp ){
        perror("ERR: ");
        printf("\nerrno: %d : %s\n", errno, strerror(errno));
    } else{
        fclose(fp);
    }
    return 0;
}