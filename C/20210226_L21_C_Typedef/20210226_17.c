/*
Задача 17
 
Кое е по добре да купите: А броя дини от сорт мелон с диаметър Х сантиметра
и дебелина на кората D сантиметър или В броя дини с диаметър У сантиметра и
същата дебелина на кората D2? Създайте структура диня с два елемента -
диаметър и дебелина на кората заделете динамично с malloc() за масив от А на
брой дини от сорт мелон и попълнете данните за диаметър между 15 и 140 см с
функцията rand(), за всяка една диня в масива и дебелина на кората между 0.5 и
3.5 см. Създайте структура диня с два елемента - диаметър и дебелина на кората
заделете динамично с malloc() за масив от В на брой дини от сорт пъмпкин и
попълнете данните за диаметър между 35 и 95 см с функцията rand(), за всяка
една диня в масива и дебелина на кората между 0.3 и 0.9 см. Намерете средната
големина на динята и средната дебелина на кората и ги съпоставете с тези от
втория масив. Изведете на екрана купчината от кой сорт е по добре да се купи.
Изход:
По-добре е да се купят ... дини с диаметър ... сантиметра и кора с дебелина D
см вместо ... дини с диаметър ... см и дебелина на кората D1 см.
 
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
typedef struct {
    char *name;
    double diameter;
    double barkThikness;
} t_waterMelons;
 
void randFillMelonsArr(t_waterMelons *arr, int size);
void randFillPumpkinsArr(t_waterMelons *arr, int size);
void printWaterMelonsArr(t_waterMelons *arr, int size);
void findBestOption(t_waterMelons arrMelons[], int sizeMelons, t_waterMelons arrPumpkin[], int sizePumpkin);
t_waterMelons makeMelons();
t_waterMelons makePumpkin();
double findAverageDiameter(t_waterMelons arr[], int size);
double findAverageBark(t_waterMelons arr[], int size);
 
 
int main(void){
    srand(time(NULL));
    int num = 5;
    // t_waterMelons *melons = (t_waterMelons *) malloc(sizeof(t_waterMelons));
    // t_waterMelons *pumpkin = (t_waterMelons *) malloc(sizeof(t_waterMelons));
    // int sizeMelonsArr = sizeof(melons) / sizeof(melons[0]);
    // int sizePumpkinArr = sizeof(pumpkin) / sizeof(pumpkin[0]);
    t_waterMelons melons[5];
    t_waterMelons pumpkin[5];
    int sizeMelonsArr = 5;
    int sizePumpkinArr = 5;
    randFillMelonsArr(melons, sizeMelonsArr);
    randFillPumpkinsArr(pumpkin, sizePumpkinArr);
    printWaterMelonsArr(melons, sizeMelonsArr);
    printWaterMelonsArr(pumpkin, sizePumpkinArr);
    findBestOption(melons, sizeMelonsArr, pumpkin, sizePumpkinArr);
    // free(melons);
    // free(pumpkin);
    return 0;
 
 
}
 
void randFillMelonsArr(t_waterMelons *arr, int size){
    t_waterMelons melon;
    for (int i = 0; i < size; i++){
        // arr = (t_waterMelons *) realloc(arr, sizeof(t_waterMelons) * (i+1));
        melon = makeMelons();
        *(arr + i) =  melon;
    }
}
 
t_waterMelons makeMelons(){
    double max = 3.5;
    double min = 0.5;
    double range = (max - min); 
    double div = RAND_MAX / range;
    double melonBark =  min + (rand() / div);
    t_waterMelons melon = {
        .name = "Melon",
        .diameter = (rand()%(140 - 15 +1)) + 15,
        .barkThikness = melonBark
 
    };
    return melon;
}
 
void randFillPumpkinsArr(t_waterMelons *arr, int size){
    for (int i = 0; i < size; i++){
        // arr = (t_waterMelons *) realloc(arr, sizeof(t_waterMelons) * (i+1));
        arr[i] = makePumpkin();
    }
}
 
t_waterMelons makePumpkin(){
    double max = 0.9;
    double min = 0.3;
    double range = (max - min); 
    double div = RAND_MAX / range;
    double pumpkinBark = min + (rand() / div);
    t_waterMelons pumpkin = {
        .name = "Pumpkin",
        .diameter = (rand()%(95 - 35 +1)) + 35,
        .barkThikness = pumpkinBark
    };
    return pumpkin;
}
 
void findBestOption(t_waterMelons arrMelons[], int sizeMelons, t_waterMelons arrPumpkin[], int sizePumpkin){
    double avgMelonsDiam = findAverageDiameter(arrMelons, sizeMelons);
    double avgMelonsBark = findAverageBark(arrMelons, sizeMelons);
    double avgPumpkinDiam = findAverageDiameter(arrPumpkin, sizePumpkin);
    double avgPumpkinBark = findAverageBark(arrPumpkin, sizePumpkin);
    // printf("AvgMelonDiam: %lf\n", avgMelonsDiam);
    // printf("AvgMelonBark: %lf\n", avgMelonsBark);
    // printf("AvgPumpBark: %lf\n", avgPumpkinBark);
    // printf("AvgPumpDiam: %lf\n", avgPumpkinDiam);
 
    double melonNet = avgMelonsDiam - avgMelonsBark;
    double pumpkinNet = avgPumpkinDiam - avgPumpkinBark;
 
    if (melonNet > pumpkinNet){
        printf("\nIt is better to buy %d watermelons with diameter of %.2lf centimeters and bark thickness of %.2lf"
                " cm, instead of %d watermelons with diameter of %.2lf cm and bark thickness of %.2lf см.\n", sizeMelons, arrMelons->diameter, arrMelons->barkThikness,
                sizePumpkin, arrPumpkin->diameter, arrPumpkin->barkThikness);
    } else{
        printf("\nIt is better to buy %d watermelons with diameter of %.2lf centimeters and bark thickness of %.2lf"
                " cm, instead of %d watermelons with diameter of %.2lf cm and bark thickness of %.2lf см.\n", sizePumpkin, arrPumpkin->diameter, arrPumpkin->barkThikness,
                sizeMelons, arrMelons->diameter, arrMelons->barkThikness);
    }
 
}
 
double findAverageDiameter(t_waterMelons arr[], int size){
    double sumDiameter = 0.0;    
    for (int i = 0; i < size; i++){
        sumDiameter += arr->diameter;        
    }
    return (sumDiameter / size);
 
}
 
double findAverageBark(t_waterMelons arr[], int size){
    double sumBark = 0.0;    
    for (int i = 0; i < size; i++){
        sumBark += arr->barkThikness;        
    }
    return (sumBark / size);
 
}
 
void printWaterMelonsArr(t_waterMelons *arr, int size){
    for (int i = 0; i < size; i++){
        printf("Type: %s\n", ((arr + i)->name));
        printf("Diameter: %.2lf\n", ((arr + i)->diameter));
        printf("Bark thickness: %.2lf\n", ((arr + i)->barkThikness));
 
    }
 
}