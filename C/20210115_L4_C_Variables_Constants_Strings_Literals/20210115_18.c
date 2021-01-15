#include <stdio.h>

int main(){
    int iCaravans = 3;
    int iCampers = 3;
    float fCaravanPrice = 90.0;
    float fCampersPrice = 100.0;
    double totalCost = 0;
    printf("Dobre doshli v Karavani Kempeti pod naem\n");
    printf("Ako zelaete karavana natisnete 1\n");
    printf("Ako zelaete kemper natisnete 2\n");
    int rez = 0;
    scanf("%d", &rez);
    if (rez == 1) {
        printf("Cenata na edna karavana e %0.2f leva.", fCaravanPrice);        
    }
    if (rez == 2) {
        printf("Cenata na edna kemper e %0.2f leva.", fCampersPrice);        
    }
    return 0;   
}