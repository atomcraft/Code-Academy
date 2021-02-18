/*
Задача 23.
Използване на метода на мехурчето за сортиране на масив от
числа (виж. wiki).
Потребителят въвежда броя числа и след това въвежда всяко
едно число. Напишете програма, която трябва да сортира числата
и да ги изведе в сортиран вид, като най-малкото се извежда първо.
Вариация: Да се направи същото с масив от символи.
*/

#include <stdio.h>

int is_Array_Sorted(int [], int);
void bubble_sort(long [], long);

int main(void){
  int a[100], n, c;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &a[c]);

  if (is_Array_Sorted(a, n))
    printf("The array is sorted.\n");
  else
    printf("The array isn't sorted.\n");

   bubble_sort(a, n);

  printf("Sorted list in ascending order:\n");

  for (c = 0; c < n; c++)
     printf("%ld\n", a[c]);

  return 0;
}

int is_Array_Sorted(int a[], int n) {
  int c, d, sorted = 1, t;

  for (c = 0 ; c < n - 1; c++) {
    for (d = 0 ; d < n - c - 1; d++) {
      if (a[d] > a[d+1]) {
        t = a[d];
        a[d] = a[d+1];
        a[d+1] = t;
        return 0;
      }
    }
  }
  return 1;
}

void bubble_sort(long list[], long n){
  long c, d, t;

  for (c = 0 ; c < n - 1; c++) {
    for (d = 0 ; d < n - c - 1; d++) {
      if (list[d] > list[d+1]) {
        /* Swapping */
        t         = list[d];
        list[d]   = list[d+1];
        list[d+1] = t;
      }
    }
  }
}