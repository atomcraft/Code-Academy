/*
Задача 3.Какво е грешното на този код?
*/

void my_strcpy(char *t, char *s){
for(; *t; t++, s++)
*s = *t;
}