/*
Задача 9*.
Дефинирайте две функции в хедър файл и едната
използваща setjmp, за да сетне мястото, на което другата
чрез longjmp да се върне.
Използвайте ги в отделен файл main.c , за да се види, че за
разлика от goto setjmp и longjmp могат да се използват в
различни файлове.
*/

#include "sjlj.h"

jmp_buf buf;

int main(void){
    if(sj("Vasko", buf) != 0) exit(0);
    lj(3,buf);
    return 0;
}