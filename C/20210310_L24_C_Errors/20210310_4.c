/*
Задача 4.
Пренапишете Задача 2 от 05.03.2021г за Пощенските такси на дадена
куриерска фирма се определят според тежестта на пратките (с точност до цял грам) и обема,
както е показано в таблицата.
При влизане в някоя функция отваряте файл за писане и при успешно излизане от функцията
записвате във файла function_name() success . Това го правим за всички функции. Ако има
някаква грешка записваме грешката във файла и името на функцията.
*/


#include <stdio.h>
#include <stdlib.h>

void getShipmentInfo(double *priceShipment, double *priceTotalShipment);
void findBestShipmentOption(double *priceShipment, double *priceTotalShipment, int numShipment);

int main(void){
    
    double *priceShipment = 0;
    priceShipment = (double*)malloc(sizeof(double));

    double *priceTotalShipment = 0;
    priceTotalShipment = (double*)malloc(sizeof(double));
    getShipmentInfo(priceShipment, priceTotalShipment);
    free(priceShipment);
    free(priceTotalShipment);
    return 0;
}

void getShipmentInfo(double *priceShipment, double *priceTotalShipment){
    FILE *fp;
    fp = fopen("funct_errors.txt", "a+");
    if (NULL == fp){
        perror("Failed to open file\n");
        exit(1);
    }
    
    int weightShipment = 0;
    int volumeShipment = 0;
    int numShipment = 0;
    int totalWeight = 0;
    int totalVolume = 0;

    printf("How many shipments do you have?\n");
    scanf("%d", &numShipment);

    if (numShipment < 1){
        printf("You have decided not to send any shipment. Thank you for using our services.\n");
        fprintf(fp,"getShipmentInfo_Func: failed\n");
        fclose(fp);
        exit(1);
    }
    
    for (int i = 1; i <= numShipment; i++){

        printf("Weight of shipment (in grams): \n");
        scanf("%d", &weightShipment);

        totalWeight += weightShipment;

        if (weightShipment <= 20){
            *priceShipment += 0.46;
        }
        else if (weightShipment <= 50){
            *priceShipment += 0.69;
        }
        else if (weightShipment <= 100){
            *priceShipment += 1.02;
        }
        else if (weightShipment <= 200){
            *priceShipment += 1.75;
        }
        else if (weightShipment <= 350){
            *priceShipment += 2.13;
        }
        else if (weightShipment <= 500){
            *priceShipment += 2.44;
        }
        else if (weightShipment <= 1000){
            *priceShipment += 3.20;
        }
        else if (weightShipment <= 2000){
            *priceShipment += 4.27;
        }
        else if (weightShipment <= 3000){
            *priceShipment += 5.03;
        }

        printf("Volume of shipment (in cm): \n");
        scanf("%d", &volumeShipment);

        totalVolume += volumeShipment;

        if (volumeShipment < 10){
            *priceShipment += 0.01;
        }
        else if (volumeShipment < 50){
            *priceShipment += 0.11;
        }
        else if (volumeShipment < 100){
            *priceShipment += 0.22;
        }
        else if (volumeShipment < 150){
            *priceShipment += 0.33;
        }
        else if (volumeShipment < 250){
            *priceShipment += 0.56;
        }
        else if (volumeShipment < 400){
            *priceShipment += 1.50;
        }
        else if (volumeShipment < 500){
            *priceShipment += 3.11;
        }
        else if (volumeShipment < 600){
            *priceShipment += 4.89;
        }
        else if (volumeShipment > 600){
            *priceShipment += 5.79;
        }
    }

    if (totalWeight > 3000){
        printf("Your shipment is too big. Maximum allowed weight is 3000 grams.\n");
        fprintf(fp,"getShipmentInfo_Func: failed\n");
        fclose(fp);
        exit(1);
    }
    else {
        if (totalWeight <= 20){
            *priceTotalShipment += 0.46;
        }
        else if (totalWeight <= 50){
            *priceTotalShipment += 0.69;
        }
        else if (totalWeight <= 100){
            *priceTotalShipment += 1.02;
        }
        else if (totalWeight <= 200){
            *priceTotalShipment += 1.75;
        }
        else if (totalWeight <= 350){
            *priceTotalShipment += 2.13;
        }
        else if (totalWeight <= 500){
            *priceTotalShipment += 2.44;
        }
        else if (totalWeight <= 1000){
            *priceTotalShipment += 3.20;
        }
        else if (totalWeight <= 2000){
            *priceTotalShipment += 4.27;
        }
        else if (totalWeight <= 3000){
            *priceTotalShipment += 5.03;
        }

        if (totalVolume < 10){
            *priceTotalShipment += 0.01;
        }
        else if (totalVolume < 50){
            *priceTotalShipment += 0.11;
        }
        else if (totalVolume < 100){
            *priceTotalShipment += 0.22;
        }
        else if (totalVolume < 150){
            *priceTotalShipment += 0.33;
        }
        else if (totalVolume < 250){
            *priceTotalShipment += 0.56;
        }
        else if (totalVolume < 400){
            *priceTotalShipment += 1.50;
        }
        else if (totalVolume < 500){
            *priceTotalShipment += 3.11;
        }
        else if (totalVolume < 600){
            *priceTotalShipment += 4.89;
        }
        else if (totalVolume > 600){
            *priceTotalShipment += 5.79;
        }
    }
    findBestShipmentOption(priceShipment, priceTotalShipment, numShipment);
    fp = fopen("funct_errors.txt", "a+");
    if (NULL == fp){
        perror("Failed to open file\n");
        exit(1);
    }
    fprintf(fp,"\ngetShipmentInfo_Func: success\n");
    fclose(fp);
}

void findBestShipmentOption(double *priceShipment, double *priceTotalShipment, int numShipment){
    FILE *fp;
    fp = fopen("funct_errors.txt", "a+");
    if (NULL == fp){
        perror("\nFailed to open file\n");
        exit(1);
    }
    if (*priceTotalShipment <= *priceShipment){
        if (numShipment == 1){
            printf("Your shipment will cost %.2f leva.\n", *priceShipment);
            fprintf(fp,"\nfindBestShipmentOption_Func: success\n");
            fclose(fp);
        } else{
            printf("It is better to combine your shipments. In this case they will cost %.2f leva instead of %.2f leva.\n", *priceTotalShipment, *priceShipment);
            fprintf(fp,"\nfindBestShipmentOption_Func: success\n");
            fclose(fp);
        }       
    }
    else {
        printf("It is better to send your shipments separately. In this case they will cost %.2f leva instead of %.2f leva.\n", *priceShipment, *priceTotalShipment);
        fprintf(fp,"\nfindBestShipmentOption_Func: success\n");
        fclose(fp);
       
    }
}