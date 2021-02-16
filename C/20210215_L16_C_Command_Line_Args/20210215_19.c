/*
Задача 20. Дефинирайте стринг „I am a poor programmer”.
Заменете през пойнтер “poor” с “great”.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *changewords(char *sentence, char *find, char *replace){
    char *dest = malloc (strlen(sentence)-strlen(find)+strlen(replace)+1);
    char *destptr = dest;
    *dest = 0;
    while (*sentence){
        if (!strncmp (sentence, find, strlen(find))){
            strcat (destptr, replace);
            sentence += strlen(find);
            destptr += strlen(replace);
        } else{
            *destptr = *sentence;
            destptr++;
            sentence++;
        }
    }
    *destptr = 0;
    return dest;
}

int main (void){
    char *result;
    result = changewords ("I am a poor programmer","poor","great");
    printf ("%s\n", result);
    free (result);
    return 0;
}