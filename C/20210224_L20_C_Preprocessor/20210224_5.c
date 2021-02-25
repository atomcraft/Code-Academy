/*
Задача 3. Напишете макрос с един параметър, който печата
съобщение, само при дефиниран макрос DEBUG. Ако DEBUG не е
дефиниран, не печата нищо.
*/

#ifdef DEBUG
/* условна компилация */
#define DEBUGMSG(msg) \
{ printf("DEBUG: %s\n", (msg)); }
#else
#define DEBUGMSG(msg)
#endif 

int main(void){
    debugMsg();
    return 0;
}