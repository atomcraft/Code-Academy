/*
Задача 10. Направете два триъгълника с отместване.
*/

#include <stdio.h>

struct point{
    int x;
    int y;
};

struct point makepoint(int x, int y){
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int main(void){
  int len = 10;
  for (int i = 1; i <= len; i++){
    for (int j = 1; j <= i; j++){
      printf("*");
    }
    for (int space = len -1; space >= 1; space--){
      printf(" ");
    }
    for (int x = 1; x <= i; x++){
      printf("*");
    }
    printf("\n");
  }
  return 0;
}