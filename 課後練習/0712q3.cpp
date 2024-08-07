#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int year;
    int yearf;
    int yearf2;
    int yearo;

    printf("Please input a year....");
    scanf("%d", &year);
    yearf=year%400 ;
    yearf2=year%4 ;
    yearo=year%100 ;
    
if (yearf==0) {
    cout << year << " is a leap year." << endl;
}else if (yearf2==0 && yearo!=0) {
    cout << year << " is a leap year." << endl;
}else if (yearf2!=0) {
    cout << year << " is not a leap year." << endl;
}else if (yearo==0 && yearf!=0) {
    cout << year << " is not a leap year." << endl;
}else {
        cout << "F" << endl;
    }


    return 0;
}