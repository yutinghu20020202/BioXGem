#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int x;
    int number;
    float total=0;
    double average;
    int max, min;

    
    cout <<"Please input the number of integers: ";
    cin>>x;
    
    max=0;
    min=number;

    for (int i = 1; i <= x; i++) {
        cout << "Integer #" << i << ":" << endl;
        cin >> number;
        
        total = number+total;

        
        if (number>=max) {
        max=number;
    }  else if (number< min) {
        min=number;
    }
    }
    average = total/x;
        cout << "The average is "<< fixed << setprecision(2) << average <<endl;
        cout<< "The maxmium is" << max <<endl;
        cout<< "The minmium is" << min <<endl;
    return 0;
}