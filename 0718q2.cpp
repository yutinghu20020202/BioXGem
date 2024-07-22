#include <iostream>
using namespace std;

int add (int a, int b){
    return (a+b)*(b-a+1)/2;
}

int main(){
    int num1, num2;
    char yesOrNo;

    while(true){

        cout << "Number 1: ";
        cin >> num1;
        cout << "Number 2: ";
        cin >> num2;

        if(num1 > num2){
            cout << "Error!! Number 1 > Number 2!!" << num1 << ">" << num2 << "!!"<<endl;
        }else if(num1 <= num2){
            int result = add(num1, num2);
            cout << "Sum = " << result << endl;
            cout << "Again(Y/N)??";
            cin >> yesOrNo;

            if(yesOrNo == 'N' || yesOrNo == 'n'){
                break;
            }

        }
        
    }

    return 0;
}