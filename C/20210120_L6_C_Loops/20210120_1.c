#include <stdio.h>

int main(void){
    printf("Press 1 to see message Hello\nPress 2 to see Poem\n"
           "Press 3 to see hidden message\n");
    int m = 0;
    scanf("%d", &m);
    if(m == 1){
        printf("hello world");
    } else if(m == 2){
        printf("Mary had a little lamb,\nIts fleece was white as snow;\n"
        "And everywhere that Mary went\nThe lamb wass ure to go.\n");
    }else{
        printf("48\n");
    }
    return 0;
}