/*
Задача 7.
Хванете дълъг стринг и пребройте колко пъти се среща всяка буква от
азбуката в него. Запишете резултата в масив за всяка буква. 
Може ли да оптимизирате тази задача и да не се налага да въртим два
цикъла?
Как бихте направили същото, използвайки case?
*/

#include <stdio.h>
#include <string.h>

void countLettersInString(char *string, int *count){
    int c = 0, x;
    while (string[c] != '\0') {
   /** Considering characters from 'a' to 'z' only and ignoring others. */

      if (string[c] >= 'a' && string[c] <= 'z') {
         x = string[c] - 'a';
         count[x]++;
      }

      c++;
   }

}

int main(void){
   char *string = "This is a string to test my idea for search in a char and ....";
   int c = 0, count[26] = {0}, x;
   countLettersInString(string, count);

   for (c = 0; c < 26; c++)
         printf("%c occurs %d times in the string.\n", c + 'a', count[c]);

   return 0;
}