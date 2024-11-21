#include <stdio.h>

// 你已經有的 powerr 函數
int powerr(int base, int exp)
{
    if (exp < 0) return 0;
    return (exp == 0) ? 1 : (base * powerr(base, exp - 1));
}

int main() {
    int base, exponent;

    // 從使用者那裡讀取 base 和 exponent 的值
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);

    // 計算並顯示結果
    int result = powerr(base, exponent);
    printf("%d^%d = %d\n", base, exponent, result);

    return 0;
}