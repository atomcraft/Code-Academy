#include <stdio.h>
#define MAXLINE 1000

int getln(char line[], int limit);
void removeTrailingBlanks(char line[], int length);

int main(void){
  int len;
  char line[MAXLINE];
  while ((len = getln(line, MAXLINE)) > 0){
    removeTrailingBlanks(line, len);
    printf("%s", line);
  }
  return 0;
}

int getln(char line[], int limit){
  int c, i;
  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
    line[i] = c;
  }
  if (c == '\n'){
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void removeTrailingBlanks(char line[], int length){
  int i;

  for (i = length - 2; line[i] == ' ' || line[i] == '\t'; --i){
      ;
  }

  line[i + 1] = '\n';
  line[i + 2] = '\0';
}