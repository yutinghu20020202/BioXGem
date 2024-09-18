#include<stdio.h>

int main () {

    int i=0, arr[100];
    int max, min;
    int shortestDistance=0;

    while(1){
        scanf("%d", &arr[i]);
        if (arr[i]==-1){
            break;
        }
        i++;
    }
    
    max=arr[0];
    min=arr[0];
    for(int j=1; j<i; j++){
        if (arr[j]>=max) {
            max=arr[j];
        }else if (arr[j]< min) {
            min=arr[j];
        }
    }

    shortestDistance = max - min;

    printf("%d\n", shortestDistance);

    return 0;
}