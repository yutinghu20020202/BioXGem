#include <stdio.h>

int main(void){
    long long x;
    scanf("%lld", &x);
    int a=0, b=0, y=0, z=0, final=0, ans[12];

    for(int i=0; i<12; i++){
        ans[i] = x%10;
        x = x/10;
    } 

    for(int j=0; j<12; j+=2){
        a = ans[j] +a ;
    }
    for(int j=1; j<12; j+=2){
        b = ans[j] +b ;
    }
    x = a*3 +b;
    y = x-1;
    z = y%10;
    final = 9-z;

    printf("%d\n", final);

    return 0;
}