#include<stdio.h>
#define w 0.9
#define u 0.1
#define b -51
#define U -0.98
#define B 153

void function (double X0, int days){
    //x當前的菜價格
    //y預測價格
    //hide
    double x=X0, y=0, h=0;
    for(int t=1; t<=days; t++){
        h = w * x + u * h +b;
        y = U * h + B;
        printf("%.1f ", y);
        x=y;
    }
}

int main () {
    double initialPrice=0;
    //scanf不可以用.數字
    scanf("%lf", &initialPrice);
    function(initialPrice, 5);

    return 0;
}