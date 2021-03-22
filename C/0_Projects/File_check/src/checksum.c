#include "files_check.h"

unsigned int checksum (char *name){
    FILE *fp;
    size_t len;
    char buffer[MAX_PATH];
    if (NULL == (fp = fopen(name, "rb"))){
        fprintf(stderr, "Failed to open file %s.\n", name);
        exit(-1);
    }
    len = fread(buffer, sizeof(char), sizeof(buffer), fp);
    unsigned int seed = 0;

    for (int i = 0; i < len; ++i){
        seed += (unsigned int) buffer[i];
        
    }
    fclose(fp);
    return seed;   
}