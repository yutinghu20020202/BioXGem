#include<stdio.h>

float bmi(int h, int w){
    float heightInMeters = h / 100.0;
    return w / (heightInMeters * heightInMeters);
    /* return w/(h/100.0)*(h/100.0) */
}
int main () {
    int x=0, y=0;
    float bodyMassIndex=0;
    
    scanf("%d %d", &x, &y);
    if( x >= 100 && x <= 200){
        if(y >= 0 && y <= 100){
            bodyMassIndex = bmi(x,y);
            printf("%.6f\n", bodyMassIndex);
        }
    }else{
        return 0;
    }

    return 0;
}