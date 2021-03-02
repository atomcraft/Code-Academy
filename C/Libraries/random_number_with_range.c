/*
Here we will see how to generate random number in given range using C. To solve this problem, we will use the srand() function. 
The current time will be used to seed the srad() function.
This function cannot generate random number in any range, it can generate number between 0 to some value. So for it, we have to follow one trick. 
We will generate random number in between 0 to (upper – lower + 1), then add the lower limit for offsetting.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void generate_random(int l, int r, int count) { //this will generate random number in range l and r
   int i;
   for (i = 0; i < count; i++) {
      int rand_num = (rand() % (r - l + 1)) + l;
      printf("%d ", rand_num);
   }
}

double randfrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

main() {
   int lower = 10, upper = 15, count = 15;
   srand(time(0)); //current time as seed of random number generator
   generate_random(lower, upper, count);
   printf("\n");
}
