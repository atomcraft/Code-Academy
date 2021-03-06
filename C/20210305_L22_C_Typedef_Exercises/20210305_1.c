/*
Задача 1. За да направи една етажерка, дърводелец се нуждае от следните
компоненти: 4 дълги дъски, 6 къси дъски, 12 малки скоби, 2 големи скоби и 14 винта.
Дърводелецът има на склад А дълги дъски, В къси дъски, С малки скоби, D големи скоби и E
винта. Колко етажерки може да направи дърводелецът?
Изход:
С наличните на склад материали (33 дълги дъски, 55 къси дъски, 88 малки скоби, 22 големи
скоби и 99 винта) дърводелецът може да направи 7 етажерки. 
*/

#include <stdio.h>
#include <stdlib.h>

#define NEEDEDLONGBOARDS 4
#define NEEDEDSHORTBOARDS 6
#define NEEDEDSMALLBRACKETS 12
#define NEEDEDLARGEBRACKETS 2
#define NEEDEDSCREWS 14

typedef struct{
    int longBoards;
    int shortBoards;
    int smallBrackets;
    int largeBrackets;
    int screws;
} t_Shelf;

void makeShelf(t_Shelf shelfs);

int main(void){
    t_Shelf shelfs = {
        .longBoards = 33,
        .shortBoards = 55,
        .smallBrackets = 88,
        .largeBrackets = 22,
        .screws = 99
    };
    makeShelf(shelfs);
    return 0;

}

void makeShelf(t_Shelf shelf){
    int shelfsOnBssLongBoards = shelf.longBoards / NEEDEDLONGBOARDS;
    printf("Based on the available long boards, we can make: %d shelfs\n", shelfsOnBssLongBoards);
    int shelfsOnBssShortBoards = shelf.shortBoards / NEEDEDSHORTBOARDS;
    printf("Based on the available short boards, we can make: %d shelfs\n", shelfsOnBssShortBoards);
    int shelfsOnBssSmallBrackets = shelf.smallBrackets / NEEDEDSMALLBRACKETS;
    printf("Based on the available small brackets, we can make: %d shelfs\n", shelfsOnBssSmallBrackets);
    int shelfsOnBssLargeBrackets = shelf.largeBrackets / NEEDEDLARGEBRACKETS;
    printf("Based on the available large brackets, we can make: %d shelfs\n", shelfsOnBssLargeBrackets);
    int shelfsOnBssScrews = shelf.screws / NEEDEDSCREWS;
    printf("Based on the available screws, we can make: %d shelfs\n", shelfsOnBssScrews);

    if (shelf.largeBrackets < 3 || shelf.shortBoards < 6 || shelf.smallBrackets < 12 || shelf.largeBrackets < 2
        || shelf.screws < 14){
        printf("Not enough material to make a single shelf.");
        exit(1);
    } else if (shelfsOnBssLargeBrackets < shelfsOnBssShortBoards && shelfsOnBssLongBoards < shelfsOnBssSmallBrackets && shelfsOnBssLongBoards < shelfsOnBssLargeBrackets
        && shelfsOnBssLongBoards < shelfsOnBssScrews){
            printf("With the available, %d large boards, %d short boards, %d small brackets, %d large brackets and %d screws, we can make %d boards\n",
            shelf.longBoards, shelf.shortBoards, shelf.smallBrackets, shelf.largeBrackets, shelf.screws, shelfsOnBssLargeBrackets);
    } else if (shelfsOnBssShortBoards < shelfsOnBssLargeBrackets && shelfsOnBssShortBoards < shelfsOnBssSmallBrackets && shelfsOnBssShortBoards < shelfsOnBssLargeBrackets
        && shelfsOnBssShortBoards < shelfsOnBssScrews){
        printf("With the available, %d large boards, %d short boards, %d small brackets, %d large brackets and %d screws, we can make %d boards\n",
            shelf.longBoards, shelf.shortBoards, shelf.smallBrackets, shelf.largeBrackets, shelf.screws, shelfsOnBssShortBoards);
    } else if (shelfsOnBssSmallBrackets < shelfsOnBssLargeBrackets && shelfsOnBssSmallBrackets < shelfsOnBssShortBoards && shelfsOnBssSmallBrackets < shelfsOnBssLargeBrackets
        && shelfsOnBssSmallBrackets < shelfsOnBssScrews){
        printf("With the available, %d large boards, %d short boards, %d small brackets, %d large brackets and %d screws, we can make %d boards\n",
            shelf.longBoards, shelf.shortBoards, shelf.smallBrackets, shelf.largeBrackets, shelf.screws, shelfsOnBssSmallBrackets);
    } else if (shelfsOnBssLargeBrackets < shelfsOnBssScrews){
        printf("With the available, %d large boards, %d short boards, %d small brackets, %d large brackets and %d screws, we can make %d boards\n",
            shelf.longBoards, shelf.shortBoards, shelf.smallBrackets, shelf.largeBrackets, shelf.screws, shelfsOnBssLargeBrackets);
    } else{
        printf("With the available, %d large boards, %d short boards, %d small brackets, %d large brackets and %d screws, we can make %d boards\n",
            shelf.longBoards, shelf.shortBoards, shelf.smallBrackets, shelf.largeBrackets, shelf.screws, shelfsOnBssScrews);

    }   


}