#include <stdio.h>

/* _  _  _  _  _  _  _  _
   9 10 11 12 13 14 15 16
   1  2  3  4  5  6  7  8
   Да се състави програма, с помощта на която играч може да играе (с право на връщане на ходовете) 
   следната игра СОЛИТЕР: На игралното поле са поставени 16 номерирани пулове и три реда с по осем позиции. 
   Целта е да се извадят от игра всички пулове с изключение на номер 1. Може да се прескача през някой пул 
   на свободна клетка, но не се разрешава движение по диагонал. Например възможни са ходове 1-9; 2-10; 1-2 и т.н. 
   По тази схема 1 прескача 9 и 9х излиза от игра – отстранява се от полето, 
   след това 2 прескача 10 и 10 отпада от играта; по-нататък 1 прескача 2 и 2 излиза от игра. */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 3
#define COLUMNS 8
#define INVALID 255
#define MAX_MOVES 1000

typedef struct coordinates {
    uint8_t x;
    uint8_t y;
} Coords;

typedef struct rev_move {
    Coords p1;
    Coords p2;
    Coords p3;
    uint8_t val_p1;
    uint8_t val_p2;
} ReverseMove;


uint8_t board[ROWS][COLUMNS] = {
   { 0,  0,  0,  0,  0,  0,  0,  0},
   { 9, 10, 11, 12, 13, 14, 15, 16},
   { 1,  2,  3,  4,  5,  6,  7,  8}
};

unsigned int move_cnt = 0;

ReverseMove moves[MAX_MOVES];

void print_board(void) {
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == 0)
                printf("  |");
            else
                printf("%2u|", board[i][j]);
        }
        printf("\n");
    }
}

int is_game_over(){
    unsigned int sum = 0;
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
         sum += board[i][j];
      }
   }
   return sum > 1;
}

Coords find_piece(uint8_t piece){
    Coords piece_cords = {INVALID,INVALID};
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
         if (board[i][j] == piece){
            piece_cords.x = i;
            piece_cords.y = j;
         }
      }
   }
   return piece_cords; 
}

int check_move(Coords p1, Coords p2){
    if(p1.x != 255 && p1.y != 255 && p2.x != 255 && p2.y != 255){
        uint8_t x_moves = p1.x>p2.x?p1.x-p2.x:p2.x-p1.x;
        uint8_t y_moves = p1.y>p2.y?p1.y-p2.y:p2.y-p1.y;
        if (x_moves == 1 && y_moves == 0){
            return 1;
        }else if (x_moves == 0 && y_moves == 1){
            return 2;
        }
    }
    return 0;
}

ReverseMove move(Coords p1, Coords p2){
    ReverseMove move;
    move.p1 = p1;
    move.p2 = p2;
    move.val_p1 = board[p1.x][p1.y];
    move.val_p2 = board[p2.x][p2.y];
    
    uint8_t val = board[p1.x][p1.y];
    board[p2.x][p2.y] = 0;
    if(p1.x > p2.x){
        board[p1.x][p1.y] = 0;
        board[p1.x-2][p1.y] = val;
        move.p3.x = p1.x-2;
        move.p3.y = p1.y;
    }else if(p1.x < p2.x){
        board[p1.x][p1.y] = 0;
        board[p1.x+2][p1.y] = val;
        move.p3.x = p1.x+2;
        move.p3.y = p1.y;
    }else if(p1.y > p2.y){
        board[p1.x][p1.y] = 0;
        board[p1.x][p1.y-2] = val;
        move.p3.x = p1.x;
        move.p3.y = p1.y-2;
    }else if(p1.y < p2.y){
        board[p1.x][p1.y] = 0;
        board[p1.x][p1.y+2] = val;
        move.p3.x = p1.x;
        move.p3.y = p1.y+2;
    }
    move_cnt++;
    return move;
}

void reverse_move(){
    ReverseMove move = moves[move_cnt - 1];
    board[move.p1.x][move.p1.y] = move.val_p1;
    board[move.p2.x][move.p2.y] = move.val_p2;
    board[move.p3.x][move.p3.y] = 0;
    move_cnt--;
}

ReverseMove choose_move(void) {
   Coords piece = { 0, 0 };
   unsigned int piece1=0,piece2=0;
   while(1) {
        printf("Enter piece numbers (0 0 for reverse move): ");
        fflush(stdin);
        scanf("%u %u", &piece1, &piece2);
        Coords p1_coords = find_piece(piece1);
        Coords p2_coords = find_piece(piece2);
        if(piece1 == 0 && piece2 == 0){
            reverse_move();
            break;
        }else if (check_move(p1_coords, p2_coords)){
            return move(p1_coords,p2_coords);
        }else{
            printf("Wrong input!\n");
        }
   }
}

int main()
{
    while(is_game_over())
    {
        print_board();
        moves[move_cnt] = choose_move();
        system("clear");
    }
    printf("Game over! You win!");
    return 0;
}
