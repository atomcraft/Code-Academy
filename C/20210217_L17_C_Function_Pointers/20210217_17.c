/*
Задача 18.
В С се използва библиотека за сортиране. Принципно имаме:
Selection Sort
Binary Sort
Merge Sort
Radix Sort
Insertion Sort
Намерете разликите между методите и кой кога е най-бърз.
*/


/*
Sorting Algorithm	Time Complexity	Space Complexity
Best Case	Average Case	Worst Case	Worst Case
Bubble Sort	Ω(N)	Θ(N2)	O(N2)	O(1)
Selection Sort	Ω(N2)	Θ(N2)	O(N2)	O(1)
Insertion Sort	Ω(N)	Θ(N2)	O(N2)	O(1)
Merge Sort	Ω(N log N)	Θ(N log N)	O(N log N)	O(N)
Heap Sort	Ω(N log N)	Θ(N log N)	O(N log N)	O(1)
Quick Sort	Ω(N log N)	Θ(N log N)	O(N2)	O(N log N)
Radix Sort	Ω(N k)	Θ(N k)	O(N k)	O(N + k)
Count Sort	Ω(N + k)	Θ(N + k)	O(N + k)	O(k)
Bucket Sort	Ω(N + k)	Θ(N + k)	O(N2)	O(N)
*/

/*
Selection Sort:

Find the minimum element in the array and swap it with the element in the 1st position.
Find the minimum element again in the remaining array[2, n] and swap it with the element at 2nd position, now we have two elements at their correct positions.
We have to do this n-1 times to sort the array.


#include <stdio.h>
int main()
{
  int array[100], n, c, d, position, t;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  for (c = 0; c < (n - 1); c++) // finding minimum element (n-1) times
  {
    position = c;

    for (d = c + 1; d < n; d++)
    {
      if (array[position] > array[d])
        position = d;
    }
    if (position != c)
    {
      t = array[c];
      array[c] = array[position];
      array[position] = t;
    }
  }

  printf("Sorted list in ascending order:\n");

  for (c = 0; c < n; c++)
    printf("%d\n", array[c]);

  return 0;
}
*/

/*
Bubble sort algorithm
Start at index zero, compare the element with the next one (a[0] & a[1] (a is the name of the array)), and swap if a[0] > a[1]. Now compare a[1] & a[2] and swap if a[1] > a[2]. Repeat this process until the end of the array. After doing this, the largest element is present at the end. This whole thing is known as a pass. In the first pass, we process array elements from [0,n-1].
Repeat step one but process array elements [0, n-2] because the last one, i.e., a[n-1], is present at its correct position. After this step, the largest two elements are present at the end.
Repeat this process n-1 times.

void bubble_sort(long list[], long n)
{
  long c, d, t;

  for (c = 0 ; c < n - 1; c++) {
    for (d = 0 ; d < n - c - 1; d++) {
      if (list[d] > list[d+1]) {
        Swapping
        t         = list[d];
        list[d]   = list[d+1];
        list[d+1] = t;
      }
    }
  }
}

*/

/*
Insertion sort:

Insertion sort in C: C program for insertion sort to sort numbers. 
This code implements insertion sort algorithm to arrange numbers of an array in ascending order. With a little modification, it will arrange numbers in descending order. Best case complexity of insertion sort is O(n), average and the worst case complexity is O(n2).
Best case complexity of insertion sort is O(n), average and the worst case complexity is O(n2).

#include <stdio.h>

int main()
{
  int n, array[1000], c, d, t, flag = 0;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  for (c = 1 ; c <= n - 1; c++) {
    t = array[c];

    for (d = c - 1 ; d >= 0; d--) {
      if (array[d] > t) {
        array[d+1] = array[d];
        flag = 1;
      }
      else
        break;
    }
    if (flag)
      array[d+1] = t;
  }

  printf("Sorted list in ascending order:\n");

  for (c = 0; c <= n - 1; c++) {
    printf("%d\n", array[c]);
  }

  return 0;
}
*/

/*
Binary search:

Binary search in C language to find an element in a sorted array. If the array isn't sorted, you must sort it using a sorting technique such as merge sort. If the element to search is present in the list, then we print its location.

int binarySearch(int a[], int s, int e, int f) {
  int m;
 
  if (s > e) // Not found
     return -1;

  m = (s + e)/2;

  if (a[m] == f)  // element found
    return m;
  else if (f > a[m])  
    return binarySearch(a, m+1, e, f);
  else
    return binarySearch(a, s, m-1, f);
}
*/

/*
Merge sort:

In Merge sort, we divide the array recursively in two halves, until each sub-array contains a single element, and then we merge the sub-array in a way that it results into a sorted array. merge() function merges two sorted sub-arrays into one, wherein it assumes that array[l .. n] and arr[n+1 .. r] are sorted.

Merge sort is one of the efficient & fastest sorting algorithms with the following time complexity:

Worst Case Time Complexity: O(n*log n)
Best Case Time Complexity: O(n*log n)
Average Time Complexity: O(n*log n)

void mergeSort(int arr[], int l, int r)
{
if (l < r)
{
// Finding mid element
int m = l+(r-l)/2;
// Recursively sorting both the halves
mergeSort(arr, l, m);
mergeSort(arr, m+1, r);
 
// Merge the array
merge(arr, l, m, r);
}
}

void merge(int arr[], int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
// Create temp arrays
int L[n1], R[n2];
// Copy data to temp array
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1+ j];
// Merge the temp arrays
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
arr[k] = L[i];
i++;
}
else
{
arr[k] = R[j];
j++;
}
k++;
}
// Copy the remaining elements of L[]
while (i < n1)
{
arr[k] = L[i];
i++;
k++;
}
// Copy the remaining elements of R[]
while (j < n2)
{
arr[k] = R[j];
j++;
k++;
}
}
*/

/*
Radix sort:
A sorting algorithm is an algorithm that puts components of a listing in a certain order. The most-used orders are numerical order and lexicographic order.

The Radix sort is a non-comparative sorting algorithm. The Radix sort algorithm is the most preferred algorithm for the unsorted list.

It sorts the elements by initially grouping the individual digits of the same place value. The idea of Radix Sort is to do digit by digit sort starting from least significant digit(LSD) to the most significant digit(MSD), according to their increasing/decreasing order. Radix sort is a small method that is used several times when alphabetizing an oversized list of names. Specifically, the list of names is initially sorted according to the first letter of every name, that is, the names are organized in twenty-six categories.

Complexity Analysis of Radix Sort O(m.n).

int get_max (int a[], int n){
   int max = a[0];
   for (int i = 1; i < n; i++)
      if (a[i] > max)
         max = a[i];
   return max;
}
void radix_sort (int a[], int n){
   int bucket[10][10], bucket_cnt[10];
   int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
   lar = get_max (a, n);
   while (lar > 0){
      NOP++;
      lar /= 10;
   }
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (a[i] / divisor) % 10;
         bucket[r][bucket_cnt[r]] = a[i];
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            a[i] = bucket[k][j];
            i++;
         }
      }
      divisor *= 10;
      printf ("After pass %d : ", pass + 1);
      for (i = 0; i < n; i++)
         printf ("%d ", a[i]);
      printf ("\n");
   }
}
*/

