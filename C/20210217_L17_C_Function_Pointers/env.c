#include <stdio.h>

int main(int argc, char *argv[], char **envp){
    int j, envc;
    char **p;

    for (j = 0; j < argc; j++){
        printf("arg\t%d\t\"%s\"\n", j, argv[j]);
    }
    for (p = envp, envc = 0; *p; p++, envc++){
        printf("env\t%d\t\"%s\"\n", envc, *p);
    }
    return 0;    
}