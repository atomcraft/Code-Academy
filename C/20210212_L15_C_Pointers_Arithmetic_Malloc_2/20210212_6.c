/*
Задача 6.
Заделете динамично с malloc памет за char* buffer с размер size = 2,
въвеждайте символи от конзолата с getchar() ги четете, записвайте ги в
буфера. Увеличавайте размера на буфера преди да се препълни с
realloc().
Прекъснете цикъла с Ctrl + Z. Принтирайте буфера и освободете паметта.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *a = NULL;
    char size = 2;
    char count = 0;
    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        if (count >= size) {
            /* reallocate the buffer to 1.5x size */
            char newsize = size + size / 2 + 16;
            char *new_a = realloc(a, newsize);
            if (new_a == NULL) {
                printf("out of memory");
                free(a);
                return 1;
            }
            a = new_a;
            size = newsize;
        }
        a[count++] = c;
    }

    for (int i = 0; i < count; i++) {
        putchar(a[i]);
    }
    free(a);
    return 0;
}
