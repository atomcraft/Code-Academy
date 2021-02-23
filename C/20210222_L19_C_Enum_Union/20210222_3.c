/*
Задача 3.
Дефинирайте структура с три елемента, които са променливи тип int, char и float.
Елементите да са наименование на продукт, цена и количество.
Задайте стойност на всеки от елементите, както следва: chocolate, 2.50, 50. Отпечатайте
на екрана.
*/

#include <stdio.h>
#include <string.h>

struct name{
    int quantity;
    char productName[128];
    float price;
};

int main(void){
    struct name product; /*дефинираме нова променлива*/
    product.quantity = 50;
    strcpy (product.productName , "chocolate");
    product.price = 2.50;
    printf("Product: %s\n", product.productName);
    printf("Quantity: %d\n", product.quantity);
    printf("Price: %.2f\n", product.price);
    return 0;
}

