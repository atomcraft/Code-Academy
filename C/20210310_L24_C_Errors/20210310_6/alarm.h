#include <signal.h>
#include <setjmp.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int i = 0; int j = 0; long T0 = 0; /* globals */

jmp_buf Env;

void alarm_me(int d){
    long t1;
    long t1sec = time(0) - T0;
    printf("%d second%s has passed: j = %d. i =%d\n", t1sec,
          (t1sec == 1) ? "" : "s", j, i);
    if (t1sec >= 8){
        printf("Giving up\n");
        longjmp(Env, 1);
    }
    alarm(1);
    signal(SIGALRM, alarm_me);
}