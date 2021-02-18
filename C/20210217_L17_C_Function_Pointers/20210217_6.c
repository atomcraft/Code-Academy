/*
Задача 6.
Пребройте буквите ‚а‘ в стринг (може да е число и масив).
Пример: "This is a string to test my idea for search in a char and ....";
*/

#include <stdio.h>
#include <string.h>

int main(void){
   char *string = "This is a string to test my idea for search in a char and ....";
   int c = 0, count = 0;

   while (string[c] != '\0') {
      if (string[c] == 'a') {
         count++;
      }
      c++;
   }
   printf("a occurs %d times in the string.\n", count);
   return 0;
}