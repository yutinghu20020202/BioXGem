#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partion (int arr[], int l, int r){
    int p = arr[r];
    int i = l - 1;
    for (int j=l; j<r; j++){
        if (arr[j] < p){
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    i++;
    swap (&arr[i], &arr[r]);
    return i;
}

void quick_main (int arr[], int l, int r){
    int n = sizeof(*arr) / sizeof(arr[0]);
    if (l<r){
        int p = partion (arr, l, r);
        quick_main (arr, l, p-1);
        quick_main (arr, p+1, r);
    }
}

int main(){
    int arr[8] = {5,4,3,9,1,8,7,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_main (arr, 0 , n-1);
    for (int i=0; i<n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}