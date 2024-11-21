#include <stdio.h>

int sumr(int n) {
    return (n <= 0) ? 0 : (n * n + sumr(n - 1)); 
}

int main() {
    int n;
    scanf("%d", &n);  // 讀取 n 的值

    int result_recursive = sumr(n);  // 遞迴版本的結果

    printf("遞迴版本計算平方和: %d\n", result_recursive);

    return 0;
}