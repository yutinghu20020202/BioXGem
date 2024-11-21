#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int compare(const void *a, const void *b) {
    return strcmp ((char *)a , (char *)b);//str是收地址的，所以不要多加一個＊
}


char result[1000][10];
int resultIndex = 0; 

void recursive (char arr[], int l){
    
    int n = strlen(arr);
    if (l == n-1){
        strcpy(result[resultIndex], arr);
        resultIndex++;
        
        return;
    }
    for (int i=l; i<n; i++){
        swap(&arr[l], &arr[i]);
        recursive(arr, l+1);
        swap(&arr[l], &arr[i]);
    }
}

int main(){
    char input[10];
    scanf("%s", input);
    recursive (input, 0);
    qsort(result, resultIndex, sizeof(result[0]), compare);
    for (int i=0; i<resultIndex; i++){
        printf("%s\n", result[i]);
    }
    
    return 0;
}