#include<stdio.h>

float triangle(int a=0){
    return 1.7320508*a*a/4;
}

int main () {
    int a=0;
    printf("Please input a length of the side of an equilateral triangle\n");
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