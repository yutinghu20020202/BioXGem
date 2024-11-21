#include <stdio.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void Perm (char list[], int i, int n){
    int j;
    if (i==n){
        for (j=1; j<=n; j++){
            printf("%c", list[j]);
        }
        printf("\n");
    }else{
        for (j=i; j<=n; j++){
            swap(&list[i], &list[j]);
            Perm(list, i+1, n);
            swap(&list[i], &list[j]);
        }
    }
}

int main(){
    int n;
    printf("Input n (<= 8): ");
    scanf("%d", &n);

    char list[n+1];  // 因為list從1開始，所以多分配一位
    printf("Input %d data: ", n);

    
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &list[i]);
    }

    // 呼叫 Perm 函數列印排列組合
    Perm(list, 1, n);
    return 0;
    
}
/*#include <stdio.h>

// 河內塔遞迴函數
void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        printf("Move sheet from %c to %c\n", A, C);
    } else {
        hanoi(n - 1, A, C, B);  // 將 n-1 個盤子從 A 經過 C 移動到 B
        hanoi(1, A, B, C);      // 將第 n 個盤子從 A 移動到 C
        hanoi(n - 1, B, A, C);  // 將 n-1 個盤子從 B 經過 A 移動到 C
    }
}

int main() {
    int n;
    printf("請輸入盤數: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');  // 從 A 移到 C，B 作為輔助
    return 0;
}*/
