#include <stdio.h>

int main(void){
    printf("Press 1 to see message Hello\nPress 2 to see Poem\n"
           "Press 3 to see hidden message\n");
    int m = 0;
    scanf("%d", &m);
    switch (m){
        case 1:
            printf("hello world\n");
            break;
        case 2:
            printf("Mary had a little lamb,\nIts fleece was white as snow;\n"
                   "And everywhere that Mary went\nThe lamb wass ure to go.\n");
            break;
        case 3:
            printf("48\n");
            break;    
        default:
            break;
    }
    return 0;
}