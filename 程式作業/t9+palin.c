#include <stdio.h>
#include <string.h>

// 九宮格轉換函數
void convertToT9(char *input, char *output) {
    typedef struct {
        int key_num;
        int count;
    } KeyPress;

    KeyPress keymap[26];
    char *key_letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int key_nums[] = {2, 3, 4, 5, 6, 7, 8, 9};

    // 構建九宮格按鍵對應表
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
        }
        p++;
    }
    *q = '\0';
}

// 判斷是否為迴文
int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // 不是迴文
        }
    }
    return 1; // 是迴文
}

int main() {
    char input[1024];
    char t9Output[2048]; // 九宮格輸出緩衝區
    scanf("%s", input);

    if (isPalindrome(input)) {
        convertToT9(input, t9Output);
        printf("%s\n", t9Output);
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}
