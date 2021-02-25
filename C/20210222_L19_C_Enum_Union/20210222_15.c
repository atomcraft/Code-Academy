/*
Задача 15.
Дефинирайте структура с 4 полета (int. char[10], double, enum),
направете масив от 20 структури и ги попълнете. Изведете масива
от структури на стандартния изход в CSV формат (
https://en.wikipedia.org/wiki/Comma-separated_values ). Пример:
prog1 > structs20.cvs
*/
#include <stdio.h>
#include <stdlib.h>
FILE * fptr;

struct bookInfo{
    char title[40];
    char author[25];
    float price;
    int pages;
};

int main(void){
    int ctr;
    struct bookInfo books[3];
    for (ctr = 0; ctr < 3; ctr++){
        printf("What is the name of the book #%d?\n", (ctr+1));
        scanf("%s", &books[ctr].title);
        puts("Who is the author? ");
        scanf("%s", &books[ctr].author);
        puts("How much did the book cost? ");
        scanf(" $%f", &books[ctr].price);
        puts("How many pages in the book? ");
        scanf(" %d", &books[ctr].pages);
        getchar(); //Clears last newline for next loop
    }
    fptr = fopen("BookInfo.csv","w");
    if (fptr == 0){
        printf("Error--file could not be opened.\n");
        exit (1);
    }
    fprintf(fptr, "\n\nHere is the collection of books: \n");
    for (ctr = 0; ctr < 3; ctr++){
        fprintf(fptr, "#%d: %s by %s", (ctr+1), books[ctr].title,
        books[ctr].author);
        fprintf(fptr, "\nIt is %d pages and cost $%.2f",
        books[ctr].pages, books[ctr].price);
        fprintf(fptr, "\n\n");
    }
    fclose(fptr); 
    return 0;
}

