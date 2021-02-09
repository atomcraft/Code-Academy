/*
Задача 4. Даден е едномерен масив с N елемента (вие изберете
стойност на N),напишете функция, която изчислява средната стойност на
елементите в масива, като я връща като double float.
*/

#include <stdio.h>

double findAvg(double *, int);

int main(void){
    double arr[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int size = sizeof(arr) / sizeof(arr[0]);
    double avgNum = findAvg(arr, size);
    printf("Average: %.2lf", avgNum);
    return 0;        
}

double findAvg(double *arr, int size){
    double average = 0.0;

    for (int i = 0; i < size; i++){
        average += arr[i];
    }
    return average /= size;
}

