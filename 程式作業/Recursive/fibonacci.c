#include <stdio.h>

int Fibo (int n){
    int F[n+1];
    F[0] = 0;
    F[1] = 1;
    if (n<2){
        return F[n];
    }else{
        int i;
        for (i=2; i<=n; i++){
            F[i] = F[i-1] + F[i-2];
        }
        return F[n];
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int total=0;
    for (int i=0; i<n; i++){
        total += Fibo(i);
    }
    printf("%d\n", total);
    printf("%d", Fibo(n));
    return 0;
}