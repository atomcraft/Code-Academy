/*
Задача 2 Създайте нов потребителски тип
към тип long long int. Използвайте го във функцията
printf, отпечатайте размера.
*/
#include <stdio.h>

typedef long long int t_Long;

int main(void){
    printf("Size of t_Long: %ld\n", sizeof(t_Long));
    return 0;
}

#include <stdio.h>

typedef long long int myint;
typedef myint* myiptr;

int main() {
    myint x = 15;
    myiptr p = &x;

    printf("Enter value: ");
    scanf("%lld", p);
    printf("%lld", x);

    return 0;
}