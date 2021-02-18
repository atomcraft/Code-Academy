/*
Задача 22.
Дадена е шахматна дъска 8 х 8 с една фигура кон, в някой от
четирите ъгъла. Напишете програма, която движи коня по
стандартния начин: 2 полета в една посока и едно
перпендикулярно на избраната посока с 2-те полета. Програмата
извежда всеки ход на коня във вида A1, C2, ... и завършва, когато
всички полета на дъската са обходени.
*/


#include <stdio.h>
#include <stdlib.h>
 
void printBoard(int chess[][8]);
int randomHorse(int chess[][8], int i, int j);
 
int main(void) {
 
   int r,c, i, j, numofsquares;
   int chess[8][8];
   for(r = 0; r < 8; r++)
      for(c = 0; c < 8; c++)
         chess[r][c] = 1;
  
   i = -1;
   while(i < 0 || i > 7) {
      printf("\nEnter your starting row [0-7] ");
      scanf("%d", &i);
   }
   j = -1;
   while(j < 0 || j > 7) {
      printf("\nEnter your starting column [0-7] ");
      scanf("%d", &j);
   }
 
   chess[i][j] = 1;
   numofsquares = randomHorse(chess, i, j);
   printBoard(chess);
 
   printf("Number of squares visited = %d\n", numofsquares);
 
   printf("\n\n\t\t\t     press enter when ready \n");
   i = getchar();
   return 0;
}
 
int randomHorse(int chess[][8], int i, int j) {
   int r = i;
   int c = j;
   int k, kmoves, moves, validmoves, n, sqr;
   int valid[8] = { 0 };
   moves = kmoves = 0;
/* 
Log:
-1 = sqr has not been visited by the knight
>0= sqr has been visited by the knight
-2= sqr is a legal next move by the knight
 
array rows are in ascending order on the screen
   0
   1
   2
*/
   while(1) {
      //check the 8 (max) possible knight moves
      if((r > 1) && (c < 7) && (chess[r-2][c+1] == -1))  //1:30 o'clock move ok?
         chess[r-2][c+1] = -2; 
      if((r > 0) && (c < 6) && (chess[r-1][c+2] == -1)) //2:30 move
         chess[r-1][c+2] = -2;
      if((r < 7) && (c < 6) && (chess[r+1][c+2] == -1)) //3:30 move
         chess[r+1][c+2] = -2;
      if((r < 6) && (c < 7) && (chess[r+2][c+1] == -1)) //5:30 move
         chess[r+2][c+1] = -2;
 
     //etc., for all 8 possible moves.
 
      for(r = 0, k = 0; r < 8; r++) {
         for(c = 0; c < 8; c++) { 
            if(chess[r][c] == -2) { 
               validmoves++;
               if(!r) sqr = c;
               else sqr = r * 10 + c;
               valid[k] = sqr;
               ++k;
            }
         }
      }
      if(!moves) {
         return chess[i][j];
      }
      n = rand() % validmoves; 
      if(valid[n] < 8) {
         r = 0;
         c = valid[n];
      }
      else {
         r = valid[n] / 10;
         c = valid[n] % 10;
      }
      chess[r][c] = kmoves;  
      ++kmoves;
      print_board(chess);
      moves = getchar();
 
      //resets
      moves = 0;
      for(i = 0; i < 8; i++)
         valid[i] = 0;
     validmoves = 0;
             
 
   }
 
}
void printBoard(int chess[][8]) {
   int i, r, c;
   printf("\n\n");
 
   for(r = 0; r < 8; r++) {
      for(i = 0; i < 9; i++) {
         if(i < 8)
            printf("|---");
         else
            printf("|");
      }
      printf("\n");
 
      for(c = 0; c < 8; c++) {
         printf("| %d ", chess[r][c]);
         if(c % 7 == 0 && c > 0)
            printf("|\n");
      }
   }
   for(i = 0; i < 9; i++) {
      if(i < 8)
         printf("|---");
      else
         printf("|");
   }
   printf("\n");
}