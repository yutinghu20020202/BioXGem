#include <stdio.h>
int sumr(int n) {
    return (n <= 0) ? 0 : (n + sumr(n - 1));
}
int main() {
    int n;

    printf("請輸入一個數字: ");
    scanf("%d", &n);

    printf("1 到 %d 的和（遞迴版）: %d\n", n, sumr(n));

    printf("1 + 2 + 3 ... + %d 的和（遞迴版）: %d\n", n,sumr(n));

    return 0;
}