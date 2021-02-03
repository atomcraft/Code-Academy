/*
Упражнение 3.* Добавете проверка във функцията int atof(char
*s) дали подаденият стринг няма показни позиции преди числото
и, ако има, ги премахнете. Проверете дали числото не е
отрицателно и, ако е така, включете знака в резултата.
*/

#include <stdio.h>
#include <ctype.h>

double atof(char *s);

int main(void){
    char s[32] = "  -1234.56";
    double rez = atof(s);
    printf("Result: %f", rez);
    return 0;
}

double atof(char s[])
{
    double val, power;
    int i, sign;
for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}