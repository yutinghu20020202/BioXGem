#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Please input a number: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        // 使金字塔居中
        for (int j = 0; j < n - i-1; j++) {
            cout << " ";
        }
        // 數字
        for (int j = 0; j <= i; j++) {
            cout << j+1;
        }
        for (int j = i; j>=1; --j){
            cout << j;

        }
        cout << endl;
    }

    return 0;
}