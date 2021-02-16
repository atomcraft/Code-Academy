/*
Задача 18. Връщаме се на кода написан в задача 17. Нека сега
отпечатаме стринговете с
декрементиране, започвайки отзад-напред.
*to -- = *from --;
Проверете готовата функция strlen.
https://www.tutorialspoint.com/c_standard_library/c_function_strlen.htm
Помислете как да направите проверка във функцията за копиране, дали
размерът на стринга, в който копираме, не е по-малък от размера на
стринга, от който копираме, и какво да се случва тогава
*/
#include <stdio.h>
#include <string.h>

void fCopyString (char *to, char *from){
    while (*from){
        *to -- = *from --;
    }
}

int main(void){
    char string1[]= "A string to be copied.\0";
    char string2[22];
    memset (string2, '\0', sizeof(string2));
    int len=0;
    len= strlen(string1);
    printf("Len: %d", len);
    fCopyString (&string2 [len-1], &string1 [len-1]);
    printf ("\n%s\n", string2);
    return 0;
}
