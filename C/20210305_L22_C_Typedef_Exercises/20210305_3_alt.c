/*
Задача 3. С увеличаване на надморската височина температурата намалява с
около 0,5ºC на всеки 100м. Нека приемем, че атмосферното налягане е нормално.
Ако се знае температурата (ХºC) на хижа Вихрен (1950 метра над морското
равнище), да се изчисли каква е температурата на връх Вихрен (2918 метра над
морското равнище). Ако се знае температурата (УºC) на връх Вихрен, да се изчисли
каква е температурата на хижа Вихрен.
Изход 1:
Ако атмосферното налягане е нормално и температурата на хижа Вихрен (1950м
н.м.р.) е ... ºC , то температурата на връх Вихрен (2918м н.м.р.) е ... ºC.
Изход 2:
Ако атмосферното налягане е нормално и температурата на връх Вихрен (2918м
н.м.р.) е ... ºC , то температурата на хижа Вихрен (1950м н.м.р.) е ... ºC.
*/
#include <stdio.h>

#define HUNDREDMETERSTEMPCHANGE 0.5

void findTemp(float temp, float alt1, float alt2);

int main(void){
    float altitudeHutVihren = 1950.0;
    float altitudePeakVihren = 2918.0;
    float tempHutVihren = 15.0;
    findTemp(tempHutVihren, altitudeHutVihren, altitudePeakVihren);
    return 0;
}

void findTemp(float temp, float alt1, float alt2){
    float altDif = alt2 - alt1;
    int tempInc = (int)altDif / 100;
    printf("%d\n", tempInc);
    float newTemp = temp - (tempInc * HUNDREDMETERSTEMPCHANGE);
    printf("%f\n", newTemp);
    printf("On the basis of normal atmospheric preassure and temperature of %.2f on hut Vihren(1950m), the temp on peak Vihren(2918m) is %.2f\n", 
           temp, newTemp);

}