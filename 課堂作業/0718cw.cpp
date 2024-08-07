#include<iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    // 定義變數
	int i, j, temp, x, a, b, c, n;
    // 初始化數字陣列和答案陣列
	int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, ans[4];
	
    // 設定隨機數生成的種子，使用當前時間來確保每次運行時結果不同
	srand(time(NULL));
	
    // 將數字陣列隨機打亂
	for(i = 0; i < 10; i++){
		x = rand() % 10;  // 生成一個0到9之間的隨機數
		temp = num[i];    // 暫存num[i]的值
		num[i] = num[x];  // 將num[i]替換為隨機位置的數值
		num[x] = temp;    // 將隨機位置的數值設為暫存值
	}
	
    
	
	n = 0;  // 嘗試次數初始化為0
	while(a!=4){
		a = 0;  // 位置正確的數字個數
		b = 0;  // 數字正確但位置不對的個數
		n++;    // 增加嘗試次數
		
		cout << "Please input four digits (0~9):"; // 提示用戶輸入四個數字
		cin >> c;  // 獲取用戶輸入
		ans[0] = c/1000;
        ans[1] = (c/100)%10;
        ans[2] = (c/10)%10;
        ans[3] = c%10;
		
		// 比較隨機數字和用戶輸入的數字
		for(i = 0; i < 4; i++){
			for(j = 0; j < 4; j++){
				if(num[i] == ans[j] && i == j){  // 如果數字相同  // 並且位置也相同
						a++;  // 位置和數字都正確
				}else if(num[i] == ans[j] && i != j){
						b++;  // 數字正確但位置不對
				}
				
			}
		}
		
		// 如果位置和數字都正確的個數為4
		if(a == 4){
			cout << "You got it!! " << n << " times!!" << endl;  // 顯示成功信息和嘗試次數
			break;  // 結束遊戲
		}else{
			cout << "The result is " << a << "A " << b << "B " << endl;  // 顯示結果
		}
	}
}