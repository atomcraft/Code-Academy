#include <stdio.h>

int main(){
    int iCaravans = 3;
    int iCampers = 3;
    float fCaravanPrice = 90.0;
    float fCamperPrice = 100.0;
    float dTotalCost = 0;
    printf("Dobre doshli v Karavani Kempeti pod naem\n");
    printf("Ako zelaete karavana natisnete 1\n");
    printf("Ako zelaete kemper natisnete 2\n");
    int rez = 0;
    scanf("%d", &rez);
    if (rez == 1) {
        printf("Cenata na edna karavana e %0.2f leva.\n", fCaravanPrice);
        printf("Jelaete li karavana? Otgovorete s y za da or n za ne.\n");
        char cChoiceCaravana;
        scanf("%s", &cChoiceCaravana);
        if (cChoiceCaravana == 'y'){
            printf("Imame 3 karavani, kolko shte jelaete? Otgovorete s 1 za edna, 2 za dve, 3 za tri.");
            int iCaravanNumber;
            scanf("%d", &iCaravanNumber);
            dTotalCost = dTotalCost + ((float)iCaravanNumber * fCaravanPrice);
            printf("\nDaljimata suma e: %.2f leva\n", dTotalCost);                     
        }
        else{
            printf("Da vi predloja kemper? Otgovorete s y za da or n za ne.\n");
            char cChoiceCamper;
            scanf("%s", &cChoiceCamper);
            if (cChoiceCamper == 'y'){
                printf("Cenata na edna kemper e %0.2f leva.\n", fCamperPrice);
                printf("Imame 3 kempera, kolko shte jelaete? Otgovorete s 1 za edna, 2 za dve, 3 za tri.");
                int iCamperNumber;
                scanf("%d", &iCamperNumber);
                dTotalCost = dTotalCost + ((float)iCamperNumber * fCamperPrice);
                printf("\nDaljimata suma e: %.2f leva\n", dTotalCost);                     
            }
            else{
                printf("Dovijdane.\n");
            }         
                       
        }                     
                
    }
    if (rez == 2) {
        printf("Cenata na edna kemper e %0.2f leva.\n", fCamperPrice);
        printf("Jelaete li kemper? Otgovorete s y za da or n za ne.\n");
        char cChoiceCamper;
        scanf("%s", &cChoiceCamper);
        if (cChoiceCamper == 'y'){
            printf("Imame 3 kempera, kolko shte jelaete? Otgovorete s 1 za edna, 2 za dve, 3 za tri.");
            int iCamperNumber;
            scanf("%d", &iCamperNumber);
            dTotalCost = dTotalCost + ((float)iCamperNumber * fCamperPrice);
            printf("\nDaljimata suma e: %.2f leva\n", dTotalCost);                     
        }
        else{
            printf("Da vi predloja karavana? Otgovorete s y za da or n za ne.\n");
            char cChoiceCaravana;
            scanf("%s", &cChoiceCaravana);
            if (cChoiceCaravana == 'y'){
                printf("Cenata na edna karavana e %0.2f leva.\n", fCaravanPrice);
                printf("Imame 3 karavani, kolko shte jelaete? Otgovorete s 1 za edna, 2 za dve, 3 za tri.");
                int iCaravanNumber;
                scanf("%d", &iCaravanNumber);
                dTotalCost = dTotalCost + ((float)iCaravanNumber * fCaravanPrice);
                printf("\nDaljimata suma e: %.2f leva\n", dTotalCost);                     
            }
            else{
                printf("Dovijdane.\n");
            }         

        }         
    }
    
    return 0;   
}