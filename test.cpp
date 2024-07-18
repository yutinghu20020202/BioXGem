#include <iostream>
#include <cstdlib>  // 包含 <cstdlib> 庫
#include <ctime>    // 包含 <ctime> 庫，用於設置隨機數種子
using namespace std;

bool first = true;

int main() {
    srand(time(0));  // 使用當前時間設置隨機數種子

    int randomNumber[4]; //裡面裝四個東西
    for (int i = 0; i<4; i++){
        randomNumber[i] = rand()%10;
        cout << randomNumber[i];
    }
    cout << endl;



    int num[4], a=0, b=0, c=0;
    cout << "Please input four digits (0~9): ";
    cin >> c;
    while(a!=4){
        cout << "Please input four digits (0~9): ";
        cin >> c;
        num[0] = c/1000;
        num[1] = c/100-num[0]*10;
        num[2] = c/10-num[0]*100-num[1]*10;
        num[3] = c%10;

        for(int m=0; m<4; m++){
            if(num[m] == randomNumber[m]){;
            a++;
            }else{
                for(int n=0; n<4; m++){
                    if(num[m]==randomNumber[n] && num[m]!=randomNumber[m]){
                        b++;
                    }
                }
            }
            cout << "The result is " << a << "A" << b << "B" << endl;
            break;
        }
    }
        
    return 0;
}