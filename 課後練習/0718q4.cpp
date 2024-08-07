#include <iostream>
using namespace std;

// 函數用來判斷一個數是否為醜數
bool isUgly(int num){
    if(num <= 0){
        return false;
    }while(num %2 == 0){
        num = num / 2;
    }while(num %3 == 0){
        num = num / 3;
    }while(num %5 == 0){
        num = num / 5;
    }return num == 1;
}

int main(){
    int N;
    cout << "Please input a number: ";
    cin >> N;

    int ugly[N];
    int count=1; //算第幾個醜數,因為後面已經設定ugly[0]=1所以初始值從1開始
    int candidate=1; //來選下一個醜數的候選人

    ugly[0] = 1;

    while(count<N){
        candidate++;
        if(isUgly(candidate)){
            ugly[count] = candidate;
            count++;
        }
    }

    for(int i = 0; i < N; i++){ //不能把i換成count是因為影響迴圈的計數
        cout << ugly[i] <<" ";
    }
    cout << endl;

    return 0;
}