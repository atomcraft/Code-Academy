/*
Задача 11. Дефинирайте структура, в която има член указател към самата
структура. Използвайте тази структура, за да дефинирате две променливи,
които се указват една друга.
*/

#include <stdio.h>

struct test{
    int a;
    int b;
    struct test *testPtr;
};

int main(void){
    struct test t1;
    struct test t2 = {&t1};
    t1.testPtr = &t2;
    printf("%p\n", &t1);
    printf("%p\n", t2.testPtr);
    printf("%p\n", &t2);
    printf("%p\n", t1.testPtr);
    return 0;
}