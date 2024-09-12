#include <stdio.h>

float polynomial(float X){
    return 7*X*X*X*X-8*X*X*X-X*X+6*X-22;
}
int main(){
    float ans, enter;
    scanf("%f", &enter);
    ans = polynomial(enter);
    printf("%.1f\n", ans);
    return 0;
}
