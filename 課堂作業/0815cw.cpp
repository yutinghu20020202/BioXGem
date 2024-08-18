#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
	srand(unsigned(time(NULL)));
	// 定義變數
		int x, sum=0, computerAdd=0, youAdd=0;
		x = rand() %31 +10; //從10開始往上隨機加數字最多加到31
		cout << "N=" << x << endl;
	
	while(true){
		
		int remainder = (x-sum)%4;
		if (remainder==1){
			computerAdd = rand() %3+1;
		}else if (remainder == 2) {
            computerAdd = 1; 
        } else if (remainder == 3) {
            computerAdd = 2;
        } else {
            computerAdd = 3;
	
		}
		cout << "Sum=" << sum << ", Computer add:" << computerAdd<< endl;
		sum += computerAdd;
		
		if (sum >= x){
			cout << "Sum=" << sum << ". You win" << endl;
			break;
		}
		
		
		cout << "Sum=" << sum << ", You add:";
		cin >> youAdd;
		
		// if (youAdd < 1 || youAdd > 3){
		// 	cout << "Please input number 1~3!"<< endl;
		// 	continue;
		// }
		sum += youAdd;
		if(sum >= x){
			cout << "Sum=" << sum << ". You lose!!" << endl;
			break;
		}

	}

	return 0;	
}