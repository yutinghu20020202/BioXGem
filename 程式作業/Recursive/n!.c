#include <stdio.h>

int fact(int n) {
    return n<=0 ? 1 : n * fact(n-1);
}

int main() {
    int n;
    printf("輸入 n 的值: ");
    scanf("%d", &n);  // 讀取 n 的值

    int result_recursive = sumr(n);  // 遞迴版本的結果

    printf("遞迴版本計算n!: %d\n", result_recursive);

    return 0;
}
