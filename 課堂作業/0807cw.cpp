#include <iostream>
using namespace std;

int main(){
    string string1, string2;
    int times=0;
    cout << "Please input the string 1: ";
    cin >> string1;

    cout << "Please input the string 2: ";
    cin >> string2;

    int length1 = string1.length();
    int length2 = string2.length();


    // 一個一個字檢查
    for (int i = 0; i <= length1 - length2; i++) {
        bool found = true;
        for (int j = 0; j < length2; j++) {
            if (string1[i + j] != string2[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            times++;
        }
    }


    if(times >= 1){
        cout << "String 2 is a substring of string 1"<<endl;
        cout << "Repeat " << times << "times"<<endl;
    }else{
        cout <<"String 2 is not a substring of string 1"<< endl;
    }

    return 0;
}