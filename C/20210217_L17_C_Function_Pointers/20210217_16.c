/*
Задача 17*.
Имаме 2 сортирани масиви А и В с различна размерност k и l и
произволни int числа.
Образувайте масив С, образуван от смесването на А и В, така че С да
съдържа елементите на А и В, но да е подреден и да не се налага да го
сортираме отново.
*/

#include <stdio.h>
void merge(int [], int, int [], int, int []);

int main(void) {
  int a[100], b[100], k, l, c, sorted[200];

  printf("Input number of elements in first array\n");
  scanf("%d", &k);

  printf("Input %d integers\n", k);
  for (c = 0; c < k; c++) {
    scanf("%d", &a[c]);
  }

  printf("Input number of elements in second array\n");
  scanf("%d", &l);

  printf("Input %d integers\n", l);
  for (c = 0; c < l; c++) {
    scanf("%d", &b[c]);
  }

  merge(a, k, b, l, sorted);

  printf("Sorted array:\n");

  for (c = 0; c < k + l; c++) {
    printf("%d\n", sorted[c]);
  }

  return 0;
}

void merge(int a[], int k, int b[], int l, int sorted[]) {
  int i, j, k;

  j = k = 0;

  for (i = 0; i < m + n;) {
    if (j < m && k < n) {
      if (a[j] < b[k]) {
        sorted[i] = a[j];
        j++;
      }
      else {
        sorted[i] = b[k];
        k++;
      }
      i++;
    }
    else if (j == m) {
      for (; i < m + n;) {
        sorted[i] = b[k];
        k++;
        i++;
      }
    }
    else {
      for (; i < m + n;) {
        sorted[i] = a[j];
        j++;
        i++;
      }
    }
  }
}