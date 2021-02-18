/*
There are a couple of different strategies possible, which all can be tailored further if necessary.

Copy one character at a time into the destination, scanning ahead for find and inserting replace when found, the original character when not found;
Copy one word at a time into the destination, scanning ahead for find and inserting replace when found, the original text when not found -- you will need this to replace entire words, rather than the literal find text only;
Use library functions to scan for the find text.
Which strategy to use depends on further (unmentioned) requirements, such as

case sensitive?
whole word only?
replace once only, or all occurrences?
can either find or replace begin and/or end with spaces, and are these significant?
One of the harder things is to assess the necessary memory needed for the new string. Below, I assume there is always one string found and replaced. To cater for 'any' new string length, without pre-scanning find and change, a safer bet is to assume every single character in sentence potentially can be replaced with replace; that is, the maximum amount of memory the destination would take up is strlen(sentence)*strlen(replace)+1 (the +1, as always, is to store the terminating zero in).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *changewords_1 (char *sentence, char *find, char *replace)
{
    char *dest = malloc (strlen(sentence)-strlen(find)+strlen(replace)+1);
    char *destptr = dest;

    *dest = 0;

    while (*sentence)
    {
        if (!strncmp (sentence, find, strlen(find)))
        {
            strcat (destptr, replace);
            sentence += strlen(find);
            destptr += strlen(replace);
        } else
        {
            *destptr = *sentence;
            destptr++;
            sentence++;
        }
    }
    *destptr = 0;
    return dest;
}

char *changewords_2 (char *sentence, char *find, char *replace)
{
    char *dest = malloc (strlen(sentence)-strlen(find)+strlen(replace)+1);
    char *destptr = dest;

    *dest = 0;

    while (*sentence)
    {
        if (!strncmp (sentence, find, strlen(find)) &&
            (sentence[strlen(find)] == 0 || sentence[strlen(find)] == ' '))
        {
            strcat (destptr, replace);
            sentence += strlen(find);
            destptr += strlen(replace);
        } else
        {
            while (*sentence && *sentence != ' ')
            {
                *destptr = *sentence;
                destptr++;
                sentence++;
            }
            while (*sentence == ' ')
            {
                *destptr = *sentence;
                destptr++;
                sentence++;
            }
        }
    }
    *destptr = 0;
    return dest;
}

char *changewords_3 (char *sentence, char *find, char *replace)
{
    char *dest = malloc (strlen(sentence)-strlen(find)+strlen(replace)+1);
    char *ptr;

    strcpy (dest, sentence);

    ptr = strstr (dest, find);
    if (ptr)
    {
        memmove (ptr+strlen(replace), ptr+strlen(find), strlen(ptr+strlen(find))+1);
        strncpy (ptr, replace, strlen(replace));
    }

    return dest;
}


int main (void)
{
    char *result;

    result = changewords_1 ("Hello I'm Number One","Number","Index");
    printf ("[%s]\n", result);
    free (result);

    result = changewords_2 ("Here Is The Onerous Number One ...","One","Four");
    printf ("[%s]\n", result);
    free (result);

    result = changewords_3 ("Here Is Number One Again","One","Fourty-Five Hundred");
    printf ("[%s]\n", result);
    free (result);

    return 0;
}