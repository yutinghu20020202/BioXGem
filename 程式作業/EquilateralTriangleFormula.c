#include<stdio.h>

float triangle(int a){
    return 1.7320508*a*a/4;
}

int main () {
    int a=0;
    
    scanf("%d", &a);
    if(a > 200 || a <= 0){
        return 0;
    }else{
        float A;
        A = triangle(a);
        printf("%.3f\n", A);
    }

    return 0;
}