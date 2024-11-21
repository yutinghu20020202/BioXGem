#include<stdio.h>

int main () {
    int d1=0, d2=0, d3=0, d4=0, d5=0, d6=0;
    scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);

    int sum123 = d1 + d2 + d3;

    if (sum123 <= 10){
        printf("Player attacks: ");
        if(d4 == d5 && d5 == d6){
            printf("Critical Hit\n");
        }else if(d4 +d5 >= d6){
            printf("Normal Hit\n");
        }else{  
            printf("Miss\n");
        }
    }else{
        printf("Dragon attacks: ");
        if(d4 == d5 || d5 == d6 || d4 == d6){
            printf("Miss\n");
        }else if(d4 +d5 != d6){
            printf("Normal Hit\n");
        }else{
            printf("Critical Hit\n");
        }
    }

    return 0;
}