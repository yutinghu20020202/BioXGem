#include <iostream>
using namespace std;

int main() {
    int a ;
    int b ;
    int c ;
    int d ;

    cout<<"plaese enter your number...";
    cin >> a;

    if (a < 0) {
        cout << a << " is not a positive integer!!" << endl;
    }
    if (a >= 1 && a <= 9) {
        cout << a << " is a small integer." << endl;
    }
    if (a >= 10 && a <= 99) {
        b=a/10;
        c=a-10*b;
        cout << "The tens digit of " << a << " is "<< b << endl;
        cout << "The units digit of " << a <<" is "<< c << endl;
    }
    if (a >= 100) {
        cout << a << " is a large integer." << endl;
    }
    if (a >= 100 && a%5 == 0) {
        cout << a << " is divisible by 5." << endl;
    }
    if (a >= 100 && a%5 == 1) {
        d=a+5;
        cout << a << " + 5 = " << d << endl;
    }
    if (a >= 100 && a%5 == 2) {
        d=a-5;
        cout << a << " - 5 = " << d << endl;
    }
    if (a >= 100 && a%5 == 3) {
        d=a*5;
        cout << a << " * 5 = " << d << endl;
    }
    if (a >= 100 && a%5 == 4) {
        d= float(a/5);
        cout << a << " / 5 = " << d << endl;
    }
    return 0;   
}