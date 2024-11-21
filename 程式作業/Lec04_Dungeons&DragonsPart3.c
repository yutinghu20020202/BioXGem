#include <stdio.h>

int main () {
    int d1, d2, d3;
    scanf("%d %d %d", &d1, &d2, &d3);
    unsigned long long num1, num2, num3, mod, sum;
    num1 = 0x38E38E38E38E3800LLU;
    num2 = 0x2AAAAAAAAAAAAAAALLU;
    num3 = 0x1C71C71C71C71C71LLU ;
    mod = 0x7CE66C50E2840000LLU;
    sum = (d1*num1) % mod;
    sum = (sum + (d2*num2)% mod)%mod;
    sum = (sum + (d3*num3)% mod)%mod;
    
    printf("%llu\n", sum);//llu沒有負數，lld有

    return 0;
}