#include<stdio.h>

int main () {
    int bingoCard[8][8];
    int hostNum[64];
    int line=0;

    //scanf("%d", bingoCard);
    //scanf("%d", hostNum);要記得陣列不可以這樣讀取，只有一行陣列的時候才可以
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%d", &bingoCard[i][j]);
        }
    }
    
    for (int i = 0; i < 64; i++) {
        scanf("%d", &hostNum[i]);
    }
    
    for(int k=0; k<64; k++){
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(hostNum[k]==bingoCard[i][j]){
                    bingoCard[i][j] = -1;
                    break;
                }
            }
        }
    }

    for (int i=0; i<8; i++){//橫的
        int row = 1;
        for (int j=0; j<8; j++){
            if(bingoCard[i][j] != -1){
                row=0;
                break;
            }
        }
        if (row) line++;//注意if用法（考試小心）
    }
    for (int j=0; j<8; j++){//直的
        int col = 1;
        for (int i=0; i<8; i++){
            if (bingoCard[i][j] != -1){
                col = 0;
                break;
            }
        }
        if(col) line++;
    }
    int diag1 = 1;//左斜
    for (int i=0; i<8; i++){
        if(bingoCard[i][i] != -1){
            diag1 = 0;
            break;
        }
    }
    if(diag1) line++;
    int diag2 = 1;//右斜
    for(int i=0; i<8; i++){
        if(bingoCard[i][8-i-1] != -1){
            diag2 = 0;
            break;
        }
    }
    if(diag2) line++;

    
    printf("%d\n",line);

    
    return 0;
}