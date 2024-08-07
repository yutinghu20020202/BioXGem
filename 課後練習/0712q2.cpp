#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string name;
    string school;
    int a;
    int b;

    cout<<"Enter your name..."<<endl;
    cin>>name;
    cout<<"Enter your school..."<<endl;
    cin>>school;

    a = (30-(name.length()))/2;
    b = (30-(school.length()))/2;

    cout << "+-------------------------+" << endl;
    cout <<"|"<<setw(a)<< name <<setw(a)<<"|"<<endl;
    cout <<"|"<<setw(b)<< school<< setw(b)<<"|"<<endl;
    cout << "+-------------------------+" << endl;

    return 0;
}