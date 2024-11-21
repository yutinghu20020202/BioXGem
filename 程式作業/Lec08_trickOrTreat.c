#include<stdio.h>
#include<stdlib.h>

int array[1500];

int maxChandy( int size){
    if (size == 0) return 0;
    if (size == 1) return array[0];
    int dp[size];
    dp[0] = array[0];
    dp[1] = ((array[0] > array[1]) ? array[0] : array[1]);

    for(int i=2; i<size; i++){
        dp[i] = ((dp[i-2]+array[i] > dp[i-1]) ? dp[i-2]+array[i] : dp[i-1]);
    }

    return dp[size-1];
}


int main() {
    int size = 0;
    scanf("%d", &size);
    for(int i = 0 ; i < size; ++i) {
        scanf("%d", &array[i]);
    }
    printf("%d\n", maxChandy( size));
    return 0;
}