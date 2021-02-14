/*
6. Напишете функция, която получава указател към масив с числа и връща
най-голямото от тях. 
*/
#include <stdio.h>

int maxValue(int *, int size);

int main(void){
    int arr[] = {1, 8, 88, 99, 192, 3, 5};
    int *p = arr;
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxNum = maxValue(p, size);
    printf("The max values is %d", maxNum);
    return 0;
}

int maxValue(int *a, int size){
    int max = 0;
    for (int i = 0; i < size; i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
}