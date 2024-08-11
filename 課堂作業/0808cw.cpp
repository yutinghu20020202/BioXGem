#include <iostream>
using namespace std;

// 計算數列的總和
int calculateSequenceSum(int n) {
    int totalSum = 0;
    while (n != 1) {
        totalSum += n;
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    totalSum += 1;  // Add the final 1 in the sequence
    return totalSum;
}

int main() {
    int lowerBound, upperBound;
    
    // 輸入範圍
    cout << "Please input the LowerBound: ";
    cin >> lowerBound;
    cout << "Please input the UpperBound: ";
    cin >> upperBound;

    int maxSum = 0;
    int bestNumber = lowerBound;

    // 遍歷範圍內的每個數字
    for (int i = lowerBound; i <= upperBound; ++i) {
        int currentSum = calculateSequenceSum(i);
        if (currentSum > maxSum) {
            maxSum = currentSum;
            bestNumber = i;
        } else if (currentSum == maxSum && i < bestNumber) {
            bestNumber = i;
        }
    }

    // 輸出結果
    cout << "N=" << bestNumber << " Sum=" << maxSum << endl;

    return 0;
}