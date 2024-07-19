#include <iostream> 

using namespace std;

// 定義一個函數，負責進行質因數分解
void primeFactorization(int n) {
    bool first = true;  // 標誌變量，用來追蹤是否是第一次輸出質因數

    // 找到2的所有因數
    while (n % 2 == 0) {  // 當 n 可以被2整除時執行
        if (first) {  // 如果是第一次輸出
            cout << 2;  // 輸出質因數2
            first = false;  // 如果沒設為false就不會出現下面else的部分ex:2222
        } else {  // 如果不是第一次輸出
            cout << " * " << 2;  // 輸出 * 2
        }
        n =n/ 2;  // 將 n 除以2
    }

    // 找到其餘奇數的因數
    for (int i = 3; i * i <= n; i += 2) {  // 從3開始，檢查每個奇數
        while (n % i == 0) {  // 當 n 可以被 i 整除時執行
            if (first) {  // 如果是第一次輸出
                cout << i;  // 輸出質因數 i
                first = false;  // 將標誌變量設為false
            } else {  // 如果不是第一次輸出
                cout << " * " << i;  // 輸出 * i
            }
            n /= i;  // 將 n 除以 i
        }
    }

    // 如果 n 是質數且大於2
    if (n > 2) {  // 檢查剩餘的 n 是否為質數
        if (first) {  // 如果是第一次輸出
            cout << n;  // 輸出質因數 n
        } else {  // 如果不是第一次輸出
            cout << " * " << n;  // 輸出 * n
        }
    }

    cout << endl;  // 輸出換行符號
}

// 主函數
int main() {
    int n; 
    cout << "Please input an integer: ";
    cin >> n;

    cout << n << " = ";  // 輸出 n =
    primeFactorization(n);  // 調用質因數分解函數

    return 0;
}