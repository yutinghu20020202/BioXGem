#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 用於存儲排列組合結果
char permutations[1000][10];
int permIndex = 0;

// Swap 函數
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// 排列組合遞迴函數
void recursive(char arr[], int l) {
    int n = strlen(arr);
    if (l == n - 1) {
        strcpy(permutations[permIndex], arr);
        permIndex++;
        return;
    }
    for (int i = l; i < n; i++) {
        swap(&arr[l], &arr[i]);
        recursive(arr, l + 1);
        swap(&arr[l], &arr[i]);
    }
}

// 字典序排序用的比較函數
int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

// 九宮格轉換函數
void convertToT9(char *input, char *output) {
    typedef struct {
        int key_num;
        int count;
    } KeyPress;

    KeyPress keymap[26];
    char *key_letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int key_nums[] = {2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 8; i++) {
        char *letter = key_letters[i];
        int num = key_nums[i];
        for (int j = 0; letter[j] != '\0'; j++) {
            char character = letter[j];
            int index = character - 'a';
            keymap[index].key_num = num;
            keymap[index].count = j + 1;
        }
    }

    char *p = input;
    char *q = output;

    while (*p) {
        if (*p >= 'a' && *p <= 'z') {
            KeyPress kp = keymap[*p - 'a'];
            *q++ = '(';
            *q++ = kp.key_num + '0';
            *q++ = ')';
            *q++ = kp.count + '0';
        } else if (*p == '\n') {
            *q++ = '\n';
        }
        p++;
    }
    *q = '\0';
}

int main() {
    char input[10];
    scanf("%s", input);

    // 1. 產生排列組合
    recursive(input, 0);

    // 2. 排列結果按字典序排序
    qsort(permutations, permIndex, sizeof(permutations[0]), compare);

    // 3. 逐一轉換成九宮格格式並輸出
    for (int i = 0; i < permIndex; i++) {
        char t9Output[100];
        convertToT9(permutations[i], t9Output);
        printf("%s\n", t9Output);
    }

    return 0;
}
