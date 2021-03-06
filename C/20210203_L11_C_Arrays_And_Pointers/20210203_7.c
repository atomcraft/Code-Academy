/*
Задача 7. Дефинирайте масив int с 10 елемента. Дефинирайте
пойнтер, който ще сочи към масива. Насочете пойнтера към масива. Нужно
ли е да използвате &? Какво представлява името на масива? Какво сочи?
Колко начина има за да изпишете насочването на пойнтера към масива.
Има ли разлика между тях?
*/

#include <stdio.h>

int main(void){
    int n[10] = {100,90,80,70,60,50,40,30,20,10};
    /*Името на масива съхранява адреса на първият елемент от масива
    Когато се извика във функция, предава адреса на първият елемент
    от масива. Разликата между името на масива и указател е. че указател е
    променлива и можем да извършваме аритметични операции - ++*p и 
    присвояване - p = n. С името на масива това не е възможно.
    Указателиете и аритметиката с указатели е по-бърза от индексирането.
    */
    int *nP = n; /* Възможно е и без &  като се посочи само името на масива.*/
    int *nP1 = &n[0];
    int n0 = *(nP+0); /*Придава стойноста на n[0] на променливата n0 */ 
 /* int *nP2 = &n; /*warning: initialization of 'int *' from incompatible pointer type 'int (*)[10]*/
    printf("%p\n", nP);
    printf("%p\n", nP1);
    printf("%d\n", n0);
 /* printf("%p\n", nP2);*/
    printf("%p\n", n);
    return 0;
}