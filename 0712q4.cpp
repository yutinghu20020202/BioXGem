#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int x ;
    int y ;
    double average;

    cout << "please input your score on test1...."<< endl;
    cin >> x;
    cout << "please input your score on test2...."<< endl;
    cin >> y;
    average = (x+y)/2.0;
    cout << fixed << setprecision(2);
    cout <<"Average score: "<< average << endl;
    
    
    if (average >= 90 && average <= 100) {
        cout << "A" << endl;
    } else if (average >=80 && average < 90) {
        cout << "B" << endl;
    } else if (average >=70 && average < 80) {
        cout << "C" << endl;
    } else if (average >=60 && average < 70) {
        cout << "D" << endl;
    } else {
        cout << "F" << endl;
    }

    return 0;
}