/*
Задача 8 Напишете функция void reverse(char s[]), която обръща низа char s[
]. Използвайте for цикъл с два аргумента, разделени със запетая
i = 0, j = strlen(s) – 1; i < j; i++, j-- , за да обърнете стринга.
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main(void){
    char s[] = "Hello World!";
    reverse(s);
    printf("%s", s);
    return 0;
}

void reverse(char s[]){
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
