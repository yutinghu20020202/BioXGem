#include <stdio.h>

int alternating_sumr(int n) {
    if (n <= 0) return 0;
    return alternating_sumr(n - 1) + (n & 1 ? n : -n);
}

int main() {
    int n;

    printf("請輸入一個數字: ");
    scanf("%d", &n);

    printf("1 到 %d 的和（遞迴版）: %d\n", n, alternating_sumr(n));

    printf("1 - 2 + 3 - 4 + ... + %d 的和: %d\n", n, alternating_sumr(n));

    return 0;
}
