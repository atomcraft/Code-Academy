#include <stdio.h>

int main(){
    float fTomatoPrice = 4.5;
    float fFlourPrice = 1.8;
    float fYogurtPrice = 0.5;
    float fIcecreamConePrice = 0.6;
    float fCandyPrice = 1.5;
    float fLollypopPrice = 0.15;
    float fTomatoWeight = 0.0; 

    printf("Здравейте, добре дошли в нашия магазин! Днес предлагаме - пресни домати,"
           "брашно, кисело мляко, сладолед на фунийки и близалки.\n");
    printf("Колко килограма домати ще желаете? ");
    scanf("%f",&fTomatoWeight);
    float fTomatoTotal = fTomatoWeight*fTomatoPrice;
    printf("Заповядайте %f килограма домати." 
           "Сметката Ви е %0.2f лева.", fTomatoWeight, fTomatoTotal);
    return 0;
}