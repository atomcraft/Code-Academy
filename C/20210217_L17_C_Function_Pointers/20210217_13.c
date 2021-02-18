/*
Задача 14.
Напишете програма, която да проверява дали 2 стринга (масива) са
анаграми и имат всичките букви на другата дума. Използвайте функции.
Примери за анаграми: реклама: карамел; босилек: обелиск.
*/

#include <stdio.h>
int checkAnagram(char [], char []);

int main(void){
  char a[1000], b[1000];

  printf("Enter the first string\n");
  scanf("%s", &a);
  printf("Enter the second string\n");
  scanf("%s", &b);

  if (checkAnagram(a, b))
    printf("The strings are anagrams.\n");
  else
    printf("The strings aren't anagrams.\n");

  return 0;
}

int checkAnagram(char a[], char b[]){
  int first[26] = {0}, second[26] = {0}, c=0;

  // Calculating frequency of characters of the first string

  while (a[c] != '\0'){
    first[a[c]-'a']++;
    c++;
  }

  c = 0;

  while (b[c] != '\0'){
    second[b[c]-'a']++;
    c++;
  }

  // Comparing the frequency of characters

  for (c = 0; c < 26; c++)
    if (first[c] != second[c])
      return 0;

  return 1;
}