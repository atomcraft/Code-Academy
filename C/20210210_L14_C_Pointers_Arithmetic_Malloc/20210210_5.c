/*
Задача 5. Пренапишете функцията за сумиране елементите на масив
използвайки пойнтер аритметика вместо инкрементиращa променливa i:
int sum_array(const int a[], int n){
int i, sum = 0;
for(i = 0; i < n; i++){
sum += a[ i ];
return sum;
}
*/

#include <stdio.h>

int sum_array(const int a[], int n){
    int *p = a;
    int sum = *p;
    for( ; *p < n;){
        sum += *(p + 1);
        *p++;
    }
    return sum;
}

int main(void){
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int result = sum_array(arr, n);
    printf("Result: %d", result);
    return 0;
}