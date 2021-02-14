/*
Задача 6. Пренапишете функцията int linear_search(const int a[], int n, int
key); използайки пойнтер аритмртиката без инкрементиращи променливи.
*/
#include <stdio.h>

void search(int arr[], int n, int key){
    int i;
    int *p = &arr[0];
    for ( ; *p < n; ){
        if (*p == key){
            printf("Element is present in the array");
            return;
        }
        p = p + 1;
    }
    printf("Element is not present in the array");       
}
 
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int key = 3;
    int n = 5;
    search(arr, n, key);
    return 0;
}