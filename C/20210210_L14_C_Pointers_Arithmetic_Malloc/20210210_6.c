/*
Задача 5. Пренапишете алгоритъма за сортиране без да използвате
инкрементиращи променливи.
void sort ( int a[], int n){
int i, j, temp;
for ( i = 0; i < n - 1; ++i )
for ( j = i + 1; j < n; ++j )
if ( a[i] > a[j] ) {
temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
*/

#include <stdio.h>

void sort ( int a[], int n){
    int i, j, temp;
    int *pI = &a[0];
    int *pJ = &a[1];
    for ( ; *pI < n-1; *pI++){
        for ( ; *pJ < n; ++pJ){
            if ( *pI > *pJ ){
                temp = *pI;
                *pI = *pJ;
                *pJ = temp;
            }
        }
    }
}

int main(void){
    int arr[] = {5, 1, 10, 99, 2, 3, 77, 4};
    int n = 8;
    sort(arr, n);
    for (int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
    return 0;    
}