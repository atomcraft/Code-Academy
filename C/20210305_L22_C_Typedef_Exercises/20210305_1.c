/*За да направи една етажерка, дърводелец се нуждае от следните
компоненти: 4 дълги дъски, 6 къси дъски, 12 малки скоби, 2 големи скоби и 14 винта.
Дърводелецът има на склад А дълги дъски, В къси дъски, С малки скоби, D големи скоби и E
винта. Колко етажерки може да направи дърводелецът?
Изход:
С наличните на склад материали (33 дълги дъски, 55 къси дъски, 88 малки скоби, 22 големи
скоби и 99 винта) дърводелецът може да направи 7 етажерки. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> /*needed for Linux INT_MAX */

typedef struct shelf {
    int long_boards;
    int short_boards;
    int small_brackets;
    int large_brackets;
    int screws;
} t_shelf;

void getWhatMaterialWeHave(t_shelf *shelf1);
void howManyShelfsWeCanMake(t_shelf *shelf1, int num_long_boards, int num_short_boards,
                            int num_small_brackets, int num_large_brackets, int num_screws);

int main(void){
    typedef t_shelf *tp_shelf;
    tp_shelf shelf1 = (tp_shelf)malloc(sizeof(t_shelf));
    if (NULL == shelf1){
        printf("Allocation memory error\n");
        exit(1);
    }
    getWhatMaterialWeHave(shelf1);   
    free(shelf1);
    return 0;
}

void getWhatMaterialWeHave(t_shelf *shelf1){
    int num_long_boards = 0;
    int num_short_boards = 0;
    int num_small_brackets = 0;
    int num_large_brackets = 0;
    int num_screws = 0;
    printf("How many long boards do we have?\n");
    scanf("%d", &num_long_boards);
    printf("How many short boards do we have?\n");
    scanf("%d", &num_short_boards);
    printf("How many small brackets do we have?\n");
    scanf("%d", &num_small_brackets);
    printf("How many large brackets do we have?\n");
    scanf("%d", &num_large_brackets);
    printf("How many screws do we have?\n");
    scanf("%d", &num_screws);
    howManyShelfsWeCanMake(shelf1, num_long_boards, num_short_boards,
                           num_small_brackets, num_large_brackets, num_screws);

}

void howManyShelfsWeCanMake(t_shelf *shelf1, int num_long_boards, int num_short_boards,
                            int num_small_brackets, int num_large_brackets, int num_screws){
    int num_shelves = INT_MAX;
    int num_possible_shelves = 0;
    shelf1->long_boards = 4;
    shelf1->short_boards = 6;
    shelf1->small_brackets = 12;
    shelf1->large_brackets = 2;
    shelf1->screws = 14;
    num_possible_shelves = num_long_boards / shelf1->long_boards;
    if (num_shelves > num_possible_shelves){
        num_shelves = num_possible_shelves;
    }
    num_possible_shelves = num_short_boards / shelf1->short_boards;
    if (num_shelves > num_possible_shelves){
        num_shelves = num_possible_shelves;
    }
    num_possible_shelves = num_small_brackets / shelf1->small_brackets;
    if (num_shelves > num_possible_shelves){
        num_shelves = num_possible_shelves;
    }
    num_possible_shelves = num_large_brackets / shelf1->large_brackets;
    if (num_shelves > num_possible_shelves){
        num_shelves = num_possible_shelves;
    }
    num_possible_shelves = num_screws / shelf1->screws;
    if (num_shelves > num_possible_shelves){
        num_shelves = num_possible_shelves;
    }

    printf("With our available materials we can made %d shelves.\n", num_shelves);
}