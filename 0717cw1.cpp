#include <iostream>
using namespace std;

// 函數定義
int add(int a, int b) {
    return a%b;
}

int main() {
    int num;

    cout << "Please enter a positive integer : ";
    cin >>num;

    int resultRemainder2 = add(num, 2); // 函數調用
    int resultRemainder3 = add(num, 3); // 函數調用
    int resultRemainder5 = add(num, 5); // 函數調用
    int resultRemainder7 = add(num, 7); // 函數調用
    

    if(resultRemainder2==0 || resultRemainder3==0 ){
        cout<<"It is not a prime number."<<endl;
    }else if( resultRemainder5==0 ||  resultRemainder7==0){
        cout<<"It is not a prime number."<<endl;
    }else{
        cout<<"It is a prime number."<<endl;
    }

    return 0;
}