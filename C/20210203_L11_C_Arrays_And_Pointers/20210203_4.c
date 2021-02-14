/*
Задача 4.Напишете функцията int binarySearch(int a[], int n, int
x), която получава като първи аргумент началото на масив а,
втория аргумент е дължината на масива, а третия аргумент е
числото, което търсим. Знаем, че масива в който ще търсим
елемента е предварително подреден. Сравняваме тъсения
елемент с елемента в средата на масива. Ако той е по голям от
този в средата търсим елемента от средата до края, ако е помалък го търсим в частта от началото до средата. Това се
повтаря, докато елемента от масива не стане равен с търсения.
Тогава връщаме номера на който се намира елемента в масива
или -1 ако не се съдържа в масива.
*/

#include <stdio.h>

int binarySearch(int a[], int n, int x);

int main(void){
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 90;
    int posX = binarySearch(a, n, x);
    printf("%d\n", posX);

    if (posX != -1){
        printf("Element found on position %d\n", posX);
    } else{
        printf("Element not found");
    }
    return 0;   
}

int binarySearch(int a[], int n, int x){
    int low, mid, high;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != a[mid]){
        if (x < a[mid])
            high = mid - 1;
        else
            low = mid +1;
        mid = (low + high) / 2;
    }
    if (x == a[mid])
        return mid;
    else
        return -1;
}