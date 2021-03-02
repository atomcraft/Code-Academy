/* _  _  _  _  _  _  _  _
   9 10 11 12 13 14 15 16
   1  2  3  4  5  6  7  8
   Да се състави програма, с помощта на която играч може да играе (с право на връщане на ходовете) 
   следната игра СОЛИТЕР: На игралното поле са поставени 16 номерирани пулове и три реда с по осем позиции. 
   Целта е да се извадят от игра всички пулове с изключение на номер 1. Може да се прескача през някой пул 
   на свободна клетка, но не се разрешава движение по диагонал. Например възможни са ходове 1-9; 2-10; 1-2 и т.н. 
   По тази схема 1 прескача 9 и 9х излиза от игра – отстранява се от полето, 
   след това 2 прескача 10 и 10 отпада от играта; по-нататък 1 прескача 2 и 2 излиза от игра. */

// #include <stdio.h>
// #include <string.h>

// #define ROWS 3
// #define COLUMNS 8
// char board[ROWS][COLUMNS] = {
//    { 0,  0,  0,  0,  0,  0,  0,  0},
//    { 9, 10, 11, 12, 13, 14, 15, 16},
//    { 1,  2,  3,  4,  5,  6,  7,  8}
// };

// typedef struct coordinates {
//    char x;
//    char y;
// } coords;
// #define BELOW(coords) board[coords.x-1][coords.y]
// #define TWOBELOW(coords) board[coords.x-1][coords.y+1]
// #define ABOVE(coords) board[coords.x-1][coords.y-2]
// #define TWOABOVE(coords) board[coords.x-1][coords.y-3]
// #define LEFTOF(coords) board[coords.x-2][coords.y-1]
// #define TWOLEFTOF(coords) board[coords.x-3][coords.y-1]
// #define RIGHTOF(coords) board[coords.x][coords.y-1]
// #define TWORIGHTOF(coords) board[coords.x+1][coords.y-1]

// unsigned char validMoves = 0;
// #define UPBIT 1
// #define DOWNBIT 2
// #define LEFTBIT 4
// #define RIGHTBIT 8


// void printBoard(void);

// int main() {
//    printBoard();
   
//    chooseMove(choosePiece());
   
//    return 0;
// }

// coords choosePiece(void) {
//    coords chosen = { 0, 0 };
//    while(1) {
//       printf("Enter coordinates of piece to move: ");
//       fflush(stdin);
//       scanf("%d %d", &chosen.x, &chosen.y);
//       if (chosen.x > COLUMNS || chosen.y > ROWS) {
//          printf("Invalid coordinates.\n");
//       } else if (board[chosen.x-1][chosen.y-1] == 0) {
//          printf("No piece is present there.\n");
//       } else {
//          break;
//       }
//    }
//    validMoves = 0;
//    if (chosen.y > 1 && ABOVE(chosen) != 0 && TWOABOVE(chosen) == 0) {
//       validMoves |= UPBIT;
//    }
//    if (chosen.y < 2 && BELOW(chosen) != 0 && TWOBELOW(chosen) == 0) {
//       validMoves |= DOWNBIT;
//    }
//    if (chosen.x > 1 && LEFTOF(chosen) != 0 && TWOLEFTOF(chosen) == 0) {
//       validMoves |= LEFTBIT;
//    }
//    if (chosen.x > 1 && RIGHTOF(chosen) != 0 && TWORIGHTOF(chosen) == 0) {
//       validMoves |= RIGHTBIT;
//    }
//    return chosen;
// }

// int move(coords piece, char direction) {
//    switch(direction) {
//       case 'u':
//          if (!(validMoves & UPBIT)) {
//             printf("Illegal move.\n");
//             return 0;
//          }
//          break;
//       case 'd':
//          if (!(validMoves & UPBIT)) {
//             printf("Illegal move.\n");
//             return 0;
//          }
//          break;
//       case 'l':
//          if (!(validMoves & UPBIT)) {
//             printf("Illegal move.\n");
//             return 0;
//          }
//          break;
//       case 'r':
//          if (!(validMoves & UPBIT)) {
//             printf("Illegal move.\n");
//             return 0;
//          }
//          break;
//       default:
//          printf("Invalid move.\n");
//          return 0;
//    }
   
// }

// void chooseMove(coords piece) {
//    char input = 0;
//    while (input = 0) {
//       printf("Select the direction of your move"
//       "\nu for Up\n"
//       "\nd for down\n"
//       "\nl for left\n"
//       "\nr for right\n");
//       fflush(stdin);
//       scanf("%c", &direction);
//       input = move(piece, input);
//    }
// }

// void printBoard(void) {
//    for (int i = 0; i < COLUMNS * ROWS/COLUMNS; i++) {
//       for (int j = 0; j < COLUMNS; j++) {
//          char pos = ((char *)board)[i*COLUMNS + j];
//       printf("\n");
//    }
// }