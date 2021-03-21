#include "files_check.h"
#include <openssl/md5.h>
#include <stdio.h>

/* gcc -g -Wall -o file file.c -lssl -lcrypto */

/* MD5 Checksum creator */
char *md5Checksum(char *name){
    unsigned char c[MD5_DIGEST_LENGTH];
    unsigned char md5Char[MD5_DIGEST_LENGTH];
    char *md5 = (unsigned char *)malloc(sizeof(c));
    int i;
    FILE *inFile = fopen (name, "rb");
    MD5_CTX mdContext;
    int bytes;
    unsigned char data[1024];

    if (inFile == NULL){
        printf ("%s can't be opened.\n", name);
        return 0;
    }

    MD5_Init (&mdContext);
    while ((bytes = fread (data, 1, 1024, inFile)) != 0)
        MD5_Update (&mdContext, data, bytes);
    MD5_Final (c,&mdContext);
    md5 = c;
    fclose (inFile);
    return md5;
}
