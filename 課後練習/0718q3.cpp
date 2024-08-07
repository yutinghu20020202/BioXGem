#include <iostream>
using namespace std;

// 判斷是否為質數的函數
bool isPrime(int num){
    if(num <= 1){
        return false;
    }for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int N;
    cout << "Please input a number: ";
    cin >> N;

    const int maxSize = 1000;
    int primes[maxSize];
    int primeCount = 0;

    // 找出1到N之間的所有質數
    for(int i = 2; i <= N; i++){
        if(isPrime(i)){
            primes[primeCount++] = i;
        }
    }

    // 列出雙質數對並計算總數
    int twinCount = 0;

    for(int i = 0; i < primeCount - 1; i++ ){
        if(primes[i + 1] - primes[i] == 2){
            cout << "(" << primes[i] << ", " << primes[i+1] << ") ";
            twinCount++;
        }
    }
    cout << endl;
    cout << "Total is " << twinCount << endl;
    return 0;
}