/*
Задача 15.
Ще копираме стрингове. Дефинирайте и инизиалицирайте два стринга:
string 1: "A string to be copied."
string3: "I am very good in strings coping!"
Дефинирайте и два празни стринга, в които ще копираме string 2,
string4. Дефинирайте функция, която през пойнтери ще извърши
копирането от стринг към стринг. Използвайте while и факта, че
*pointer++ отива към следващия символ.
Помислете за терминиращия символ. Принтирайте двата изкопирани
стринга.
Извикайте функцията и копирайте от string1 в string4.
*/

#include <stdio.h>
#include <string.h>

void stringCopy(char *s1, char *s2);

int main(void){
    char *string1 = "A string to be copied";
    char *string2 = "I am very good in strings coping!";
    char string3[strlen(string1) + 1];
    char string4[strlen(string2) + 1];
    stringCopy(string2, string4);
    printf("String 4: %s\n", string4);
    stringCopy(string1, string3);
    printf("String 3: %s\n", string3);
    return 0;
}
/*
void stringCopy(char *s1, char *s2){
    while (*++s2 = *++s1){
        ;
    }
}
*/

void stringCopy(char *s1, char *s2){
    while (*s2++ = *s1++){
        ;
    }
}
