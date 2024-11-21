#include<stdio.h>

int main () {
    long long num;
    scanf("%lld", &num);
    
    long long arr[num], prefitSum=0, i, j;
    for (i=0; i < num; i++){
        scanf("%lld", &arr[i]);
    }
    for (i=0; i<num; i++){
        prefitSum += arr[i];
        if ((prefitSum%arr[i]) == 0){
            printf("%lld %lld\n", prefitSum, arr[i]);
        }
    }
    
    
    return 0;
}