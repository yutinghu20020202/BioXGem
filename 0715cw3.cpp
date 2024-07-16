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
        for (int j = 0; j < 2 * i +1; j++) {
            cout << (i+1) % 10;
        }
        cout << endl;
    }

    return 0;
}