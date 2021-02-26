/*
Задача 3. Дефинирайте потребителски тип към
указател.Създайте променлива, насочете указателя
към нея, използвайки новия потребителски тип.
*/


#include <stdio.h>

// typedef long long int t_Long;
typedef int* t_Int;

int main(void){
    int x = 5;
    t_Int pI = &x;
    printf("Value of pointer pI: %d\n", *pI);
    return 0;
}