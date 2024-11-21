#include <stdio.h>

int a_1, a_n, d;

int sum(int a_i){
    if (a_i > a_n) return 0;
    return a_i + sum (a_i + d);
}

int main()
{
    scanf("%d %d %d", &a_1, &a_n, &d);
    printf("%d", sum(a_1));
    return 0;
}