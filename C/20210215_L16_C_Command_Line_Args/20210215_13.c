/*
Задача 13.
Напишете програма, която намира дължината на стринг с
пойнтер! (без да използва length());
*/

#include <stdio.h>

int main(){
    char s[] = "alabala portokala, koj izqde kashkavala"; 
    int length = 0;
    char *ptr;      
    ptr = s;  
    while (*ptr++) length++;
    printf("%d\n",length);
    return 0;
}