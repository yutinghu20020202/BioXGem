#include <iostream>
using namespace std;

// 函數定義
int add(int a, int b ) {
    while (b != 0) {
    int temp = b;
        b = a % b;
        a = temp;
    }
    return a ;
}

int main() {
    int num1, num2;

    cout << "Please input two intergers: ";
    cin >> num1 >> num2 ;

    // 確保num2永遠比較大
    if(num1>num2){
        int temp1 = num1;
        num1 = num2;
        num2 = temp1;
    }
    
    int result = add(num1 , num2);

    cout << "GCD is" << result << endl;
    return 0;
}