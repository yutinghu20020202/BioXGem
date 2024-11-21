#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_LEN 1024
#define LINE_LEN 128

void convert(char *arr[], int count){//count是行
    typedef struct{
        int key_num;
        int count;
    }KeyPress;

    KeyPress keymap[26];

    char *key_letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int key_nums[] = {2, 3, 4, 5, 6, 7, 8, 9};

    for (int i=0; i<8; i++){
        char *letter = key_letters[i]; //指向key_letters[i]裡面的第一個
        int num = key_nums[i];
        for (int j=0; letter[j] != '\0' ; j++){
            char character = letter[j];
            int index = character - 'a';
            keymap[index].key_num = num;
            keymap[index].count = j+1;
        }
    }

    for (int i=0; i<count; i++){
        char *p = arr[i];
        char output[BUFFER_LEN];
        char *q = output;

        while(*p){
            if (*p>='a' && *p<='z'){
                KeyPress kp = keymap[*p-'a'];
                *q++ = '(';
                *q++ = kp.key_num + '0';
                *q++ = ')';
                *q++ = kp.count + '0';

            }else if (*p == ' '){
                *q++ = ' ';

            }else if (*p == '\n'){
                *q++ = '\n';
                *q++ = '\0'; //就算是換行符號後面也有句號

            }
            *p++;
        }
        *q = '\0';
        strncpy(arr[i], output, BUFFER_LEN-1);
    }
}

int main() {
  char line[BUFFER_LEN];
  char buffer[LINE_LEN][BUFFER_LEN];
  char *arr[LINE_LEN];

  int count = 0;
  while (fgets(line, BUFFER_LEN - 1, stdin) != NULL) {
    arr[count] = buffer[count];
    strncpy(buffer[count++], line, BUFFER_LEN - 1);
  }
  convert(arr, count);
  for (int i = 0; i < count; i++) {
    printf("%s", arr[i]);
  }
}