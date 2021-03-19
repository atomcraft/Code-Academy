#include <stdio.h>
#include <openssl/md5.h>
#include <unistd.h>

/* gcc -g -Wall -o file file.c -lssl -lcrypto */

int main(void){
    unsigned char c[MD5_DIGEST_LENGTH];
    char *filename="test.txt";
    int i;
    FILE *inFile = fopen (filename, "rb");
    MD5_CTX mdContext;
    int bytes;
    unsigned char data[1024];

    if (inFile == NULL){
        printf ("%s can't be opened.\n", filename);
        return 0;
    }

    MD5_Init (&mdContext);
    while ((bytes = fread (data, 1, 1024, inFile)) != 0)
        MD5_Update (&mdContext, data, bytes);
    MD5_Final (c,&mdContext);
    for(i = 0; i < MD5_DIGEST_LENGTH; i++) printf("%02x", c[i]);
    printf (" %s\n", filename);
    fclose (inFile);
    return 0;



    // int n;
    // unsigned char out[MD5_DIGEST_LENGTH];
    // MD5_CTX c;
    // char buf[512];
    // ssize_t bytes;
    // MD5_Init(&c);
    // bytes = read(STDIN_FILENO, buf, 512);
    // while(bytes > 0){
    //     MD5_Update(&c, buf, bytes);
    //     bytes = read(STDIN_FILENO, buf, 512);
    // }
    // MD5_Final(out, &c);
    // for(n = 0; n < MD5_DIGEST_LENGTH; n++){
    //     printf("%02x", out[n]);
    // }
    // return 0;        
}